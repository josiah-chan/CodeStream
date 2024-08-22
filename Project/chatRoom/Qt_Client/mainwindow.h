#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "clientsocket.h"
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    /* 处理注册信息的槽函数 */
    void handleRegisSlot();
    /* 处理登录信息的槽函数 */
    void handleLoginSlot();
    /* 处理连接成功的槽函数 */
    void handleConnectedSlot();
    /* 处理完整信号的槽 */
    void handleDataSlot(const QByteArray &data);

private:
    Ui::MainWindow *ui;

    /* 网络通信 */
    ClientSocket *m_client;
};

#endif // MAINWINDOW_H
