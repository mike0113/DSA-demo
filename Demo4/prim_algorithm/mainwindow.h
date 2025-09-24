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

    void primMST();
    int minKey();
    vector<int> parent;  // Array to store constructed MST
    vector<int> key; // Key values used to pick minimum weight edge in cut
    vector<bool> mstSet; // To represent set of vertices included in MST
    vector<vector<int>> primOrder;

    void drawNode(QPainter &painter);
    int center_x;
    int center_y;
    int r;

    int findIndex(char);
    int cost[51][51];
    vector<char> node;
    int maximum;
    int begin;  //index
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
