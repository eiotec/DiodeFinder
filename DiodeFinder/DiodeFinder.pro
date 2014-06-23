#-------------------------------------------------
#
# Project created by QtCreator 2014-04-14T13:23:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DiodeFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    diodefinder.cpp \
    sceneobject.cpp \
    stableobject.cpp

HEADERS  += mainwindow.h \
    diodefinder.h \
    sceneobject.h \
    stableobject.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

QMAKE_CXXFLAGS += -std=c++0x
