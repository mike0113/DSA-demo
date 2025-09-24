#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TreeNode.h"
#include <QList>
#include <QLabel>

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
    QString in_s;
    QString af_s;
    char *pr;
    char *in;
    char *af;
    QList<QLabel*> label_array;
    TreeNode *root;
    void FindAForder(char* inorder, char* preorder, int length, char* aforder, int &dis);

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
