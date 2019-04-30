#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T07:24:22
#
#-------------------------------------------------

QT       += core gui widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gallery-desktop
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

CONFIG += c++14

SOURCES += \
        AlbumListWidget.cpp \
        AlbumWidget.cpp \
        GalleryWidget.cpp \
        PictureWidget.cpp \
        PictureDelegate.cpp \
        ThumbnailProxyModel.cpp \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        AlbumListWidget.h \
        AlbumWidget.h \
        GalleryWidget.h \
        PictureWidget.h \
        MainWindow.h \
        PictureDelegate.h \
        ThumbnailProxyModel.h

FORMS += \
        AlbumListWidget.ui \
        AlbumWidget.ui \
        GalleryWidget.ui \
        PictureWidget.ui \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/release/ -lgallery-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/debug/ -lgallery-core
else:unix: LIBS += -L$$OUT_PWD/../gallery-core/ -lgallery-core

INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-core

RESOURCES += \
    resource.qrc
