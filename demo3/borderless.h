#ifndef BORDERLESS_H
#define BORDERLESS_H


#include <QWidget>


class borderless : public QWidget {
    Q_OBJECT

public:
    explicit borderless(QWidget *parent = nullptr);
    ~borderless() override;

private:
    int m_nBorderWidth = 10;
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
};


#endif //BORDERLESS_H
