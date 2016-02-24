#ifndef SUDOKUDIALOG_H_
#define SUDOKUDIALOG_H_

#include <QMainWindow>

#include "ui_SudokuDialogUi.h"

class SudokuDialog : public QMainWindow, public Ui_SudokuDialogUi
{
    Q_OBJECT;

public:
    SudokuDialog();
    virtual ~SudokuDialog();
};

#endif /* SUDOKUDIALOG_H_ */
