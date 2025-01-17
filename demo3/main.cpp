#include <QApplication>
#include "borderless.h"

int main(int argc, char *argv[]) {
    qputenv("QT_QPA_PLATFORM", "windows:darkmode=0");
    QApplication a(argc, argv);

    auto *w =new borderless();
    w->show();
    return QApplication::exec();
}

