#-------------------------------------------------
#
# Project created by QtCreator 2019-04-21T13:41:46
#
#-------------------------------------------------
include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui



QT       -= gui

TARGET = cm-lib
TEMPLATE = lib

DEFINES += CMLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += source

SOURCES += source/models/client.cpp \
    source/controllers/command-controller.cpp \
    source/controllers/mastercontroller.cpp \
    source/data/DateTimeDecorator.cpp \
    source/data/EnumeratorDecorator.cpp \
    source/data/IntDecorator.cpp \
    source/data/StringDecorator.cpp \
    source/data/datadecorator.cpp \
    source/data/entity.cpp \
    source/framework/command.cpp

HEADERS += source/cm-lib_global.h \
            source/controllers/command-controller.h \
            source/controllers/mastercontroller.h \
            source/controllers/navigation-controller.h \
            source/data/DateTimeDecorator.h \
            source/data/EnumeratorDecorator.h \
            source/data/IntDecorator.h \
            source/data/StringDecorator.h \
            source/data/datadecorator.h \
            source/data/entity-connection.h \
            source/data/entity.h \
            source/framework/command.h \
            source/models/client.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


