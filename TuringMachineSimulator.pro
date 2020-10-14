#-------------------------------------------------
#
# Project created by QtCreator 2019-06-27T09:11:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TuringMachineSimulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        machine.cpp \
    codeeditor.cpp \
    lexer.cpp \
    parser.cpp \
    token.cpp \
    Config.cpp \
    Mov.cpp \
    erros.cpp \
    playercontroller.cpp

HEADERS  += machine.h \
    codeeditor.h \
    constants.h \
    lexer.h \
    parser.h \
    token.h \
    Config.h \
    erros.h \
    Mov.h \
    playercontroller.h

FORMS  += machine.ui
RC_ICONS = Tms.ico

DISTFILES += \
    3.png

RESOURCES += \
    recursos.qrc

