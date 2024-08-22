#include "clientsocket.h"
#include <QHostAddress>

ClientSocket::ClientSocket(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::connected, [this]()
    {
        /* 发射信号 */
        emit connectSuccessed();
    });

    connect(m_socket, &QTcpSocket::readyRead, this, &ClientSocket::handleReadSlot);
}

ClientSocket::~ClientSocket() = default;

/* 连接服务器 */
void ClientSocket::connnectToServer(const QString &ip, quint16 port)
{
    m_ip = ip;
    m_port = port;

    m_socket->connectToHost(QHostAddress(ip), port);
}

int ClientSocket::writeData(const QByteArray &data)
{
    qint64 len = data.size();

    /* 1.先发送数据包大小 */
    qint64 writtenBytes = m_socket->write(reinterpret_cast<const char*>(&len), sizeof(len));
    if (writtenBytes != sizeof(len))
    {
        return -1; // 写入失败
    }

    /* 2.再发送数据包内容 */
    writtenBytes = m_socket->write(data);
    if (writtenBytes != len)
    {
        perror("writen eroor");
        return -1;
    }

    return 0;   /* 写入成功 */
}

/* 处理读数据 */
void ClientSocket::handleReadSlot()
{
    m_buffer.append(m_socket->readAll());
    while(static_cast<size_t>(m_buffer.size()) >= sizeof (size_t))
    {
        size_t size;
        memcpy(&size, m_buffer.data(), sizeof (size_t));

        if (static_cast<size_t>(m_buffer.size()) < size + sizeof(size_t))
        {
            break;
        }

        /* 发送信号 */
        emit dataReceived(m_buffer.mid(static_cast<int>(sizeof(size_t)), static_cast<int>(size)));

        m_buffer.remove(0, static_cast<int>(sizeof(size_t) + size));
    }
//    qDebug() << "recv Data: " << m_socket->readAll();
}
