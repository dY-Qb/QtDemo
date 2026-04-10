#include "SimpleThemeSelector.h"

#include <utils/stylehelper.h>
#include <utils/theme/theme.h>
#include <utils/theme/theme_p.h>
#include <coreplugin/manhattanstyle.h>

#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QCoreApplication>

static const char themeNameKey[] = "ThemeName";

void SimpleThemeSelector::setTheme(const QString &themeFile)
{
    using namespace Utils;

    static Theme theme("");
    QSettings settings(themeFile, QSettings::IniFormat);
    theme.readSettings(settings);
    setCreatorTheme(&theme);
    StyleHelper::setBaseColor(QColor(StyleHelper::DEFAULT_BASE_COLOR));
    QApplication::setStyle(new ManhattanStyle(creatorTheme()->preferredStyles().value(0)));
    QApplication::setPalette(theme.palette());
}

SimpleThemeSelector::SimpleThemeSelector(QWidget *parent)
    : QComboBox(parent)
{
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("ThemeDemo");

    // 加载所有主题文件
    for (const QFileInfo &themeFile : QDir(":/themes/", "*.creatortheme").entryInfoList()) {
        QSettings settings(themeFile.absoluteFilePath(), QSettings::IniFormat);
        addItem(settings.value(themeNameKey).toString(), themeFile.absoluteFilePath());
    }

    // 默认使用 Flat Dark 主题
    QString defaultTheme = "Flat Dark";
    setCurrentText(defaultTheme);
    if (currentData().isValid()) {
        setTheme(currentData().toString());
    }

    // 切换主题时自动应用
    connect(this, QOverload<int>::of(&QComboBox::currentIndexChanged), [this](int) {
        if (currentData().isValid()) {
            setTheme(currentData().toString());
        }
    });
}

QList<QPair<QString, QString>> SimpleThemeSelector::getThemeInfo()
{
    QList<QPair<QString, QString>> themeList;
    for (const QFileInfo &themeFile : QDir(":/themes/", "*.creatortheme").entryInfoList()) {
        QSettings settings(themeFile.absoluteFilePath(), QSettings::IniFormat);
        themeList << qMakePair(settings.value(themeNameKey).toString(), themeFile.absoluteFilePath());
    }
    return themeList;
}
