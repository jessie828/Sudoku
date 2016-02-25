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
}


void SudokuDialog::slotExitClicked()
{
    close();
}


void SudokuDialog::newGame()
{
    QMap<QPair<int, int>, int> board;
    board.insert(QPair<int, int>(1,0), 3);
    board.insert(QPair<int, int>(3,0), 2);
    board.insert(QPair<int, int>(5,0), 9);
    board.insert(QPair<int, int>(8,0), 5);
    board.insert(QPair<int, int>(2,1), 8);
    board.insert(QPair<int, int>(3,1), 1);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
//    board.insert(QPair<int, int>(0,2), 6);
    m_table->setupBoard(board);
}

