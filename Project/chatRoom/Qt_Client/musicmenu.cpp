#include "musicmenu.h"
#include "ui_musicmenu.h"
#include <QIcon>
#include <QPixmap>
#include <QPushButton>
#include <QDebug>
#include <QUrl>
#include <QDir>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileInfoList>
#include <QSlider>
#include <QFile>
#include <QTextCodec>

musicMenu::musicMenu(ClientSocket* clientInfo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicMenu),
    m_player(new QMediaPlayer(this)),
    m_isPlay(false),
    m_currentPlayMode(ORDER_MODE),
    m_backupLastSongRow(0),
    m_currentSongRow(0),
    m_lyricPositionTimer(new QTimer(this)),
    m_clientInfo(clientInfo)
{
    ui->setupUi(this);

    /* 设置专辑封面图 */
    setAlbumPic(":/image/8.png");

    /* 设置初始化的按钮图标 */
    setInitButtonIcon();

    m_musicPath = "D:\\QTtuna\\Codes\\musicPlayer\\music\\";
    loadApponitMusicPath("D:\\QTtuna\\Codes\\musicPlayer\\music\\");

    connect(ui->prevBtn, &QPushButton::clicked, this, &musicMenu::handlePrevSlot);
    connect(ui->playBtn, &QPushButton::clicked, this, &musicMenu::handlePlaySlot);
    connect(ui->nextBtn, &QPushButton::clicked, this, &musicMenu::handleNextSlot);

    connect(ui->switchModBtn, &QPushButton::clicked, this, &musicMenu::handleSwitchSlot);
    connect(ui->liricBtn, &QPushButton::clicked, this, &musicMenu::handleLiricSlot);
    connect(ui->favoriteBtn, &QPushButton::clicked, this, &musicMenu::handleFavoriteSlot);
    connect(ui->volumeBtn, &QPushButton::clicked, this, &musicMenu::handleVolumnSlot);

    /* 在线音乐 - 信号和槽 */
    connect(ui->onlinePlayBtn, &QPushButton::clicked, this, &musicMenu::handleSearchMucicSlot);
    connect(m_clientInfo, &ClientSocket::dataReceived, this, &musicMenu::handleOnlineDataSlot);

    /* 加载音乐, 软件打开时能够记录上次音乐播放的位置及记录 */
    /* 初始化加载第一首歌 */
    ui->musicList->setCurrentRow(m_currentSongRow);
    m_lastSongName = "if-西野カナ-if";

    m_player->setMedia(QUrl::fromLocalFile(m_musicPath + m_lastSongName + ".mp3"));
    loadAppointLyricMusicPath(m_musicPath + m_lastSongName + ".lrc");

    /* 信号和槽 */
    connect(m_player, &QMediaPlayer::durationChanged, this, &musicMenu::handleDurationSlot);
    connect(m_player, &QMediaPlayer::positionChanged, this, &musicMenu::handlePositonSlot);
    connect(ui->processBar, &QSlider::sliderMoved, m_player, &QMediaPlayer::setPosition);
    connect(m_player, &QMediaPlayer::stateChanged, this, &musicMenu::handleStateChangedSlot);

    /* 定时器 */
    m_lyricPositionTimer->setInterval(1000);
    connect(m_lyricPositionTimer, &QTimer::timeout, this, &musicMenu::handleTimeoutSlot);

    /* 设置占位符 */
    ui->searchMusic->setPlaceholderText("搜索音乐");

    QStringList songList;

    songList.push_back("一直很安静");
    songList.push_back("爱情买卖");
    songList.push_back("无名之辈");
    songList.push_back("江南");
    songList.push_back("缝纫机乐队");
    songList.push_back("爱就一个字");
    songList.push_back("无名的人");
    songList.push_back("虹之间");

    m_complete = new QCompleter(songList, this);
    /* 弹出匹配项 */
    m_complete->setCompletionMode(QCompleter::PopupCompletion);
    /* 将补全器设置到搜索框 */
    ui->searchMusic->setCompleter(m_complete);
}

void musicMenu::setAlbumPic(const QPixmap &pixmap)
{
    ui->albumLabel->setPixmap(pixmap.scaled(ui->albumLabel->width(),ui->albumLabel->height(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void musicMenu::setAlbumPic(const QString &picfilename)
{
    QPixmap albumLabelPixmap(picfilename);
    setAlbumPic(albumLabelPixmap);
}

/* 加载本地音乐源路径 */
void musicMenu::loadApponitMusicPath(const QString &filepath)
{
    QDir dir(filepath);
    if (dir.exists() == false)
    {
        QMessageBox::warning(this, "打开文件夹", "文件夹不存在");
        return;
    }

    QFileInfoList fileInfo = dir.entryInfoList(QDir::Files);
    /* 循环查找 */
    for (const QFileInfo &info : fileInfo)
    {
        if (info.suffix() == "mp3")     //过滤器
        {
            qDebug() << "fileName: " << info.baseName() << endl;
            ui->musicList->addItem(info.baseName());
        }
    }
}

/* 播放指定路径音乐 */
void musicMenu::startApponitMusic()
{
    QString songName = ui->musicList->currentItem()->text();

    QString adsPathname = m_musicPath + songName + ".mp3";

    /* 播放切换动作后的歌曲 */
    m_player->setMedia(QUrl::fromLocalFile(adsPathname));
    /* 加载歌词 */
    loadAppointLyricMusicPath(m_musicPath + songName + ".lrc");
    /* 处理歌曲播放状态 */
    handlePlaySlot();
}

/* 打开歌词文件 */
void musicMenu::loadAppointLyricMusicPath(const QString &filepath)
{
    /* 清空旧歌曲 */
    m_lyricInfo.clear();
    QFile file(filepath);

    if (file.open(QIODevice::ReadOnly) == false)
    {
        QMessageBox::warning(this, "歌词文件", "歌词文件不存在");
        return;
    }

    /* 尝试自动检测文件编码并转换 */
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString content = in.readAll();

    /* 检查是否成功解码（如果有乱码，通常会包含替换字符） */
    if (content.contains(QChar(0xFFFD)))
    {
        /* UTF-8 解码失败，尝试 ANSI (Windows-1252 或 GB18030) */
        file.seek(0);  /* 重置文件指针 */
//        QTextCodec *codec = QTextCodec::codecForName("Windows-1252");  /* 英文 ANSI */
        QTextCodec *codec = QTextCodec::codecForName("GB18030");    /* 中文 ANSI */
        in.setCodec(codec);
        content = in.readAll();
    }

    QStringList lines = content.split('\n');
#if 0
    while (!in.atEnd())
    {
        QString lineData = in.readLine();
        qDebug() << "lineDate: " << lineData;

        QStringList listInfo = lineData.split("]");

        /* 将字符串时间转换成毫秒 */
        int lyricTime = parseTime(listInfo[0].split("[")[1]);   /* 转换后的字符串类似： "[03:39.56" */
        QString lyric = listInfo[1];    /* 转换后的字符串类似： "跟夜风一样的声音" */

        /* 插入哈希表 */
        m_lyricInfo[static_cast<const unsigned int>(lyricTime)] = lyric;

        qDebug() << "listInfo[0]" << listInfo[0];
        qDebug() << "listInfo[1]" << listInfo[1];
    }
#else
    for (const QString &lineDate : lines)
    {
        QStringList listInfo = lineDate.split("]");

        /* 处理不符合预期格式的数据 */
        if (listInfo.size() < 2)
        {
            continue;
        }

        /* 将字符串时间转换成毫秒 */
        int lyricTime = parseTime(listInfo[0].split("[")[1]);    /* 转换后的字符串类似： "[03:39.56" */
        QString lyric = listInfo[1].trimmed();   /* 转换后的字符串类似： "跟夜风一样的声音" */

        m_lyricInfo[static_cast<const unsigned int>(lyricTime)] = lyric;
    }

#endif
    file.close();
}

/* 设置初始的按钮图标 */
void musicMenu::setInitButtonIcon()
{
    /* 设置图标 */
    QIcon prevBtnIcon(":/icon/prev.png");
    ui->prevBtn->setIcon(prevBtnIcon);
    /* 将图标的大小适配按钮本身大小 */
    ui->prevBtn->setIconSize(QSize(30, 30));
    /* 样式表 */
    ui->prevBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon playBtnIcon(":/icon/play.png");
    ui->playBtn->setIcon(playBtnIcon);
    ui->playBtn->setIconSize(QSize(30, 30));
    ui->playBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon nextBtnIcon(":/icon/next.png");
    ui->nextBtn->setIcon(nextBtnIcon);
    ui->nextBtn->setIconSize(QSize(30, 30));
    ui->nextBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon liricBtnIcon(":/icon/liric.png");
    ui->liricBtn->setIcon(liricBtnIcon);
    ui->liricBtn->setIconSize(QSize(30, 30));
    ui->liricBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon favoriteBtnIcon(":/icon/favorite_2.png");
    ui->favoriteBtn->setIcon(favoriteBtnIcon);
    ui->favoriteBtn->setIconSize(QSize(30, 30));
    ui->favoriteBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon volumnBtnIcon(":/icon/volumn.png");
    ui->volumeBtn->setIcon(volumnBtnIcon);
    ui->volumeBtn->setIconSize(QSize(30, 30));
    ui->volumeBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    QIcon switchBtnIcon(":/icon/switch.png");
    ui->switchModBtn->setIcon(switchBtnIcon);
    ui->switchModBtn->setIconSize(QSize(30, 30));
    ui->switchModBtn->setStyleSheet("QPushButton {background-color: rgb(255, 255, 255, 0); }");

    /* 更改图标 */
    m_modeIcons.push_back(":/icon/switch.png");
    m_modeIcons.push_back(":/icon/singelSong.png");
    m_modeIcons.push_back(":/icon/random.png");
}

/* 解析时间 */
int musicMenu::parseTime(const QString &time)
{
    int minutes = static_cast<int>(time.split(":")[0].toUInt());

    int seconds = static_cast<int>(time.split(":")[1].split(".")[0].toUInt());

    int mileseconds = static_cast<int>(time.split(".")[1].toUInt());

    int totalMiles = minutes * 60 * 1000 + seconds * 1000 + mileseconds;
    return totalMiles;
}

musicMenu::~musicMenu()
{
    delete ui;
    delete m_player;
}

/* 函数实现，关闭事件 */
void musicMenu::closeEvent(QCloseEvent *event)
{
    QMessageBox::information(this, "关闭", "关闭窗口");
    /* todo... 记录数据 */
}

void musicMenu::handlePrevSlot()
{
    /* 播放列表当前行 */
    int currentRow = ui->musicList->currentRow();
    int rowCount = ui->musicList->count();

    int prevRow = 0;
    if (m_currentPlayMode == ORDER_MODE)        /* 顺序播放 */
    {
        prevRow = (currentRow - 1 + rowCount) % (rowCount);
    }
    else if (m_currentPlayMode == CYCLE_MODE)   /* 单曲播放 */
    {
        prevRow = currentRow;
    }
    else if (m_currentPlayMode == RANDOM_MODE)  /* 随机播放 */
    {
//        do
//        {
//            prevRow = qrand() % (rowCount);
//        }while(prevRow == currentRow);
        prevRow = m_backupLastSongRow;
    }

    ui->musicList->setCurrentRow(prevRow);

#if 0
    QString songName = ui->musicList->currentItem()->text();
    QString songPath = QString("D:\\QTtuna\\Codes\\musicPlayer\\music\\%1.mp3").arg(songName);

    qDebug() << "prev songName: " << songName << endl;
    qDebug() << "prev songPath: " << songPath << endl;

    m_player->setMedia(QUrl::fromLocalFile(songPath));
    m_player->play();

    ui->playBtn->setIcon(QIcon(":/icon/pause.png")); // 切换播放按钮图标
#else
    startApponitMusic();

#endif
}

void musicMenu::handlePlaySlot()
{
    /* 如果歌曲没有播放 */
#if 0
    if(m_isPlay == false)
    {
        /* 播放音乐 */
        m_player->play();

        ui->playBtn->setIcon(QIcon(":/icon/pause.png"));
        m_isPlay = true;
    }
    else
    {
        /* 暂停音乐 */
        m_player->pause();

        ui->playBtn->setIcon(QIcon(":/icon/play.png"));
        m_isPlay = false;
    }
#else
    /* 方案2 */
    if (m_player->state() == QMediaPlayer::PlayingState)
    {
        /* 暂停播放 */
        m_player->pause();
        qDebug() << "pause";
        ui->playBtn->setIcon(QIcon(":/icon/play.png"));
        /* 停止定时器 */
        m_lyricPositionTimer->stop();
    }
    else if(m_player->state() == QMediaPlayer::PausedState || m_player->state() == QMediaPlayer::StoppedState)
    {
        /* 播放音乐 */
        m_player->play();
        qDebug() << "play";
        ui->playBtn->setIcon(QIcon(":/icon/pause.png"));
        /* 启动定时器 */
        m_lyricPositionTimer->start();
    }
#endif
}

void musicMenu::handleNextSlot()
{
    /* 播放列表当前行 */
    int currentRow = ui->musicList->currentRow();
    m_backupLastSongRow = currentRow;
    int rowCount = ui->musicList->count();

    int nextRow = 0;
    if (m_currentPlayMode == ORDER_MODE)        /* 顺序播放 */
    {
        nextRow = (currentRow + 1) % (rowCount);
    }
    else if (m_currentPlayMode == CYCLE_MODE)   /* 单曲播放 */
    {
        nextRow = currentRow;
    }
    else if (m_currentPlayMode == RANDOM_MODE)  /* 随机播放 */
    {
        do
        {
            nextRow = qrand() % (rowCount);
        }while(nextRow == currentRow);
    }

    ui->musicList->setCurrentRow(nextRow);
    /* 播放指定音乐 */
    startApponitMusic();
}

void musicMenu::handleSwitchSlot()
{
    qDebug() << "handleSwitchSlot";

    m_currentPlayMode = (m_currentPlayMode + 1) % PLAYMODE_MAX;
    ui->switchModBtn->setIcon(QIcon(m_modeIcons[m_currentPlayMode]));
}

void musicMenu::handleLiricSlot()
{
    qDebug() << "liric";
}

void musicMenu::handleFavoriteSlot()
{
    qDebug() << "favorite";
}

void musicMenu::handleVolumnSlot()
{
    qDebug() << "volumn";
}

/* 处理定时器超时 */
void musicMenu::handleTimeoutSlot()
{
    /* 处理当前歌曲的位置 */
    int currentPots = static_cast<int>(m_player->position());

//    qDebug() << "currentPots: " << currentPots;

    for (auto iter = m_lyricInfo.begin(); iter != m_lyricInfo.end(); iter++)
    {
        int prevPos = static_cast<int>(iter.key());
        int nextPos = static_cast<int>((iter + 1).key());

        if (prevPos < currentPots && currentPots < nextPos)
        {
            ui->lyricLabel->setText(iter.value());  /* 显示歌词 */
            break;
        }
    }
}

void musicMenu::handleSearchMucicSlot()
{
    qDebug() << "开始搜索在线音乐...";

    QString musicName = "一直很安静";

    qDebug() << "musicName: " << musicName << endl;

    /* json: key必须是字符串、value不约束数据类型 */
    /* 创建json对象 */
    QJsonObject jsonObj;

    /* 设置key, value属性 */
    jsonObj["type"] = FUNC_SEARCH_MUSIC;
    jsonObj["musicName"] = musicName;

    /* 创建 Document 对象 */
    QJsonDocument document(jsonObj);
    qDebug() << "document.toJson(): " << document.toJson() << endl;

    m_clientInfo->writeData(document.toJson());
}

void musicMenu::handleOnlineDataSlot(const QByteArray &data)
{
    qDebug() << "file: " << __FILE__ << "handleOnlineDataSlot" << "\tLine:" << __LINE__ << endl;

    /* 1.解析json字符串 */
    QJsonDocument document = QJsonDocument::fromJson(data);
    if (document.isObject() == false)
    {
        qDebug() << "document parse is not Object." << endl;
        return;
    }

    /* 2.讲document对象转成json对象 */
    QJsonObject jsonObj = document.object();

    /* 3.取值 */
    int type = jsonObj["type"].toInt();

    if (type == FUNC_ONLINE_MUSIC)
    {
        QString musicname = jsonObj["musicName"].toString();
        QString base64Data = jsonObj["musicContent"].toString();
        qDebug() << "size of Base64 data: " << base64Data << endl;

        /* Base解码 */
        QByteArray audioData = QByteArray::fromBase64(base64Data.toUtf8());

        /* 创建一个QBuffer缓冲区 */
        QBuffer *buffer = new QBuffer(this);
        buffer->setData(audioData);

        if (buffer->open(QIODevice::ReadOnly) == false)
        {
            qDebug() << "无法打开缓冲区" << endl;
            delete buffer;
            return;
        }

        m_player->setMedia(QMediaContent(), buffer);

        /* 播放音乐 */
        m_player->play();
    }
}

void musicMenu::handleStateChangedSlot()
{
    qDebug() << "state: " << m_player->state();
    qDebug() << "Media status:" << m_player->mediaStatus();

    if (m_player->state() == QMediaPlayer::StoppedState && m_player->position() != 0)
    {
        /* 播放下一首 */
        handleNextSlot();
    }
}

void musicMenu::handleDurationSlot(qint64 duration)
{
    int minutes = static_cast<int>(duration / 60000);  // 将毫秒转换为分钟
    int seconds = static_cast<int>((duration % 60000) / 1000);  // 将剩余的毫秒转换为秒

    QString formatStr = "%1:%2";
    QString totalTime = formatStr.arg(minutes).arg(seconds);
    ui->totalTime->setText(totalTime);

    /* 更新进度条的最大值 */
    ui->processBar->setRange(0, static_cast<int>(duration));
}

void musicMenu::handlePositonSlot(qint64 position)
{
    ui->processBar->setValue(static_cast<int>(position));

    int minutes = static_cast<int>(position / 60000);  // 将毫秒转换为分钟
    int seconds = static_cast<int>((position % 60000) / 1000);  // 将剩余的毫秒转换为秒
    QString formatStr = "%1:%2";
    QString currentTime = formatStr.arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));  // 确保秒数为两位数，前导零

    ui->currentTime->setText(currentTime);
}
