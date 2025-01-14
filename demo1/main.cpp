#include <QApplication>

#include "fence.h"
#include "level.h"
#include "splitter.h"

int main(int argc, char *argv[]) {
    qputenv("QT_QPA_PLATFORM", "windows:darkmode=0");
    QApplication a(argc, argv);
    auto * l = new window_level::level();
    l->show();
    auto * f = new window_fence::fence();
    f->show();
    auto * s = new window_splitter::splitter();
    s->show();
    return QApplication::exec();
}
