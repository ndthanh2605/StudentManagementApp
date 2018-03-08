#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T22:06:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Entity/jsonentity.cpp \
    Entity/student.cpp \
    UI/formlogin.cpp \
    UI/Student/formstudentlist.cpp \
    Model/studentmodel.cpp \
    webservicecontroller.cpp \
    jsondataparser.cpp \
    UI/Student/formaddstudent.cpp

HEADERS += \
        mainwindow.h \
    Entity/jsonentity.h \
    Entity/student.h \
    UI/formlogin.h \
    UI/Student/formstudentlist.h \
    Model/studentmodel.h \
    webservicecontroller.h \
    jsondataparser.h \
    UI/Student/formaddstudent.h

FORMS += \
        mainwindow.ui \
    UI/formlogin.ui \
    UI/Student/formstudentlist.ui \
    UI/Student/formaddstudent.ui

RESOURCES += \
    assets.qrc
