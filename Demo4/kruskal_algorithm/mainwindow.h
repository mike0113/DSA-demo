#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Graph.h"
#include <vector>

using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void kruskalMST();

    int findIndex(char );
    int cost[51][51];
    vector<char> node;
    int maximum;

    void drawNode(QPainter &painter);
    int center_x;
    int center_y;
    int r;
    vector<vector<int>> kruskalOrder;
    bool flag;
    int step;
    bool path;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

protected:
void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
