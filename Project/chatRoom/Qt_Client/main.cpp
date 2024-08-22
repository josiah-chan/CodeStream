#include "mainwindow.h"
#include <QApplication>
#include "musicmenu.h"
#include "onlineplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

/* C/S架构 和 B/S浏览器架构 */

    MainWindow w;
    w.show();

    /* 在线音乐播放 */
//    onlinePlayer w;

    return a.exec();
}
