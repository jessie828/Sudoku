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


void SudokuDialog::slotNewClicked()
{
    printf("New Game\n");
    newGame();
}


void SudokuDialog::slotResetClicked()
{
    printf("Reset Game\n");
    reloadGame();
}


void SudokuDialog::slotExitClicked()
{
    close();
}


void SudokuDialog::reloadGame()
{
    m_table->setupBoard(false);
}


void SudokuDialog::newGame()
{
    m_table->setupBoard(true);
}

