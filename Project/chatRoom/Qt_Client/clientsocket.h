#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QByteArray>

/* 枚举 - 功能操作码 - 与客户端匹配 */
enum FunctionOption
{
    FUNC_REGISTER = 1,  /* 注册 */
    FUNC_LOGIN,         /* 登录 */
    FUNC_EXIT,          /* 退出 */
    FUNC_ADD_FRIEND,    /* 添加好友 */
    FUNC_DEL_FRIEND,    /* 删除好友 */
    FUNC_NEW_GROUP,     /* 建群 */
    FUNC_EXIT_GROUP,    /* 退群 */
    FUNC_SEARCH_MUSIC,  /* 搜索服务器音乐 */
    FUNC_ONLINE_MUSIC   /* 处理在线音乐 */
};

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = nullptr);
    /* 析构函数 */
    ~ClientSocket();

    /* 连接服务器 */
    void connnectToServer(const QString &ip, quint16 port);
    int writeData(const QByteArray &data);

signals:
    void connectSuccessed();
    void dataReceived(const QByteArray &data);

public slots:
    void handleReadSlot();

private:
    QTcpSocket *m_socket;
    QString m_ip;
    quint16 m_port;

    /* 数据缓冲区 */
    QByteArray m_buffer;
};

#endif // CLIENTSOCKET_H
