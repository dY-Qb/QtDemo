/**
 * 主题库 Demo - 完整版
 *
 * 包含多种控件，展示主题效果
 */

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QSlider>
#include <QProgressBar>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGroupBox>
#include <QTabWidget>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>

#include "SimpleThemeSelector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("主题库 Demo - 控件展示");
    window.resize(900, 700);

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);

    // ==================== 顶部：主题选择器 ====================
    QGroupBox *themeGroup = new QGroupBox("主题选择", &window);
    QHBoxLayout *themeLayout = new QHBoxLayout(themeGroup);
    QLabel *themeLabel = new QLabel("选择主题:", themeGroup);
    SimpleThemeSelector *themeSelector = new SimpleThemeSelector(themeGroup);
    themeLayout->addWidget(themeLabel);
    themeLayout->addWidget(themeSelector);
    themeLayout->addStretch();
    mainLayout->addWidget(themeGroup);

    // ==================== Tab 页：展示各种控件 ====================
    QTabWidget *tabWidget = new QTabWidget(&window);

    // ---------- Tab 1: 基础控件 ----------
    QWidget *tab1 = new QWidget();
    QVBoxLayout *tab1Layout = new QVBoxLayout(tab1);

    // 按钮组
    QGroupBox *btnGroup = new QGroupBox("按钮", tab1);
    QHBoxLayout *btnLayout = new QHBoxLayout(btnGroup);
    btnLayout->addWidget(new QPushButton("普通按钮", btnGroup));
    QPushButton *checkableBtn = new QPushButton("可选中按钮", btnGroup);
    checkableBtn->setCheckable(true);
    checkableBtn->setChecked(true);
    btnLayout->addWidget(checkableBtn);
    QPushButton *flatBtn = new QPushButton("扁平按钮", btnGroup);
    flatBtn->setFlat(true);
    btnLayout->addWidget(flatBtn);
    QPushButton *disabledBtn = new QPushButton("禁用按钮", btnGroup);
    disabledBtn->setEnabled(false);
    btnLayout->addWidget(disabledBtn);
    tab1Layout->addWidget(btnGroup);

    // 复选框和单选框
    QGroupBox *checkGroup = new QGroupBox("选择框", tab1);
    QHBoxLayout *checkLayout = new QHBoxLayout(checkGroup);
    QVBoxLayout *checkVLayout = new QVBoxLayout();
    checkVLayout->addWidget(new QCheckBox("复选框 1", checkGroup));
    QCheckBox *check2 = new QCheckBox("复选框 2 (选中)", checkGroup);
    check2->setChecked(true);
    checkVLayout->addWidget(check2);
    QCheckBox *check3 = new QCheckBox("复选框 3 (禁用)", checkGroup);
    check3->setEnabled(false);
    checkVLayout->addWidget(check3);
    checkLayout->addLayout(checkVLayout);

    QVBoxLayout *radioVLayout = new QVBoxLayout();
    QRadioButton *radio1 = new QRadioButton("单选框 1", checkGroup);
    radioVLayout->addWidget(radio1);
    QRadioButton *radio2 = new QRadioButton("单选框 2 (选中)", checkGroup);
    radio2->setChecked(true);
    radioVLayout->addWidget(radio2);
    QRadioButton *radio3 = new QRadioButton("单选框 3 (禁用)", checkGroup);
    radio3->setEnabled(false);
    radioVLayout->addWidget(radio3);
    checkLayout->addLayout(radioVLayout);
    tab1Layout->addWidget(checkGroup);

    // 输入框
    QGroupBox *inputGroup = new QGroupBox("输入框", tab1);
    QVBoxLayout *inputLayout = new QVBoxLayout(inputGroup);
    QLineEdit *lineEdit1 = new QLineEdit("普通文本输入框", inputGroup);
    inputLayout->addWidget(lineEdit1);
    QLineEdit *lineEdit2 = new QLineEdit("只读输入框", inputGroup);
    lineEdit2->setReadOnly(true);
    inputLayout->addWidget(lineEdit2);
    QLineEdit *lineEdit3 = new QLineEdit("禁用输入框", inputGroup);
    lineEdit3->setEnabled(false);
    inputLayout->addWidget(lineEdit3);
    tab1Layout->addWidget(inputGroup);

    // 下拉框
    QGroupBox *comboGroup = new QGroupBox("下拉框", tab1);
    QHBoxLayout *comboLayout = new QHBoxLayout(comboGroup);
    QComboBox *combo1 = new QComboBox(comboGroup);
    combo1->addItems({"选项 1", "选项 2", "选项 3", "选项 4"});
    comboLayout->addWidget(combo1);
    QComboBox *combo2 = new QComboBox(comboGroup);
    combo2->setEditable(true);
    combo2->addItems({"可编辑下拉框", "选项 A", "选项 B"});
    comboLayout->addWidget(combo2);
    tab1Layout->addWidget(comboGroup);

    tab1Layout->addStretch();
    tabWidget->addTab(tab1, "基础控件");

    // ---------- Tab 2: 数值和进度控件 ----------
    QWidget *tab2 = new QWidget();
    QVBoxLayout *tab2Layout = new QVBoxLayout(tab2);

    // 滑块
    QGroupBox *sliderGroup = new QGroupBox("滑块", tab2);
    QVBoxLayout *sliderLayout = new QVBoxLayout(sliderGroup);
    QSlider *hSlider = new QSlider(Qt::Horizontal, sliderGroup);
    hSlider->setValue(50);
    sliderLayout->addWidget(new QLabel("水平滑块:", sliderGroup));
    sliderLayout->addWidget(hSlider);
    QSlider *vSlider = new QSlider(Qt::Vertical, sliderGroup);
    vSlider->setValue(70);
    sliderLayout->addWidget(new QLabel("垂直滑块:", sliderGroup));
    QHBoxLayout *vSliderLayout = new QHBoxLayout();
    vSliderLayout->addWidget(vSlider);
    vSliderLayout->addStretch();
    sliderLayout->addLayout(vSliderLayout);
    tab2Layout->addWidget(sliderGroup);

    // 进度条
    QGroupBox *progressGroup = new QGroupBox("进度条", tab2);
    QVBoxLayout *progressLayout = new QVBoxLayout(progressGroup);
    QProgressBar *progress1 = new QProgressBar(progressGroup);
    progress1->setValue(30);
    progressLayout->addWidget(progress1);
    QProgressBar *progress2 = new QProgressBar(progressGroup);
    progress2->setValue(75);
    progressLayout->addWidget(progress2);
    QProgressBar *progress3 = new QProgressBar(progressGroup);
    progress3->setRange(0, 0); // 繁忙状态
    progressLayout->addWidget(progress3);
    tab2Layout->addWidget(progressGroup);

    // 数值输入框
    QGroupBox *spinGroup = new QGroupBox("数值输入框", tab2);
    QHBoxLayout *spinLayout = new QHBoxLayout(spinGroup);
    QSpinBox *spinBox = new QSpinBox(spinGroup);
    spinBox->setValue(42);
    spinBox->setRange(0, 100);
    spinLayout->addWidget(new QLabel("整数:", spinGroup));
    spinLayout->addWidget(spinBox);
    QDoubleSpinBox *doubleSpinBox = new QDoubleSpinBox(spinGroup);
    doubleSpinBox->setValue(3.14);
    doubleSpinBox->setRange(0, 10);
    doubleSpinBox->setSingleStep(0.1);
    doubleSpinBox->setDecimals(2);
    spinLayout->addWidget(new QLabel("小数:", spinGroup));
    spinLayout->addWidget(doubleSpinBox);
    tab2Layout->addWidget(spinGroup);

    tab2Layout->addStretch();
    tabWidget->addTab(tab2, "数值和进度");

    // ---------- Tab 3: 文本和列表控件 ----------
    QWidget *tab3 = new QWidget();
    QVBoxLayout *tab3Layout = new QVBoxLayout(tab3);

    // 文本编辑框
    QGroupBox *textGroup = new QGroupBox("文本编辑框", tab3);
    QVBoxLayout *textLayout = new QVBoxLayout(textGroup);
    QTextEdit *textEdit = new QTextEdit(textGroup);
    textEdit->setPlaceholderText("这是一个 QTextEdit，可以输入多行文本...\n\n测试主题效果！");
    textEdit->setPlainText("这是一个 QTextEdit，可以输入多行文本...\n\n测试主题效果！");
    textLayout->addWidget(textEdit);
    tab3Layout->addWidget(textGroup);

    // 列表控件
    QGroupBox *listGroup = new QGroupBox("列表控件", tab3);
    QHBoxLayout *listLayout = new QHBoxLayout(listGroup);

    QListWidget *listWidget = new QListWidget(listGroup);
    listWidget->addItems({"列表项 1", "列表项 2", "列表项 3", "列表项 4", "列表项 5"});
    listWidget->setCurrentRow(1);
    listLayout->addWidget(new QLabel("QListWidget:", listGroup));
    listLayout->addWidget(listWidget);

    QTreeWidget *treeWidget = new QTreeWidget(listGroup);
    treeWidget->setHeaderLabels({"树形列表"});
    QTreeWidgetItem *root1 = new QTreeWidgetItem(treeWidget, {"根节点 1"});
    new QTreeWidgetItem(root1, {"子节点 1-1"});
    new QTreeWidgetItem(root1, {"子节点 1-2"});
    QTreeWidgetItem *root2 = new QTreeWidgetItem(treeWidget, {"根节点 2"});
    new QTreeWidgetItem(root2, {"子节点 2-1"});
    treeWidget->expandAll();
    listLayout->addWidget(new QLabel("QTreeWidget:", listGroup));
    listLayout->addWidget(treeWidget);

    tab3Layout->addWidget(listGroup);

    // 表格控件
    QGroupBox *tableGroup = new QGroupBox("表格控件", tab3);
    QVBoxLayout *tableLayout = new QVBoxLayout(tableGroup);
    QTableWidget *tableWidget = new QTableWidget(4, 3, tableGroup);
    tableWidget->setHorizontalHeaderLabels({"列 1", "列 2", "列 3"});
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 3; ++col) {
            tableWidget->setItem(row, col, new QTableWidgetItem(QString("单元格 %1,%2").arg(row+1).arg(col+1)));
        }
    }
    tableLayout->addWidget(tableWidget);
    tab3Layout->addWidget(tableGroup);

    tabWidget->addTab(tab3, "文本和列表");

    mainLayout->addWidget(tabWidget);

    window.show();

    return a.exec();
}
