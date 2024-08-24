#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QIcon>
#include <QPushButton>
#include <QDebug>
#include <QPicture>
#include <QPixmap>
#include <QFileDialog>      /* 文件对话框 */
#include "customlabel.h"
#include <QHostAddress>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QBuffer>
#include "musicmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_client(new ClientSocket(this))
{
    ui->setupUi(this);

    /* 设置标题 */
    setWindowTitle("MusicPlayer");

    /* 设置窗口图标 */
    QIcon picIcon(":/image/basketball.png");
    setWindowIcon(picIcon);

    /* 初始化设置头像 */
    ui->headImg->setHeadImage(":/image/8.png");

    /* 信号和槽 */
    connect(ui->RegisterBtn, &QPushButton::clicked, this, &MainWindow::handleRegisSlot);

    /* 登录信号和槽 */
    connect(ui->LoginBtn, &QPushButton::clicked, this, &MainWindow::handleLoginSlot);

   /* 连接服务器 */
    m_client->connnectToServer("192.168.181.148", 8080);
    /* 信号与槽，判断有没有连接成功 */
    connect(m_client, &ClientSocket::connectSuccessed, this, &MainWindow::handleConnectedSlot);
    connect(m_client, &ClientSocket::dataReceived, this, &MainWindow::handleDataSlot);
}

/* 处理信号的槽函数 */
void MainWindow::handleRegisSlot()
{
    qDebug() << "注册按钮被点击了..." << endl;

    QString username = ui->accountInfo->text();
    QString passwd = ui->passwdInfo->text();

    qDebug() << "username: " << username << "  passwd: " << passwd  << endl;

    /* json: key必须是字符串、value不约束数据类型 */
    /* 创建json对象 */
    QJsonObject jsonobj;

    /* 设置key, value属性 */
    jsonobj["type"] = FUNC_REGISTER;
    jsonobj["username"] = username;
    jsonobj["passwd"] = passwd;

    /* 创建 Document 对象 */
    QJsonDocument document(jsonobj);
    m_client->writeData(document.toJson());
}

/* 处理登录信息的槽函数 */
void MainWindow::handleLoginSlot()
{
    qDebug() << "登录按钮...";

    QString username = ui->accountInfo->text();
    QString passwd = ui->passwdInfo->text();

    qDebug() << "username: " << username << " passwd: " << passwd  << endl;

    /* json: key必须是字符串、value不约束数据类型 */
    /* 创建json对象 */
    QJsonObject jsonobj;

    /* 设置key, value属性 */
    jsonobj["type"] = FUNC_LOGIN;
    jsonobj["username"] = username;
    jsonobj["passwd"] = passwd;

    /* 创建 Document 对象 */
    QJsonDocument document(jsonobj);
    m_client->writeData(document.toJson());
}

void MainWindow::handleConnectedSlot()
{
    qDebug() << "连接服务器成功...";
}

/* 处理完成数据的槽函数 */
void MainWindow::handleDataSlot(const QByteArray &data)
{
    qDebug() << "文件：(" << __FILE__ << ") data: " << data;
    /* 1.解析json字符串 */
    QJsonDocument document = QJsonDocument::fromJson(data);

    if (document.isObject() == false)
    {
        qDebug() << "document is not Object! File: (" << __FILE__ << ")";
        return;
    }
    /* 2.将document对象转成json对象 */
    QJsonObject jsonObj = document.object();

    /* 3.取值 */
    int type = jsonObj["type"].toInt();
    QString result = jsonObj["result"].toString();
    if (type == FUNC_REGISTER)
    {
        /* todo... 这里改为 REGISTER */
        if (result == "success")
        {
            QMessageBox::information(this, "注册", "注册成功");
        }
        else
        {
            QString reason = jsonObj["reason"].toString();
            QMessageBox::information(this, "注册", reason);
        }
    }
    else if (type == FUNC_LOGIN)
    {
        /* todo... 改为LOGIN */
        if (result == "success")
        {
            QMessageBox::information(this, "登录", "登录成功");

            /* 登录成功之后，跳转到音乐播放器的界面 */
            musicMenu *musicInterface = new musicMenu(m_client);
            musicInterface->show();
            disconnect(m_client, &ClientSocket::dataReceived, this, &MainWindow::handleDataSlot);
            /* 隐藏当前窗口 */
            this->hide();
        }
        else
        {
            QString reason = jsonObj["reason"].toString();
            QMessageBox::information(this, "登录", reason);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
