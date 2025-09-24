#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <iomanip>

#include <algorithm>
#include <QPainter>
#include <math.h>

using std::setw;
using std::string;
using std::cout;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    center_x = 400;
    center_y = 400;
    r = 300;
    flag = false;
    maximum = 0;
    step = 0;
    path = false;
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    //initialization
    path = false;
    maximum = 0;
    step = 0;
    flag = false;
    node.clear();
    kruskalOrder.clear();
    kruskalOrder.push_back(vector<int> ({0, 0, 0}));

    node.push_back('0');
    for(int i = 0; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j = 0; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cost[i][j] = 0;
        }
    }



    QString qstr = ui->lineEdit->text();
    string str = qstr.toStdString();

    for(int i = 1; i <= str.length(); i++){
        node.push_back(str[i-1]);
    }
    maximum = node.size() - 1;

    qstr = ui->lineEdit_2->text();
    str = qstr.toStdString();

    //(A,B,2) (A,C,4) version
//    int pos = 0;
//    int start = 0, end = 0;
//    string substr, temp;
//    while((pos = str.find(" ")) != string::npos){
//        substr = str.substr(0, pos-1);
//        cout << substr << std::endl;
//        start = findIndex(substr[1]);
//        end = findIndex(substr[3]);
//        //cout << start << " " << end << std::endl;
//        temp = substr.substr(5);
//        cout << "temp: " << stoi(temp) << std::endl;
//        cost[start][end] = cost[end][start] = stoi(temp);

//        str = str.substr(pos+1);
//        //cout << str << std::endl;
//    }
//    //substr = str.substr(0, pos-1);
//    cout << str << std::endl;
//    start = findIndex(str[1]);
//    end = findIndex(str[3]);
//    temp = str.substr(5);
//    cout << "temp: " << stoi(temp)<< std::endl;
//    cost[start][end] = cost[end][start] = stoi(temp);

    // A5B,A6C, version
    int pos = 0, len = 0;
    int start = 0, end = 0;
    string substr, temp;
    while((pos = str.find(",")) != string::npos){
        substr = str.substr(0, pos);
        cout << substr << std::endl;
        start = findIndex(substr[0]);
        len = substr.length();
        end = findIndex(substr[len - 1]);
        //cout << start << " " << end << std::endl;
        temp = substr.substr(1, len - 2);
        cout << "temp: " << stoi(temp) << std::endl;
        cost[start][end] = cost[end][start] = stoi(temp);

        str = str.substr(pos+1);
        //cout << str << std::endl;
    }
    //substr = str.substr(0, pos-1);
    cout << str << std::endl;
    start = findIndex(str[0]);
    len = str.length();
    end = findIndex(str[len - 1]);
    temp = str.substr(1, len - 2);
    cout << "temp: " << stoi(temp)<< std::endl;
    cost[start][end] = cost[end][start] = stoi(temp);



    //TEST
    for(int i =1 ; i <= maximum; i++){
        for(int j =1 ; j <= maximum; j++){
            cout << std::setw(4)<< cost[i][j] << " ";
        }
        cout << std::endl;
    }


    //TEST
    cout << "Maximum: " << maximum << std::endl;
    for(auto it = node.begin(); it != node.end(); it++){
        cout << *it << " " ;
    }
    cout << std::endl;

    kruskalMST();

    for(auto iy = kruskalOrder.begin(); iy != kruskalOrder.end(); iy++){
        for(auto ix = iy->begin(); ix != iy->end(); ix++){
            cout << *ix << " ";
        }
        cout << std::endl;
    }
    cout << std::endl;

    flag = true;
    this->update();

}

void MainWindow::kruskalMST(){

    Graph g(maximum);

    for(int i = 1 ; i <= maximum; i++){
        for(int j = i ; j <= maximum; j++){
            if(cost[i][j]){
                g.addEdge(i, j, cost[i][j]);
                //cout << cost[i][j] << " ";
            }
        }
    }
    //cout << "here!" << std::endl;
    g.kruskals_mst(kruskalOrder);

    for(auto iy = kruskalOrder.begin(); iy != kruskalOrder.end(); iy++){
        for(auto ix = iy->begin(); ix != iy->end(); ix++){
            cout << *ix << " ";
        }
        cout << std::endl;
    }
    cout << "here " << kruskalOrder.size() <<std::endl;
}

void MainWindow::drawNode(QPainter &painter){

    //DrawLine
    double arc =  2 * M_PI / maximum;
    for(int i = 1; i <= maximum; i++){
        double x = r*cos(arc * (i - 1));
        double y = r*sin(arc * (i - 1));
        for(int j = i; j <= maximum; j++){
            if(cost[i][j]){
                //cout << "i,j: " << i << " " << j << std::endl;
                painter.drawText(center_x + (x + r*cos(arc * (j - i + (i - 1)))) / 2, center_y - (y + r*sin(arc * (j - i + (i - 1)))) / 2 - 5, QString::number(cost[i][j]));
                painter.drawLine(center_x + x, center_y - y, center_x + r*cos(arc * (j - i + (i - 1))), center_y - r*sin(arc * (j - i + (i - 1))));
            }
        }
    }
    //DrawRedLine
    if(step){
        //cout << "step: " <<step << std::endl;
        for(int a = 1; a <= step; a++){
            //cout << "PrimOrder: "<<primOrder[a][0] << " " << primOrder[a][1] << std::endl;
            int i = kruskalOrder[a][0];
            int j = kruskalOrder[a][1];
            double x = r*cos(arc * (i - 1));
            double y = r*sin(arc * (i - 1));
            painter.setPen(Qt::red);
            //painter.drawText(center_x + (x + r*cos(arc * (j - i + (i - 1)))) / 2, center_y - (y + r*sin(arc * (j - i + (i - 1)))) / 2 - 5, QString::number(cost[i][j]));
            painter.drawLine(center_x + x, center_y - y, center_x + r*cos(arc * (j - i + (i - 1))), center_y - r*sin(arc * (j - i + (i - 1))));
        }
    }

    //DrawEllipse
    for(int i = 1; i <= maximum; i++){

        char temp = node.at(i);
        QString qstr = QString::fromStdString(string(1,temp));
        //painter.drawEllipse(center_x-r,center_y-r,600,600);
        double x = r*cos(arc * (i - 1));
        double y = r*sin(arc * (i - 1));
        painter.setBrush(Qt::white);
        painter.setPen(Qt::black);
        painter.drawEllipse(center_x + x - 10, center_y - y - 10, 20, 20);
        painter.drawText(center_x + x - 5, center_y - y + 5, qstr);

    }

    if (path){
        int temp1, temp2;
        string str = "";
        for(int i = 1; i < maximum; i++){
            temp1 = kruskalOrder[i][0];
            temp2 = kruskalOrder[i][1];
            if(node.at(temp1) < node.at(temp2))
            //if(temp1 < temp2)
                str = str + node.at(temp1) + node.at(temp2) + "⭢";
            else
                str = str + node.at(temp2) + node.at(temp1) + "⭢";
        }
        str = str.substr(0, str.length()-3);
        QString qstr = QString::fromStdString(str);
        painter.drawText(100, 725, qstr);
    }

}

int MainWindow::findIndex(char ch){
    for(int i = 1; i < node.size(); i++){
        if(node.at(i) == ch){
            return i;
        }
    }
    return -1;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    if(flag){
        drawNode(painter);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    step++;
    if(step >= maximum) step = maximum - 1;
    this->update();
}


void MainWindow::on_pushButton_3_clicked()
{
    path = true;
    this->update();
}

