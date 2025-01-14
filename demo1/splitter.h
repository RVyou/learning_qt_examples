//
// Created by aini on 2025/1/13.
//

#ifndef SPLITTER_H
#define SPLITTER_H

#include <QWidget>

namespace window_splitter {

class splitter : public QWidget {
Q_OBJECT

public:
    explicit splitter(QWidget *parent = nullptr);
    ~splitter() override;

private:
};
} // window_splitter

#endif //SPLITTER_H
