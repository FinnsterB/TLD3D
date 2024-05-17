TEMPLATE = app
TARGET = PLD3D

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += ../src/window.h ../src/render.h ../src/triangle.h ../src/projector.h
SOURCES += ../src/window.cpp ../src/render.cpp ../src/triangle.cpp ../src/projector.cpp

SOURCES +=  ../src/main.cpp
