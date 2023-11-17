QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/board.cpp \
    Model/game.cpp \
    Model/move.cpp \
    Model/player.cpp \
    Model/position.cpp \
    Model/square.cpp \
    Model/support.cpp \
    boardview.cpp \
    gameoverwindow.cpp \
    main.cpp \
    mwdiaballik.cpp \
    option.cpp \
    squareview.cpp


HEADERS += \
    Model/board.h \
    Model/direction.h \
    Model/game.h \
    Model/move.h \
    Model/player.h \
    Model/playerColor.h \
    Model/position.h \
    Model/square.h \
    Model/support.h \
    PatternObs/observer.h \
    PatternObs/subject.h \
    boardview.h \
    gameoverwindow.h \
    mwdiaballik.h \
    option.h \
    squareview.h


FORMS += \
    gameoverwindow.ui \
    mwdiaballik.ui \
    option.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
