
#ifndef STACKED_H
#define STACKED_H

#include <QWidget>

namespace window_stacked {


class stacked : public QWidget {
Q_OBJECT

public:
    explicit stacked(QWidget *parent = nullptr);
    ~stacked() override;

private:
};
} // window_stacked

#endif //STACKED_H
