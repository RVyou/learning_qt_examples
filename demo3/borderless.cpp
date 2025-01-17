//
// Created by aini on 2025/1/17.
//


#include "borderless.h"
#include <QDebug>


borderless::borderless(QWidget *parent) : QWidget(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
}

void borderless::mousePressEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //windows订单坐标
    const auto wPos = this->pos();
    //点击偏移跟窗口的便宜
    movPos = pos - wPos;
}

void borderless::mouseMoveEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //当前点跟窗口的位置
    this->move(pos-movPos);
}

borderless::~borderless() {
}
