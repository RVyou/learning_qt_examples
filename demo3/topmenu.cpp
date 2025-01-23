//
// Created by aini on 2025/1/17.
//


#include "topmenu.h"

#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>

topMenu::topMenu(QWidget *parent) : QWidget(parent) {
    // 父窗口不影响自窗口
    setAttribute(Qt::WA_StyledBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    //颜色无用
    this->setStyleSheet("background-color:rgb(255, 0, 0)");
    // this->setObjectName("topMenu");
    this->setMinimumSize(800, 50);
    this->setContentsMargins(5, 5, 5, 5);

    auto *hBox = new QHBoxLayout(this);
    hBox->setContentsMargins(0, 0, 0, 0);

    auto *bt = new QPushButton(this);
    bt->setMinimumSize(30, 50);
    bt->setText("left");
    bt->setStyleSheet("QPushButton {"
        "border: none;" // 去掉边框
        "}");

    auto *bt2 = new QPushButton(this);
    bt2->setMinimumSize(30, 50);
    bt2->setFixedSize(30, 50);
    bt2->setText("x");

    //x点击点击信号关闭
    connect(bt2, &QPushButton::clicked, this, [=]() {
        qDebug() << "bt2";
        this->closeWindowEvent();
    });
    // bt2->setStyleSheet("QPushButton {"
    //                      "border: none;" // 去掉边框
    //                      "background-color: white;" // 设置背景色
    //                      "shadow: none;" // 去掉阴影
    //                      "}");

    hBox->addWidget(bt);
    hBox->addStretch();
    hBox->addWidget(bt2);
}


void topMenu::mousePressEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //windows左上角坐标
    const auto wPos = this->parentWidget()->pos();
    //点击偏移跟窗口的便宜
    movPos = pos - wPos;
    qDebug() << "mousePressEvent Pos:" << movPos;
    qDebug() << "mousePressEvent Pos :" << pos;
}

void topMenu::mouseMoveEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //父类窗口做移动
    this->parentWidget()->move(pos - movPos);
    qDebug() << "mouseMoveEvent Pos:" << movPos;
    qDebug() << "mouseMoveEvent Pos :" << pos;
}

topMenu::~topMenu() {
}
