#ifndef BORDERLESS_H
#define BORDERLESS_H

#include <QWidget>

#include <QWidget>
#include <QMouseEvent>


class borderless : public QWidget {
    Q_OBJECT

public:
    explicit borderless(QWidget *parent = nullptr);
    ~borderless() override;

protected:
    QPoint movPos;
    void mousePressEvent(QMouseEvent *event) override;//鼠标单击事件
    void mouseMoveEvent(QMouseEvent *event) override;//移动事件
};


#endif //BORDERLESS_H
