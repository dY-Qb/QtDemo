QT += core gui widgets

TARGET = ThemeDemo
TEMPLATE = app

# 引入主题库
include($$PWD/3rdparty/theme/theme_header.pri)
include($$PWD/3rdparty/theme/theme.pri)

SOURCES += \
    main.cpp \
    SimpleThemeSelector.cpp

HEADERS += \
    SimpleThemeSelector.h
