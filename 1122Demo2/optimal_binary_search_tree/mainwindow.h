#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

#include "TreeNode.h"
#include <QList>
#include <QLabel>

using std::vector;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct point
{
    int x;
    int y;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void print_Tree(QPainter &painter, TreeNode* root, int type, int x, int y);
    void erase(QPainter &painter);
    QList<QLabel*> label_array;
    TreeNode *root;


    void printTable();
    void drawTree(int, int, int, TreeNode*);
    vector<char> key;
    vector<int> freq;
    int cost[52][52];
    char best[52][52];
    int N;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool flag;
    bool clear;
    int x;
    int y;

protected:
    void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
