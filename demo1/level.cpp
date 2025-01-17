
#include "level.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

namespace window_level {
    level::level(QWidget *parent) : QWidget(parent) {
        this->setWindowTitle("水平布局");
        this->setFixedSize(800, 600);

        auto *level = new QHBoxLayout(this);
        auto *path = new QLabel(this);
        path->setObjectName("path");
        path->setText("path");
        path->setFixedSize(40, 50);

        auto *edit = new QLineEdit(this);
        edit->setObjectName("edit");
        edit->setFixedSize(100, 50);

        auto *button = new QPushButton(this);
        button->setObjectName("button");
        button->setText("button1");
        level->setAlignment(Qt::AlignLeft); //向左对齐
        level->addWidget(path);
        level->addWidget(button);
        level->addWidget(edit);

        auto *vertical = new QVBoxLayout(this);

        auto *button1 = new QPushButton("按钮 1");
        auto *button2 = new QPushButton("按钮 2");
        auto *button3 = new QPushButton("按钮 3");

        vertical->addWidget(button1);
        vertical->addWidget(button2);
        vertical->addWidget(button3);
        level->addLayout(vertical); //添加垂直
    }

    level::~level() {
    }
} // window_level
