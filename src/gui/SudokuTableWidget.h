#ifndef SUDOKUTABLEWIDGET_H_
#define SUDOKUTABLEWIDGET_H_

#include <QTableWidget>
#include <QTableWidgetItem>

class SudokuTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    SudokuTableWidget(QWidget *parent = 0);
    void setupBoard(bool);

signals:
    void test();

private:
    void paintEvent(QPaintEvent *e);
    void clear(bool);

private slots:
        void slotValidateInput(QTableWidgetItem *);

private:
    Board m_board;
    QList<QTableWidgetItem *> m_ignoredItems;
};

#endif /* SUDOKUTABLEWIDGET_H_ */
