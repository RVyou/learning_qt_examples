#include "dialog.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QStandardPaths>
#include <QImageReader>
#include <QSettings>
#include <QImage>
#include <QPixmap>



Window::Window(QWidget *parent)
    : QWidget(parent) {
    //固定大小
    setFixedSize(800, 600);
    // 创建主布局
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    // 创建水平布局
    QHBoxLayout *horizontalLayout = new QHBoxLayout();

    // 创建控件
    label = new QLabel("图片路径", this);
    lineEdit_path = new QLineEdit(this);
    btnOpen = new QPushButton("打开", this);
    label_image = new QLabel("TextLabel", this);

    // 将控件添加到水平布局
    horizontalLayout->addWidget(label);
    horizontalLayout->addWidget(lineEdit_path);
    horizontalLayout->addWidget(btnOpen);

    // 将水平布局和图片标签添加到垂直布局
    verticalLayout->addLayout(horizontalLayout);
    verticalLayout->addWidget(label_image);

    // 设置布局
    setLayout(verticalLayout);

    // 连接按钮点击信号到槽函数
    connect(btnOpen, &QPushButton::clicked, this, &Window::on_btnOpen_clicked);

    // 初始化图片标签
    label_image->clear();
}

Window::~Window() {
}

void Window::open() {
    if (FilePath.isEmpty()) {
        FilePath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    }
    qDebug() << "File Path :" << FilePath;
    QString fileName = QFileDialog::getOpenFileName(this, "请选择图片", FilePath, "图片(*.png *.jpg);;");
    qDebug() << "Selected file:" << fileName;

    if (fileName.isEmpty()) {
        return;
    }
    int dirEnd = fileName.lastIndexOf("/");
    if (dirEnd != -1) {
        FilePath = fileName.left(dirEnd);
    }

    // 检查文件是否存在
    if (!QFile::exists(fileName)) {
        qDebug() << "File does not exist:" << fileName;
        return;
    }



    qDebug() << "Supported formats:" << QImageReader::supportedImageFormats();
    // 使用 QImage 加载图片
    QImage  image(fileName);
    if (image.isNull()) {

        qDebug() << "Failed to load image:" << fileName;
        return;
    }

    // 将 QImage 转换为 QPixmap
    QPixmap pixmap = QPixmap::fromImage(image);
    if (pixmap.isNull()) {
        qDebug() << "Failed to convert QImage to QPixmap:" << fileName;
        return;
    }

    // 缩放图片并显示·
    pixmap = pixmap.scaled(label_image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label_image->setPixmap(pixmap);
    lineEdit_path->setText(fileName);
}

void Window::on_btnOpen_clicked() {
    open();
}
