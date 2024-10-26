#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <iostream>
#include <iomanip>

#include <QString>
#include "TreeNode.h"
#include <QPainter>
#include <QLabel>
#include <QRect>
#include <QThread>

#define MAX INT_MAX
using std::string;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    root = NULL;
    flag = false;
    clear = false;
    x=500;
    y=225;

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPainter painter(this);

    key.push_back(' ');
    freq.push_back(0);
    for(int i = 0; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j = 0; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cost[i][j] = 0;
            best[i][j] = '0';
        }
    }


    QString qstr = ui->lineEdit->text();
    string str = qstr.toStdString();
    for(int i = 0; i < str.length(); i++){
        key.push_back(str[i]);
    }
    str = "";
    /*for(auto it = key.begin(); it != key.end(); it++){
        str = str + *it + ' ';
        std::cout << *it << std::endl;
    }*/

    qstr = ui->lineEdit_2->text();
    str = qstr.toStdString();
    int pos = 0;
    string substr;
    while((pos = str.find(',')) != string::npos){
        substr = str.substr(0,pos);
        freq.push_back(stoi(substr));
        str = str.substr(pos+1);
        //std::cout << substr << " ";
    }
    freq.push_back(stoi(str));

    /*str ="";
    for(auto it = freq.begin(); it != freq.end(); it++){
        str = str + std::to_string(*it) + ' ';
        std::cout << std::to_string(*it) << std::endl;
    }*/

    N = key.size()-1;
    //optimal search tree
    //initialization
    for(int i = 1; i <= N; i++)
        for(int j = i+1; j < N+1; j++)
            cost[i][j] = MAX;
    for(int i = 1;i <= N; i++){
        cost[i][i] = freq[i];
        best[i][i] = key[i];
    }
    for(int i =1; i <= N+1; i++)
        cost[i][i-1] = 0;

    /*for(int i = 0; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j = 0; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            std::cout << cost[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    //start
    int tmp = 0;
    for(int j = 1; j <= N-1; j++ ){
        for(int i =1; i <= N-j; i++){
            for(int k = i; k <= i+j; k++){
                tmp = cost[i][k-1] + cost[k+1][i+j];
                if(tmp < cost[i][i+j]){
                    cost[i][i+j] = tmp;
                    best[i][i+j] = key[k];
                }
            }
            tmp = 0;
            for(int k = i; k <= i+j; k++)
                tmp = tmp + freq[k];
            cost[i][i+j] = cost[i][i+j] + tmp;
        }
    }

    /*for(int i = 0; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j = 0; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            std::cout << best[i][j] << " ";
        }
        std::cout << std::endl;
    }*/
    drawTree(1, N, 0, root);
    printTable();

    flag = true;
    this->update();

    //qstr = QString::fromStdString(str);
    //ui->label_3->setText(qstr);
}

void MainWindow::printTable(){

    string mes = "<table border='1' cellpadding='5' style='font-size:14px' width=700> <tr>";
    for(int i = 0; i <= N; i++){
        mes = mes + "<td>" +  string(1,key[i]) + "</td>" ;
    }
    for(int i = 1; i <= N; i++){
        mes = mes + "<tr> <td>" + string(1,key[i]) + "</td>";
        for(int j = 1; j <= N; j++){
            mes += "<td>";
            if(best[i][j] != '0'){
                mes = mes + std::to_string(cost[i][j]) + string(1, best[i][j]);
            }
            mes += "</td>";
        }
        mes += "</tr>";
    }
    mes += "</table>";

    QString qstr = QString::fromStdString(mes);
    ui->textBrowser->setText(qstr);

    //key.clear();
    //freq.clear();
}

//void printTree;

void MainWindow::drawTree(int i, int j, int Dir, TreeNode* node){
    if(i > j)
        return;
    else if(i == j){
        //std::cout <<"Best[i][j]: "<< best[i][j] << " ";
        //if(node != NULL)
            //std::cout<< "Node :" << node->key << std::endl;
        node = node->insert(node, Dir, best[i][j]);
        //std::cout << "Node :" << node->key << std::endl;
        return;
    }
    //std::cout <<"Best[i][j]: "<< best[i][j] << " ";
    //if(node != NULL)
    //    std::cout<< "Node :" << node->key << std::endl;
    node = node->insert(node, Dir, best[i][j]);
    if(i==1 && j == N)
        root = node;
    //std::cout << "Node :" << node->key << std::endl;
    int index = 0;
    for(int x = 1; x < key.size(); x++){
        if (best[i][j] == key[x]){
            index = x;
            break;
        }
    }
    //std::cout << "Index : "<< index << std::endl;
    drawTree(i,index-1, 1, node);
    drawTree(index+1, j, 2, node);

}

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
        sprintf(temp,"%c",root->key);
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
    if(flag){
        print_Tree(painter, root, 0, x, y);
        //this->update();
    }
}

