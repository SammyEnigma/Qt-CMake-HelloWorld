QT += core gui widgets

TARGET = config
TEMPLATE = app

CONFIG += c++11 no_smart_library_merge static

FORMS   += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp
HEADERS += mainwindow.h

QMAKE_CXXFLAGS += -Wno-expansion-to-defined
QMAKE_LFLAGS = -static
