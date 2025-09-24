
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include "TreeNode.h"
#include <QPainter>
#include <QLabel>
#include <string>
#include <QRect>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    root = NULL;
    flag = false;
    clear = false;
    x=350;
    y=150;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void FindAForder(char* inorder, char* preorder, int length, char* aforder, int &dis)
//{
//    if (length == 0)
//        return;
//    TreeNode* node = new TreeNode;//Noice that [new] should be written out.
//    node->key = *preorder;
//    int root;
//    for (root = 0; root < length; root++)
//    {
//        /*每次都是找出根結點*/
//        if (inorder[root] == *preorder)
//            break;
//    }
//    //Left
//    FindAForder(inorder, preorder + 1, root, aforder, dis);
//    //Right
//    FindAForder(inorder + root + 1, preorder + root + 1, length - (root + 1), aforder, dis);
//    aforder[dis++] = (char)node->key;
//    //cout << node->num << ' ';
//}
void MainWindow::print_Tree(QPainter &painter, TreeNode* root, int type, int x, int y)
{
    if(root==nullptr)
        return;
    else
    {
        print_Tree(painter, root->left, 1, x-80, y+80);
        QLabel *label;
        label = new QLabel(this);
        char temp[100]={};
        sprintf(temp,"%d",root->key);
        string print = temp;
        QString str = QString::fromStdString(print);
        label->setText(str);
        switch(type)
        {
        case 0:     //root
            painter.drawEllipse(x-30, y, 70, 50);
            if(root->left!=NULL)    //new
                painter.drawLine(x-10,y+50,x-40,y+80);
            if(root->right!=NULL)   //new
                painter.drawLine(x+20,y+50,x+40,y+80);
            label->setGeometry(QRect(QPoint(x, y),QSize(300, 50)));
            break;
        case 1:     //leftsubtree
            painter.drawEllipse(x+40-30, y, 70, 50);
            if(root->left!=NULL)
                painter.drawLine(x-10+25,y+42,x-10-20,y+80);
            if(root->right!=NULL)
                painter.drawLine(x+10+40,y+50,x+10+40,y+80);
            label->setGeometry(QRect(QPoint(x+40, y),QSize(300, 50)));
            break;
        case 2:     //rightsubtree
            painter.drawEllipse(x-40-30, y, 70, 50);
            if(root->left!=NULL)
                painter.drawLine(x-40+5,y+50,x-40+5,y+80);
            if(root->right!=NULL)
                painter.drawLine(x-40+25,y+44,x-40+70,y+80);
            label->setGeometry(QRect(QPoint(x-40, y),QSize(300, 50)));
            break;
        }
        label->setFont(QFont("Timers" , 12 ,  QFont::Bold));
        label->show();
        label_array.push_back(label);
        print_Tree(painter, root->right, 2, x+80, y+80);
    }

}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(flag)
        print_Tree(painter, root, 0, x, y);
}
void MainWindow::erase(QPainter &painter)
{
    painter.eraseRect(0, 0, 800, 600);
}
void MainWindow::on_pushButton_clicked()
{
    //initialize
    QPainter painter(this);
    erase(painter);
    for(int j=0;j<pr_s.size();j++)
        root=root->deleteNode(root,pr[j]);
    //ui->label_3->clear();
    //ui->label_3->show();
    this->update();
    for(int i=0;i<label_array.size();i++)
    {
        label_array[i]->clear();
        label_array[i]->show();
        label_array[i]->deleteLater();
    }
    label_array.clear();
    //    pr_s=ui->lineEdit->text();        ?

    //start
    string tmp;
    QString in_s=ui->lineEdit->text();
    string a=in_s.toStdString();
    for (int i = 0; i < (int)a.length(); i++)
    {
        if (a[i] == ',')
        {
            lst.push_back(atoi(tmp.c_str()));   //*char to int
            tmp = "";
        }
        else
        {
            tmp += a[i];
        }
    }
    lst.push_back(atoi(tmp.c_str()));
    tmp = "";

    //    string print="";
    for(int j=0;j<lst.size();j++)
    {
        root=root->insert(root,lst[j]);     //add node
        //print.push_back(af[j]);
    }
    QString find_n = ui->lineEdit_2->text();
    int find = find_n.toInt();
    string ans = root->SearchNode(root, find);
    QString ans_q= QString::fromStdString(ans);
    ui->textBrowser->setText(ans_q);

    flag= true;     //paint
    this->update();

}
