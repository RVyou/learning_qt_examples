//
// Created by aini on 2025/1/13.
//

#ifndef FENCE_H
#define FENCE_H

#include <QWidget>

namespace window_fence {

class fence : public QWidget {
Q_OBJECT

public:
    explicit fence(QWidget *parent = nullptr);
    ~fence() override;

private:
};
} // window_fence

#endif //FENCE_H
