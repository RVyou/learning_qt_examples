//
// Created by aini on 2025/1/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_stacked.h" resolved

#include "stacked.h"
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QStackedLayout>


namespace window_stacked {
    stacked::stacked(QWidget *parent) : QWidget(parent) {
        this->setWindowTitle("堆栈布局");
        this->setFixedSize(600, 400);

        //切换按钮
        auto *pButton = new QPushButton("点击切换", this);

        //切换的页面
        auto *pFirstPage = new QLabel(this);
        pFirstPage->setStyleSheet("QLabel{background-color:rgb(255, 0, 0)}");
        auto *pSecondPage = new QLabel(this);
        pSecondPage->setStyleSheet("QLabel{background-color:rgb(255, 255, 0)}");
        auto *pThirdPage = new QLabel(this);
        pThirdPage->setStyleSheet("QLabel{background-color:rgb(255, 0, 255)}");

        // 添加页面（用于切换）
        auto *m_pStackedLayout = new QStackedLayout();
        m_pStackedLayout->addWidget(pFirstPage);
        m_pStackedLayout->addWidget(pSecondPage);
        m_pStackedLayout->addWidget(pThirdPage);

        //绑定事件 槽
        connect(pButton, &QPushButton::clicked, this, [=]() {
            int nextPage = (m_pStackedLayout->currentIndex() + 1) % m_pStackedLayout->count();
            m_pStackedLayout->setCurrentIndex(nextPage);
        });

        //垂直布局
        auto *pLayout = new QVBoxLayout(this);
        pLayout->addWidget(pButton, 0, Qt::AlignLeft | Qt::AlignVCenter);
        pLayout->addLayout(m_pStackedLayout);
        pLayout->setSpacing(10);
        pLayout->setContentsMargins(10, 10, 10, 10);

    }

    stacked::~stacked() {
    }
} // window_stacked
