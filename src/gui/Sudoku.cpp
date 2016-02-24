#include "SudokuDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SudokuDialog dialog;
    dialog.show();

    return app.exec();
}
