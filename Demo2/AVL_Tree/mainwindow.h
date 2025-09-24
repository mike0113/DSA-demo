#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "treenode.h"
#include <QList>
#include <QLabel>
#include <vector>

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
    QString  pr_s;
    char* pr;
    QList<QLabel*> label_array;
    TreeNode *root;
    QVector<int> lst;


private:
    Ui::MainWindow *ui;
    bool flag;
    bool clear;
    int x;
    int y;

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
