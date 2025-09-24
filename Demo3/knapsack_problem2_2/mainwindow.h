#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <map>
#include <string>
using std::vector;
using std::map;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct obj{
    int price;
    int weight;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    map<string,obj> item;
    vector<string> name;    //fish
    int M;
    int N;
    vector<int> value;  //price
    vector<int> size;   //weight
};
#endif // MAINWINDOW_H
