QT       += core gui multimedia multimediawidgets bluetooth
QT       += network webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    game.cpp \
    gamemenu.cpp \
    main.cpp \
    mainwindow.cpp \
    newmenu.cpp \
    normal.cpp \
    profile.cpp \
    qdownloader.cpp \
    restartstart.cpp

HEADERS += \
    ImageDownloader.h \
    dialog.h \
    game.h \
    gamemenu.h \
    mainwindow.h \
    newmenu.h \
    normal.h \
    profile.h \
    qdownloader.h \
    restartstart.h

FORMS += \
    dialog.ui \
    game.ui \
    gamemenu.ui \
    loginstart.ui \
    newmenu.ui \
    normal.ui \
    profile.ui \
    restartstart.ui

TRANSLATIONS += \
    apolo_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    hgf.qrc
