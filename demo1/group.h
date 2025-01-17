
#ifndef GROUP_H
#define GROUP_H

#include <QWidget>

namespace window_group {


class group : public QWidget {
Q_OBJECT

public:
    explicit group(QWidget *parent = nullptr);
    ~group() override;

private:
};
} // window_group

#endif //GROUP_H
