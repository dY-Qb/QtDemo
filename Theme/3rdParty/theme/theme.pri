include($$PWD/widgets/widgets.pri)
include($$PWD/utils/utils-lib.pri)
include($$PWD/coreplugin/coreplugin.pri)
include($$PWD/extensionsystem/extensionsystem.pri)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/aggregation/aggregate.h \
    $$PWD/aggregation/aggregation_global.h \
    $$PWD/app/app_version.h \


SOURCES += \
    $$PWD/aggregation/aggregate.cpp \


RESOURCES += \
    $$PWD/themes.qrc
