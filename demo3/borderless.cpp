//
// Created by aini on 2025/1/17.
//


#include <QDebug>
#include <QVBoxLayout>
#include "borderless.h"
#include "topmenu.h"

borderless::borderless(QWidget *parent) : QWidget(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    this->setContentsMargins(0, 0, 0, 0);
    this->setStyleSheet("background-color:rgb(255, 255, 255)");;
    this->setMinimumSize(800, 600);
    //垂直波距
    auto *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    //自定义菜单栏
    auto *menu = new topMenu();


    //底部窗口
    auto *qw = new QWidget();
    qw->setMinimumSize(800, 550);
    qw->setStyleSheet("background-color:rgb(15, 185, 125)");;
    qw->setContentsMargins(0, 0, 0, 0);

    vbox->addWidget(menu);
    vbox->addWidget(qw);


    //x 关闭窗口
    connect(menu, &topMenu::closeWindow, this, [=]() {
        qDebug() << "closeWindowEvent";
        this->close();
    });
}


borderless::~borderless() {
}
