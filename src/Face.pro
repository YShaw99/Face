#-------------------------------------------------
#
# Project created by QtCreator 2020-12-27T19:35:58
#
#-------------------------------------------------

QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Face
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    register.cpp \
    publicfun.cpp \

HEADERS  += mainwindow.h \
    login.h \
    register.h \
    publicfun.h

FORMS    += mainwindow.ui \
    login.ui \
    register.ui

INCLUDEPATH += ../include \
               ../include/opencv \
               ../include/opencv2

LIBS += ../lib/libopencv_*.a

RESOURCES += \
    ../res/res.qrc

