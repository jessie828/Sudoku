include( ../Sudoku.pri )

TEMPLATE = app

INCLUDEPATH = \
        $$SUDOKU_SANDBOX_SRC/util \
        #

CONFIG += qt static

DYNAMIC_FLAG = -Wl,-Bdynamic
STATIC_FLAG = -Wl,-Bstatic

LIBS += \
    -L$$SUDOKU_SANDBOX_LIB \
    -lutil \
    #

POST_TARGETDEPS = \
    $$SUDOKU_SANDBOX_LIB/* \
    #

TARGET = Sudoku.exe

DESTDIR = $$SUDOKU_SANDBOX_BIN
MOC_DIR = $$SUDOKU_SANDBOX_MOC
UI_SOURCES_DIR = ./uic_cpp
UI_HEADERS_DIR = ./uic_headers

QMAKE_LFLAGS_RPATH =
QMAKE_LFLAGS =

SOURCES += \
        SudokuDialog.cpp \
        SudokuTableWidget.cpp \
        Sudoku.cpp \
        #

HEADERS += \
        SudokuDialog.h \
        SudokuTableWidget.h \
        #

FORMS += \
        SudokuDialogUi.ui \
        #
