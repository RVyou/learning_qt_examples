//
// Created by aini on 2025/1/17.
//

#ifndef TOPMENU_H
#define TOPMENU_H

#include <QWidget>
#include <QMouseEvent>


class topMenu : public QWidget {
    Q_OBJECT

public:
    explicit topMenu(QWidget *parent = nullptr);

    ~topMenu() override;

    //发送信号
    void closeWindowEvent() {
        qDebug() << "closeWindow:";
        emit closeWindow();
    }

signals:
    void closeWindow();//信号

private:
    QPoint movPos;

    void mousePressEvent(QMouseEvent *event) override; //鼠标单击事件
    void mouseMoveEvent(QMouseEvent *event) override; //移动事件
};


#endif //TOPMENU_H
