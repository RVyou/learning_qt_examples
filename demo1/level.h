

#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>

namespace window_level {

class level : public QWidget {
Q_OBJECT

public:
    explicit level(QWidget *parent = nullptr);
    ~level() override;

private:
};
} // window_level

#endif //LEVEL_H
