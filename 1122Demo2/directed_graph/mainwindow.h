#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    int findIndex(char );
    int cost[51][51];
    vector<char> node;
    int maximum;

    void calcArrow(double start_x, double start_y, double stop_x, double stop_y, double &x1, double &y1, double &x2, double &y2);
    void drawNode(QPainter &painter);
    int center_x;
    int center_y;
    int r;
    bool flag;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *);

};
#endif // MAINWINDOW_H
