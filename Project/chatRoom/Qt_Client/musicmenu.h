#ifndef MUSICMENU_H
#define MUSICMENU_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVector>
#include <QMap>
#include <QTimer>       /* 定时器 */
#include <QCompleter>   /* 补全 */
#include <QStringList>  /* 歌曲清单 */
#include "clientsocket.h"
#include <QCloseEvent>
#include <QJsonDocument>
#include <QJsonObject>
#include <QBuffer>

namespace Ui {
class musicMenu;
}

enum PlayMode
{
    ORDER_MODE,
    CYCLE_MODE,
    RANDOM_MODE,
    PLAYMODE_MAX,
};

class musicMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit musicMenu(ClientSocket *clientInfo, QWidget *parent = nullptr);
    ~musicMenu() override;

protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void handlePrevSlot();
    void handlePlaySlot();
    void handleNextSlot();
    void handleSwitchSlot();
    void handleLiricSlot();
    void handleFavoriteSlot();
    void handleVolumnSlot();
    void handleTimeoutSlot();
    void handleMusicItemDoubleClickedSlot();

    /* 音乐状态改变 */
    void handleStateChangedSlot();
    /* 处理进度条长度 */
    void handleDurationSlot(qint64 duration);
    /* 处理进度条的进度 */
    void handlePositonSlot(qint64 position);

    /* 发送搜索歌曲信息给到服务器 */
    void handleSearchMucicSlot();
    /* 接受处理来自服务器的音乐流数据 */
    void handleOnlineDataSlot(const QByteArray &musicData);

public:
    void setAlbumPic(const QPixmap &pixmap);
    void setAlbumPic(const QString &picfilename);

     /* 加载本地音乐源路径 */
    void loadApponitMusicPath(const QString &filepath);
    /* 播放指定音乐 */
    void startApponitMusic();

    /* 加载歌词 */
    void loadAppointLyricMusicPath(const QString &filepath);

private:
    /* 设置初始的按钮图标 */
    void setInitButtonIcon();
    /* 解析时间 */
    int parseTime(const QString &time);

private:
    Ui::musicMenu *ui;

    QMediaPlayer *m_player;

    /* 判断是否播放 */
    bool m_isPlay;

    /* 当前播放模式 */
    int m_currentPlayMode;
    /* 切换模式的图标 */
    QVector<QString> m_modeIcons;

    /* 任务： */
    /* 1.维护上一首歌的行数，todo.. 验收项目考核之一，队列实现（记录10个） */
    /* 2.Qlist中可以双击某一首歌 */
    /* 3.歌曲的名字、歌曲信息在同一行列显示*/
    /* 4.点击歌词按钮，界面上显示list 歌词滚动*/
    int m_backupLastSongRow;
    /* 当前播放音乐在歌单里面是哪一行 */
    int m_currentSongRow;

    /* 本地音乐文件夹 */
    QString m_musicPath;
    /* 保留上一次程序退出的歌曲名 */
    QString m_lastSongName;

    /* 歌词信息<时间: 歌词> */
    QMap<quint32, QString> m_lyricInfo;

    /* 定时器, 检测position位置的歌词 */
    QTimer *m_lyricPositionTimer;

    /* 搜索框补全 */
    QCompleter *m_complete;

    /* 通信 */
    ClientSocket *m_clientInfo;
};

#endif // MUSICMENU_H
