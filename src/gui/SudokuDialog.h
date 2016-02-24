#ifndef SUDOKUDIALOG_H_
#define SUDOKUDIALOG_H_

#include <QMainWindow>

#include "ui_SudokuDialogUi.h"

class SudokuDialog : public QMainWindow, public Ui_SudokuDialogUi
{
    Q_OBJECT;

public:
    SudokuDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~SudokuDialog();
};

#endif /* SUDOKUDIALOG_H_ */
