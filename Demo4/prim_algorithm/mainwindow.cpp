#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include <QPainter>
#include <QRect>
#include <math.h>

using std::max;
using std::setw;
using std::cout;
using std::string;

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
    //QPainter painter(this);

    path =false;
    maximum = 0;
    step = 0;
    flag = false;
    node.clear();
    key.clear();
    mstSet.clear();
    parent.clear();
    primOrder.clear();
    node.push_back('0');
    begin = 0;

    for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cost[i][j] = 0;
        }
    }



    QString qstr = ui->lineEdit->text();
    string str = qstr.toStdString();

    for(int i = 1; i <= str.length(); i++){
        node.push_back(str[i-1]);
    }
    maximum = node.size() - 1;

    /*for(auto it = node.begin(); it != node.end(); it++){
        cout << *it << " ";
    }*/

    qstr = ui->lineEdit_3->text();
    str = qstr.toStdString();

    char b = *str.c_str();
    for(int i = 1; i <= node.size(); i++){
        if (b == node.at(i)){
            begin = i;
            break;
        }
    }
    cout << "Begin: "<< begin << std::endl;

    qstr = ui->lineEdit_2->text();
    str = qstr.toStdString();

    //(A,B,2) (A,C,4) version
    int pos = 0;
    int start = 0, end = 0;
    string substr, temp;
    while((pos = str.find(" ")) != string::npos){
        substr = str.substr(0, pos-1);
        cout << substr << std::endl;
        //substr
        start = findIndex(substr[1]);
        end = findIndex(substr[3]);
        //cout << start << " " << end << std::endl;
        //cout << "strat, end:" << start << " " << end << std::endl;
        temp = substr.substr(5);
        cout << "temp: " << stoi(temp) << std::endl;
        cost[start][end] = cost[end][start] = stoi(temp);

        str = str.substr(pos+1);
        //cout << str << std::endl;
    }
    //substr = str.substr(0, pos-1);
    cout << str << std::endl;
    start = findIndex(str[1]);
    end = findIndex(str[3]);
    //cout << "strat, end:" << start << " " << end << std::endl;
    temp = str.substr(5);
    cout << "temp: " << stoi(temp)<< std::endl;
    cost[start][end] = cost[end][start] = stoi(temp);

    //A5B,A6C, version
//    int pos = 0, len = 0;
//    int start = 0, end = 0;
//    string substr, temp;
//    while((pos = str.find(",")) != string::npos){
//        substr = str.substr(0, pos);
//        cout << substr << std::endl;
//        start = findIndex(substr[0]);
//        len = substr.length();
//        end = findIndex(substr[len - 1]);
//        //cout << start << " " << end << std::endl;
//        temp = substr.substr(1, len - 2);
//        cout << "temp: " << stoi(temp) << std::endl;
//        cost[start][end] = cost[end][start] = stoi(temp);

//        str = str.substr(pos+1);
//        //cout << str << std::endl;
//    }
//    //substr = str.substr(0, pos-1);
//    cout << str << std::endl;
//    start = findIndex(str[0]);
//    len = str.length();
//    end = findIndex(str[len - 1]);
//    temp = str.substr(1, len - 2);
//    cout << "temp: " << stoi(temp)<< std::endl;
//    cost[start][end] = cost[end][start] = stoi(temp);

//    for(int i =1 ; i <= maximum; i++){
//        for(int j =1 ; j <= maximum; j++){
//            cout << std::setw(4)<< cost[i][j] << " ";
//        }
//        cout << std::endl;
//    }


    //TEST
    cout << "Maximum: " << maximum << std::endl;
    for(auto it = node.begin(); it != node.end(); it++){
        cout << *it << " " ;
    }
    cout << std::endl;

    //prim's algorithm
    primMST();
    this->update();

}

void MainWindow::primMST(){

    //int parent[V];  // Array to store constructed MST
    //int key[V]; // Key values used to pick minimum weight edge in cut
    //bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i <= maximum; i++){
        parent.push_back(0);
        key.push_back(INT_MAX);
        mstSet.push_back(false);
        cout << parent.at(i) <<" " << key.at(i) << " " << mstSet.at(i) << std::endl;
    }

    //TEST
    /*for(auto it = key.begin(); it != key.end(); it++){
        cout << *it << " ";
    }
    cout << std::endl;
    for(auto it = mstSet.begin(); it != mstSet.end(); it++){
        cout << *it << " ";
    }
    cout << std::endl;
    */

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[begin] = 0; //edge
    parent[begin] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 1; count < maximum; count++) {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        //u 接下來新加入的點(index)
        int u = minKey();   // 1, 2, 3, 4,

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 1; v <= maximum; v++)

            // cost[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if cost[u][v] is smaller than key[v]
            //  兩點有連接       v還未加入樹裡            到 v 距離較短
            if (cost[u][v] && mstSet[v] == false && cost[u][v] < key[v]){
                //u 連到 v        到 v 的距離
                parent[v] = u, key[v] = cost[u][v];
            }
        //      什麼點連到 u
        cout << parent[u] << " - " << u << " \t"
             << cost[u][parent[u]] << " \n";
        primOrder.push_back(vector<int>({parent[u], u, cost[u][parent[u]]}));

    }

    int u = minKey();
    cout << parent[u] << " - " << u << " \t"
         << cost[u][parent[u]] << " \n";
    primOrder.push_back(vector<int>({parent[u], u, cost[u][parent[u]]}));


    for(auto iy = primOrder.begin(); iy != primOrder.end(); iy++){
        for(auto ix = iy->begin(); ix != iy->end(); ix++){
            cout << *ix << " ";
        }
        cout << std::endl;
    }
    cout << std::endl;



    flag = true;
    cout << "flag true!" << std::endl;

}

int MainWindow::minKey()
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 1; v <= maximum; v++)
        if (mstSet[v] == false && key[v] < min) //點還未在樹裡 且 邊是最小的
            min = key[v], min_index = v;

    return min_index;
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
        cout << "step: " <<step << std::endl;
        for(int a = 1; a <= step; a++){
            //cout << "PrimOrder: "<<primOrder[a][0] << " " << primOrder[a][1] << std::endl;
            int i = primOrder[a][0];
            int j = primOrder[a][1];
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
    //Show path
    if(path){
        int temp;
        string str = "";
        for(int i = 0; i < maximum; i++){
            temp = primOrder[i][1];
            str = str + node.at(temp) + "⭢";
        }
        str = str.substr(0, str.length()-3);
        QString qstr = QString::fromStdString(str);
        painter.drawText(100, 725, qstr);


    }

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
    //cout << step << " Button" << std::endl;

    this->update();
}

int MainWindow::findIndex(char ch){
    for(int i = 1; i < node.size(); i++){
        if(node.at(i) == ch){
            return i;
        }
    }
    return -1;
}

void MainWindow::on_pushButton_3_clicked()
{
    path = true;
    this->update();
}

