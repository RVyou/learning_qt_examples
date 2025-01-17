//
// Created by aini on 2025/1/15.
//

#ifndef LAYOUT_SWITCH_H
#define LAYOUT_SWITCH_H

#include <QWidget>

namespace window_layout_switch {


class layout_switch : public QWidget {
Q_OBJECT

public:
    explicit layout_switch(QWidget *parent = nullptr);
    ~layout_switch() override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    QMenu *menu;
};
} // window_layout_switch

#endif //LAYOUT_SWITCH_H
