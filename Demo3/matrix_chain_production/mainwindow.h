#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <vector>
#include <iostream>
#include <QMainWindow>

using std::string;
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
    string PrintOptimalParens(int **, int , int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int N;
    vector<char> matrix;
    vector<int> size;
};
#endif // MAINWINDOW_H
