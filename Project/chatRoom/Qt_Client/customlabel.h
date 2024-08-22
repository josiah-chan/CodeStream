#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QString>
#include <QFileDialog>

class customlabel : public QLabel
{
    Q_OBJECT
public:
    explicit customlabel(QWidget *parent = nullptr);

public:
    /* 设置头像 */
    void setHeadImage(const QString & filename);

protected:
    /* 1.鼠标进入事件 */
    void enterEvent(QEvent *event) override;

    /* 2.鼠标离开事件 */
    void leaveEvent(QEvent *event) override;

    /* 3.鼠标点击事件 */
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString m_filename;

signals:

public slots:
};

#endif // CUSTOMLABEL_H
