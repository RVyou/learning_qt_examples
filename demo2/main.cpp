#include <QApplication>

#include "dialog.h"

int main(int argc, char *argv[]) {
    // QApplication::addLibraryPath("D:\app\qt\6.8.1\msvc2022_64\plugins\imageformats");
    QApplication a(argc, argv);
    Window w;
    w.show();

    return a.exec();
}

