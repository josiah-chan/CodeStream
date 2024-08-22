#include "customlabel.h"

customlabel::customlabel(QWidget *parent) : QLabel(parent)
{
    m_filename = " ";
}

void customlabel::setHeadImage(const QString &filename)
{
    QPixmap headPic(filename);
    setPixmap(headPic.scaled(135,135,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    m_filename = filename;
}

/* 鼠标进入事件 */
void customlabel::enterEvent(QEvent *event)
{
    setStyleSheet("background-color:rgb(0,0,0,100);"    // 半透明
                  "color: white;"                       // 白色文本
                  "font-weight: bold;");                // 粗体
    setText("更改头像");
    setAlignment(Qt::AlignCenter);                      // 文本居中

    /* 让进入事件回归到父类 */
    QLabel::enterEvent(event);
}

/* 鼠标离开事件 */
void customlabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开" << endl;
    setHeadImage(m_filename);

    /* 让离开事件回归到父类 */
    QLabel::leaveEvent(event);
}

/* 鼠标点击事件 */
void customlabel::mousePressEvent(QMouseEvent *event)
{
    setStyleSheet("background-color:rgb(0,0,0,100);"    // 半透明
                  "color: white;"                       // 白色文本
                  "font-weight: bold;");                // 粗体
    setText("显示更改头像");
    QString filter = "Image Files (*.png *.jpg *.jpeg *.gif)";
    QString filename = QFileDialog::getOpenFileName(this, "选择新头像", " ", filter);

    /* 设置头像 */
    if(filename.size() > 0)
    {
        setHeadImage(filename);
    }
    else
    {
        setHeadImage(m_filename);
    }


    /* 让事件回归到父类 */
    QLabel::mousePressEvent(event);
}
