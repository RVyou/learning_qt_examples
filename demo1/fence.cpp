
#include "fence.h"
#include <QGridLayout>
#include <QPushButton>


namespace window_fence {
fence::fence(QWidget *parent) :
    QWidget(parent) {
    auto* layout = new QGridLayout(this);

    auto *button1 = new QPushButton("按钮 1");
    auto *button2 = new QPushButton("按钮 2");

    auto *vertical = new QVBoxLayout(this);

    auto *b1 = new QPushButton("按钮 1");
    auto *b2 = new QPushButton("按钮 2");
    auto *b3 = new QPushButton("按钮 3");

    vertical->addWidget(b1);
    vertical->addWidget(b2);
    vertical->addWidget(b3);

    layout->addWidget(button1,0,1);
    layout->addWidget(button2,1,1);
    layout->addLayout(vertical,0,0);
}

fence::~fence() {
}
} // window_fence
