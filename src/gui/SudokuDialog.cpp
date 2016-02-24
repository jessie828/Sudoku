#include "SudokuDialog.h"

#include <stdio.h>

SudokuDialog::SudokuDialog(QWidget *parent, Qt::WindowFlags flags)
  : QMainWindow(parent, flags)
{
    printf("welcome to Sudoku\n");
    setupUi(this);

    connect(m_newButton, SIGNAL(clicked()), SLOT(slotNewClicked()));
    connect(m_resetButton, SIGNAL(clicked()), SLOT(slotResetClicked()));
    connect(m_exitButton, SIGNAL(clicked()), SLOT(slotExitClicked()));
}

SudokuDialog::~SudokuDialog()
{
}


void SudokuDialog::slotNewClicked()
{
    printf("New Game\n");
}


void SudokuDialog::slotResetClicked()
{
    printf("Reset Game\n");
}


void SudokuDialog::slotExitClicked()
{
    close();
}

