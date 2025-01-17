#include <QApplication>

#include "fence.h"
#include "group.h"
#include "layout_switch.h"
#include "level.h"
#include "splitter.h"
#include "stacked.h"

int main(int argc, char *argv[]) {
    qputenv("QT_QPA_PLATFORM", "windows:darkmode=0");
    QApplication a(argc, argv);
    auto *l = new window_level::level();
    l->show();
    auto *f = new window_fence::fence();
    f->show();
    auto *s = new window_splitter::splitter();
    s->show();
    auto *st = new window_stacked::stacked();
    st->show();
    auto *g = new window_group::group();
    g->show();
    auto *ls = new window_layout_switch::layout_switch();
    ls->show();
    return QApplication::exec();
}
