#include <QTableWidget>

class SudokuTableWidget : public QTableWidget
{
public:
    SudokuTableWidget(QWidget *parent = 0);
    void setupBoard(const QMap<QPair<int, int>, int> &);

private:
    void paintEvent(QPaintEvent *e);

private:
    bool m_drawLines;
};
