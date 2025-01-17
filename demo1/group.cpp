
#include "group.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>


namespace window_group {
group::group(QWidget *parent) :
    QWidget(parent) {
    this->setWindowTitle("分组框布局");

    // 主 ：创建一个垂直布局
    auto *layout = new QVBoxLayout(this);

    // 创建一个QGroupBox
    auto *groupBox = new QGroupBox("选项组", this);
    groupBox->setCheckable(true); // 设置QGroupBox为可选中

    // 在QGroupBox中添加控件
    auto *checkBox1 = new QCheckBox("选项1", groupBox);
    auto *checkBox2 = new QCheckBox("选项2", groupBox);
    auto *radioButton1 = new QRadioButton("单选1", groupBox);
    auto *radioButton2 = new QRadioButton("单选2", groupBox);
    auto *lineEdit = new QLineEdit(groupBox);

    // 内：创建一个水平布局来组织QGroupBox内的控件
    auto *groupBoxLayout = new QHBoxLayout(groupBox);
    groupBoxLayout->addWidget(checkBox1);
    groupBoxLayout->addWidget(checkBox2);
    groupBoxLayout->addWidget(radioButton1);
    groupBoxLayout->addWidget(radioButton2);
    groupBoxLayout->addWidget(lineEdit);

    // 创建第二个个QGroupBox
    auto *groupBox2 = new QGroupBox("第二组", this);
    auto *checkBox5 = new QCheckBox("选项1", groupBox2);
    // 内：创建一个水平布局来组织QGroupBox内的控件
    auto *groupBoxLayout2 = new QHBoxLayout(groupBox2);
    groupBoxLayout2->addWidget(checkBox5);

    // 将QGroupBox添加到主窗口的布局中
    layout->addWidget(groupBox);
    layout->addWidget(groupBox2);

}

group::~group() {
}
} // window_group
