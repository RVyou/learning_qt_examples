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
    this->setMaximumHeight(50);
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
    auto *bt3 = new QPushButton(this);
    bt3->setMinimumSize(30, 50);
    bt3->setFixedSize(30, 50);
    bt3->setText("口");
    auto *bt4 = new QPushButton(this);
    bt4->setMinimumSize(30, 50);
    bt4->setFixedSize(30, 50);
    bt4->setText("一");
    //x点击点击信号关闭
    connect(bt2, &QPushButton::clicked, this, [=]() {
        qDebug() << "bt2";
        this->closeWindowEvent();
    });
    //大小窗口变化
    connect(bt3, &QPushButton::clicked, this, [=]() {
        qDebug() << "bt3" << this->windowStatus;
        if (this->windowStatus) {
            this->windowStatus = false;
            this->parentWidget()->showNormal();
        } else {
            this->windowStatus = true;
            this->parentWidget()->showMaximized();
        }
    });
    //最小化窗口
    connect(bt4, &QPushButton::clicked, this, [=]() {
        qDebug() << "bt4";
        this->parentWidget()->showMinimized();
    });


    // bt2->setStyleSheet("QPushButton {"
    //                      "border: none;" // 去掉边框
    //                      "background-color: white;" // 设置背景色
    //                      "shadow: none;" // 去掉阴影
    //                      "}");

    hBox->addWidget(bt);
    hBox->addStretch();
    hBox->addWidget(bt4);
    hBox->addWidget(bt3);
    hBox->addWidget(bt2);
}

//双击放大和缩小
void topMenu::mouseDoubleClickEvent(QMouseEvent *event) {
    qDebug() << "mouseDoubleClickEvent";
    if (this->windowStatus) {
        this->windowStatus = false;
        this->parentWidget()->showNormal();
    } else {
        this->windowStatus = true;
        this->parentWidget()->showMaximized();
    }
}

void topMenu::mousePressEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //windows左上角坐标
    const auto wPos = this->parentWidget()->pos();
    //点击偏移跟窗口的偏移点
    movPos = pos - wPos;


    //计算偏移比率缩放使用
    auto w = this->parentWidget()->width();
    //偏右
    if (w / 3 * 2 < pos.x() && this->windowStatus) {
        movPos.setX(800 - w + pos.x());
        //中间范围内宽度直接居中就行
    } else if (w / 3 < pos.x() && this->windowStatus) {
        movPos.setX((800 / 2));
    }

    qDebug() << "mousePressEvent movPos:" << movPos;
    qDebug() << "mousePressEvent Pos :" << pos;
    qDebug() << "mousePressEvent width :" << w;
}

void topMenu::mouseMoveEvent(QMouseEvent *event) {
    const auto pos = event->globalPos();
    //如果是最大化时候先缩放  方法一般
    if (this->windowStatus) {
        this->windowStatus = false;
        this->parentWidget()->showNormal();
        qDebug() << "showNormal click movPos:" << movPos;
        //窗口缩放后无法第一时间获取到宽度
        //调整缩放后的偏差
        qDebug() << "showNormal click width:" << this->parentWidget()->width();;
        this->parentWidget()->move(pos - movPos);

        return;
    }

    //父类窗口做移动
    this->parentWidget()->move(pos - movPos);
    qDebug() << "mouseMoveEvent Pos:" << movPos;
    qDebug() << "mouseMoveEvent Pos :" << pos;
}

topMenu::~topMenu() {
}
