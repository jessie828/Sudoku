#ifndef SUDOKUTABLEWIDGET_H_
#define SUDOKUTABLEWIDGET_H_

#include <QTableWidget>
#include <QTableWidgetItem>

class SudokuTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    SudokuTableWidget(QWidget *parent = 0);
    void setupBoard(const QMap<QPair<int, int>, int> &);

signals:
    void test();

private:
    void paintEvent(QPaintEvent *e);

private slots:
        void slotValidateInput(QTableWidgetItem *);
};

#endif /* SUDOKUTABLEWIDGET_H_ */
