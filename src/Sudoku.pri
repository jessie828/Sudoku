CONFIG += release warn_on
CONFIG += ordered

OBJECTS_DIR = $$(SUDOKU_BUILD)/obj

SUDOKU_SANDBOX     = $$(SUDOKU_BUILD)
SUDOKU_SANDBOX_BIN = $$SUDOKU_SANDBOX/bin
SUDOKU_SANDBOX_LIB = $$SUDOKU_SANDBOX/lib
SUDOKU_SANDBOX_SRC = $$SUDOKU_SANDBOX/src
SUDOKU_SANDBOX_MOC = ./moc_cpp

QMAKE_CXXFLAGS += -fPIC -fmessage-length=0
QMAKE_CFLAGS   += -fPIC -fmessage-length=0 

# Additional optimizations for release build
QMAKE_CXXFLAGS += -finline-functions
QMAKE_CFLAGS   += -finline-functions

QMAKE_LIBDIR_X11 += /usr/X11R6/lib64
