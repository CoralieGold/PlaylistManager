CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS +=  -std=c++11

QT += widgets

QT += core gui

QT += multimedia

HEADERS += \
    author.h \
    time.h \
    track.h \
    mainwindow.h \
    playlist.h \
    interface.h

SOURCES += \
    author.cpp \
    main.cpp \
    time.cpp \
    track.cpp \
    mainwindow.cpp \
    playlist.cpp \
    interface.cpp

FORMS += \
    mainwindow.ui

DISTFILES += \
    authors.txt \
    Sons/Cherche-moi-Long.mp3
