#pragma once

#include <QComboBox>
#include <QList>
#include <QString>
#include <QPair>

/**
 * 简单版主题选择器 - 不依赖项目内部文件
 * 可以直接复制到任何 Qt 项目中使用
 */
class SimpleThemeSelector : public QComboBox
{
    Q_OBJECT
public:
    explicit SimpleThemeSelector(QWidget *parent = nullptr);

    // 获取所有可用主题列表: (主题名, 主题文件路径)
    static QList<QPair<QString, QString>> getThemeInfo();

    // 设置主题
    static void setTheme(const QString &themeFile);
};
