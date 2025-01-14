#ifndef WINDOWS_H
#define WINDOWS_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>

QT_BEGIN_NAMESPACE

namespace Ui {
class Window;
}

QT_END_NAMESPACE


class Window : public QWidget {
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

    ~Window();

private:
    void open();

private slots:
    void on_btnOpen_clicked();

private:
    QLabel *label;
    QLineEdit *lineEdit_path;
    QPushButton *btnOpen;
    QLabel *label_image;
    QString FilePath;
};
#endif //WINDOWS_H
