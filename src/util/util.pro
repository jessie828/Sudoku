include( ../Sudoku.pri )

TEMPLATE = lib

INCLUDEPATH = \
        #

CONFIG += staticlib

TARGET = util
DESTDIR = $$SUDOKU_SANDBOX_LIB

MOC_DIR = ./moc_cpp

SOURCES += \
        NumberGroup.cpp \
        #

HEADERS += \
        NumberGroup.h \
        #
