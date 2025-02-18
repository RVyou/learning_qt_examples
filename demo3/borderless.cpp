#include <QDebug>
#include <QVBoxLayout>
#include "borderless.h"
#include "topmenu.h"

#include <QMouseEvent>
#include <qt_windows.h>
#include <windowsx.h>
#include <Windows.h>
#include <QPoint>

borderless::borderless(QWidget *parent) : QWidget(parent) {
    //拉伸
    this->setAttribute(Qt::WA_Hover, true);
    //| Qt::WindowMinMaxButtonsHint 这个属性加上就不能伸拉
    this->setWindowFlags(Qt::FramelessWindowHint);


    this->setContentsMargins(0, 0, 0, 0);
    this->setStyleSheet("background-color:rgb(255, 255, 255)");;
    this->setMinimumSize(800, 600);
    //垂直布局
    auto *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(0, 0, 0, 0);
    vbox->setSpacing(0);
    //自定义菜单栏
    auto *menu = new topMenu();


    //底部窗口
    auto *qw = new QWidget();
    qw->setMinimumSize(800, 550);
    qw->setStyleSheet("background-color:rgb(15, 185, 125)");;
    qw->setContentsMargins(0, 0, 0, 0);

    vbox->addWidget(menu);
    vbox->addWidget(qw);


    //x 关闭窗口
    connect(menu, &topMenu::closeWindow, this, [=]() {
        qDebug() << "closeWindowEvent";
        this->close();
    });
}

bool borderless::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
    switch (auto param = static_cast<MSG *>(message); param->message) {
        case WM_NCHITTEST: {
            // 1. 获取窗口的 DPI
            UINT dpi = GetDpiForWindow(param->hwnd);

            // 2. 获取屏幕坐标（已经经过缩放）
            int x = GET_X_LPARAM(param->lParam);
            int y = GET_Y_LPARAM(param->lParam);

            // 3. 将屏幕坐标反缩放为逻辑坐标
            //    注意：这里直接用除法进行反缩放。更精确的做法是使用DPIScaling等更复杂的处理。
            x = MulDiv(x, 96, dpi);
            y = MulDiv(y, 96, dpi);

            // 4. 使用 mapFromGlobal 将逻辑坐标转换为窗口局部坐标
            QPoint globalPos(x, y);
            QPoint localPos = this->mapFromGlobal(globalPos);
            const int nX = localPos.x();
            const int nY = localPos.y();

            if (nX > m_nBorderWidth && nX < this->width() - m_nBorderWidth &&
                nY > m_nBorderWidth && nY < this->height() - m_nBorderWidth) {
                if (childAt(nX, nY) != nullptr)
                    return QWidget::nativeEvent(eventType, message, result);
            }
            // 左边框
            if (nX > 0 && nX < m_nBorderWidth) {
                *result = HTLEFT;
            }
            // 右边框
            if (nX > this->width() - m_nBorderWidth && nX < this->width()) {
                *result = HTRIGHT;
            }
            // 上边框
            if (nY > 0 && nY < m_nBorderWidth) {
                *result = HTTOP;
            }
            // 下边框
            if (nY > this->height() - m_nBorderWidth && nY < this->height()) {
                *result = HTBOTTOM;
            }

            // 左上角
            if (nX > 0 && nX < m_nBorderWidth && nY > 0 && nY < m_nBorderWidth) {
                *result = HTTOPLEFT;
            }
            // 右上角
            if (nX > this->width() - m_nBorderWidth && nX < this->width() && nY > 0 && nY < m_nBorderWidth) {
                *result = HTTOPRIGHT;
            }
            // 左下角
            if (nX > 0 && nX < m_nBorderWidth && nY > this->height() - m_nBorderWidth && nY < this->height()) {
                *result = HTBOTTOMLEFT;
            }
            // 右下角
            if (nX > this->width() - m_nBorderWidth && nX < this->width() && nY > this->height() - m_nBorderWidth && nY
                < this->height()) {
                *result = HTBOTTOMRIGHT;
            }
            if (*result != HTNOWHERE) {
                // qDebug() << "WM_NCHITTEST" << *result;
                return true;
            }
            return false;
        }
        default: ;
    }

    return QWidget::nativeEvent(eventType, message, result); // 其他消息交给 Qt 处理
}

borderless::~borderless() {
}
