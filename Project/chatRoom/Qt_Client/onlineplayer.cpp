#include "onlineplayer.h"
#include <QMediaPlayer>
#include <QMediaContent>
#include <QString>
#include <QFileInfo>
#include <QFile>
#include <QBuffer>

onlinePlayer::onlinePlayer(QObject *parent) : QObject(parent)
{
    qDebug() << " 在线音乐播放..." << endl;
    QMediaPlayer *player = new QMediaPlayer(this);

    /* 音乐路径 */
    QString musicPath1 = "D:\\QTtuna\\Codes\\musicPlayer\\music\\一直很安静.mp3";

    QString musicPath = "D:\\QTtuna\\Codes\\musicPlayer\\music\\【翠花不太脆】亲爱的少年.mp3";

    /* 检查音乐文件信息 */
    QFileInfo checkInfo(musicPath);
    if (checkInfo.exists() == false)
    {
        qDebug() << "文件不存在" << endl;
        return;
    }

    QFile musicFile(musicPath);

    if (musicFile.open(QIODevice::ReadOnly) == false)
    {
        qDebug() << "打开音乐源失败" << endl;
    }

    /* 音乐数据 */
    QByteArray audioData = musicFile.readAll();
    /* 关闭文件 */
    musicFile.close();

#if 1
    /* 创建一个QBuffer */
    QBuffer *buffer = new QBuffer(this);
    buffer->setData(audioData);

    if (buffer->open(QIODevice::ReadOnly) == false)
    {
        qDebug() << "无法打开缓冲区" << endl;
    }
#endif
    player->setMedia(QMediaContent(), buffer);

    /* 播放音乐 */
    player->play();
    /* 设置音量 */
//    player->setVolume(100);
}
