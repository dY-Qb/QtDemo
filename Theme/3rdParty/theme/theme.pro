TARGET = theme
TEMPLATE = lib
QT += core
DEFINES += CORE_LIBRARY
DEFINES += UTILS_LIBRARY

#####################################################################
# set debug/release build environment
#
# CONFIG += debug_and_release
# release: DESTDIR = lib-release
# debug: DESTDIR = lib-debug

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(debug, debug|release) {
    OUTDIR = debug
} else {
    OUTDIR = release
}

##################################################################
# 1. define output folder.
##################################################################

LIB_PATH = $$PWD/../../../../libs
OUT_PATH = $$PWD/../../../../out

DESTDIR     = $$OUT_PATH/$$OUTDIR/libs/
OBJECTS_DIR = $$OUT_PATH/temp/$$TARGET/$$OUTDIR/OBJ/
MOC_DIR     = $$OUT_PATH/temp/$$TARGET/$$OUTDIR/MOC/
RCC_DIR     = $$OUT_PATH/temp/$$TARGET/$$OUTDIR/RCC/
UI_DIR      = $$OUT_PATH/temp/$$TARGET/$$OUTDIR/UI/

include($$PWD/theme.pri)


