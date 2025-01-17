//
// Created by aini on 2025/1/15.
//


#include "layout_switch.h"
#include <QMenu>
#include <QAction>
#include <qcoreevent.h>
#include <QMessageBox>
#include <QLayout>


namespace window_layout_switch {
    layout_switch::layout_switch(QWidget *parent) : QWidget(parent) {
        //菜单策略
        this->setContextMenuPolicy(Qt::DefaultContextMenu);
        this->setStyleSheet("QWidget{background-color:rgb(255, 0, 0)}");
        //构建菜单
        menu = new QMenu(this);
        auto *action1 = new QAction("action1");
        auto *action2 = new QAction("action2");
        auto *action3 = new QAction("action3");
        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        //槽
        connect(menu, &QMenu::triggered, this, [=](QAction *action) {
            // QMessageBox::information(this, "标题", action->text());

            //删除父类元素
            auto *layoutData = this->layout();
            if (layoutData != nullptr) {
                for (auto i = 0; i < layoutData->count(); i++) {
                    auto *layout = layoutData->itemAt(i);
                    if (layout->widget() != nullptr) {
                        layout->widget()->setParent(nullptr);
                    }
                    delete layout;
                }
                delete layoutData;
            };

            if (action->text() == "action1") {
                this->setStyleSheet("QWidget{background-color:rgb(255, 0, 0)}");
            }
            if (action->text() == "action2") {
                this->setStyleSheet("QWidget{background-color:rgb(0, 255, 0)}");
            }
            if (action->text() == "action3") {
                this->setStyleSheet("QWidget{background-color:rgb(0, 0, 255)}");
            }
        });
    }

    //弹出菜单
    void layout_switch::contextMenuEvent(QContextMenuEvent *event) {
        menu->exec(QCursor::pos());
    }

    layout_switch::~layout_switch() {
    }
} // window_layout_switch
