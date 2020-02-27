TEMPLATE = app
TARGET = stereoVidPi

QT = core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    keyReceiver.cpp

HEADERS += \
    window.h \
    keyReceiver.h
