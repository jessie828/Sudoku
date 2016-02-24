#include "SudokuDialog.h"

#include <stdio.h>

SudokuDialog::SudokuDialog(QWidget *parent, Qt::WindowFlags flags)
  : QMainWindow(parent, flags)
{
    printf("welcome to Sudoku\n");
    setupUi(this);
}

SudokuDialog::~SudokuDialog()
{
}

