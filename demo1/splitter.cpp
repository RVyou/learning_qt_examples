//
// Created by aini on 2025/1/13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_splitter.h" resolved

#include "splitter.h"

#include <QVBoxLayout>
#include <QSplitter>
#include <QTextBrowser>
#include <QPalette>

namespace window_splitter {
    splitter::splitter(QWidget *parent) : QWidget(parent) {
        this->setWindowTitle("分裂器");
        //水平布局
        auto *layout = new QHBoxLayout(this);

        auto *splitter = new QSplitter(this);
        auto *widget = new QWidget(this);
        widget->setWindowIconText("aa");
        widget->setStyleSheet("background-color: rgb(25, 156, 0);");
        widget->setMinimumSize(QSize(300, 300));//固定最小宽高

        splitter->addWidget(widget);
        //父级关联  不关联不发拖动
        auto* splitter2 = new QSplitter(Qt::Vertical,splitter);
        //鼠标弹起后在分割
        splitter2->setOpaqueResize(false);

        auto *widget2 = new QWidget(this);
        widget2->setWindowIconText("bb");
        widget2->setStyleSheet("background-color: rgb(255, 156, 0);");
        widget2->setMinimumSize(QSize(300, 300));

        auto* text = new QTextBrowser(this);
        text->setReadOnly(false);//只读或者可编辑
        splitter2->addWidget(widget2);
        splitter2->addWidget(text);

        splitter->addWidget(splitter2);

        //添加分裂器
        layout->addWidget(splitter);
        // setLayout(layout);//安装布局在当前窗口 如何上面添加this 这里可以不需要
    }

    splitter::~splitter() {
    }
} // window_splitter
