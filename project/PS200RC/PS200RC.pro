#-------------------------------------------------
#
# Project created by QtCreator 2014-09-24T17:42:53
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PS200RC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    singlevaluedialog.cpp \
    mydoublespinbox.cpp \
    settingsdialog.cpp \
    settingshelper.cpp \
    serialworker.cpp

HEADERS  += mainwindow.h \
    singlevaluedialog.h \
    mydoublespinbox.h \
    settingsdialog.h \
    settingshelper.h \
    serialworker.h

FORMS    += mainwindow.ui \
    singlevaluedialog.ui \
    settingsdialog.ui