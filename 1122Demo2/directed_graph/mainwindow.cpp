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

    center_x = 750;
    center_y = 400;
    r = 300;
    flag = false;
    maximum = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //initialization
    maximum = 0;
    flag = false;
    node.clear();

    node.push_back('0');
    for(int i = 0; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j = 0; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cost[i][j] = 0;
        }
    }
    //Input Node
    QString qstr = ui->lineEdit->text();
    string str = qstr.toStdString();

    for(int i = 1; i <= str.length(); i++){
        node.push_back(str[i-1]);
    }
    maximum = node.size() - 1;

    qstr = ui->lineEdit_2->text();
    str = qstr.toStdString();


    //Input Edge
    int pos = 0;
    int start = 0, end = 0;
    string substr, temp;
    while((pos = str.find(" ")) != string::npos){
        substr = str.substr(0, pos-1);
        cout << substr << std::endl;
        start = findIndex(substr[1]);
        end = findIndex(substr[3]);
        //cout << start << " " << end << std::endl;
        temp = substr.substr(5);
        cout << "temp: " << stoi(temp) << std::endl;
        cost[start][end] = stoi(temp);

        str = str.substr(pos+1);
        //cout << str << std::endl;
    }

    cout << str << std::endl;
    start = findIndex(str[1]);
    end = findIndex(str[3]);
    temp = str.substr(5);
    cout << "temp: " << stoi(temp)<< std::endl;
    cost[start][end] = stoi(temp);

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

    str = "<table border='1' cellpadding='5' style='font-size:14px' width=600> <tr> <td> </td>" ;
    for(int i = 1; i <= maximum; i++){
        str = str + "<td>" + node.at(i) + "</td>";
    }
    str = str + "</tr>";

    for(int i = 1; i <= maximum; i++){
        str = str + "<tr> <td>" + node.at(i) + "</td>";
        for(int j = 1; j <= maximum; j++){
            str = str + "<td>" + std::to_string(cost[i][j]) + "</td>";
        }
        str += "</tr>";
    }


    qstr = QString::fromStdString(str);
    ui->textBrowser->setText(qstr);

    flag = true;
    this->update();
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
                painter.setPen(QPen(Qt::magenta,2));
                double start_x = center_x + x;
                double start_y = center_y - y - 3;
                double end_x = center_x + r*cos(arc * (j - i + (i - 1)));
                double end_y = center_y - r*sin(arc * (j - i + (i - 1))) - 3;

                painter.drawText( (start_x + end_x) / 2, (start_y + end_y) / 2 - 10, QString::number(cost[i][j]));
                painter.drawLine(start_x, start_y, end_x , end_y);
                //painter.drawText(center_x + (x + r*cos(arc * (j - i + (i - 1)))) / 2, center_y - (y + r*sin(arc * (j - i + (i - 1)))) / 2 + 10, QString::number(cost[i][j]));
                //painter.drawLine(center_x + x, center_y - y + 3, center_x + r*cos(arc * (j - i + (i - 1))) , center_y - r*sin(arc * (j - i + (i - 1))) + 3);
                //Arrow
                double x1, x2, y1, y2;
                calcArrow(start_x, start_y, end_x, end_y, x1, y1, x2, y2);
                painter.drawLine(end_x, end_y, x1, y1);
                painter.drawLine(end_x, end_y, x2, y2);
            }
        }
    }
    for(int i = 1; i <= maximum; i++){
        double x = r*cos(arc * (i - 1));
        double y = r*sin(arc * (i - 1));
        for(int j = 1; j <= i; j++){
            if(cost[i][j]){
                //cout << "i,j: " << i << " " << j << std::endl;
                painter.setPen(QPen(Qt::darkCyan, 2));
                double start_x = center_x + x;
                double start_y = center_y - y + 3;
                double end_x =  (center_x + r*cos(arc * (j - i + (i - 1)))) ;
                double end_y =  (center_y - r*sin(arc * (j - i + (i - 1)))) + 3;

                painter.drawText( (start_x + end_x) / 2, (start_y + end_y) / 2 + 10, QString::number(cost[i][j]));
                painter.drawLine(start_x, start_y, end_x , end_y);
                //painter.drawText(center_x + (x + r*cos(arc * (j - i + (i - 1)))) / 2, center_y - (y + r*sin(arc * (j - i + (i - 1)))) / 2 + 10, QString::number(cost[i][j]));
                //painter.drawLine(center_x + x, center_y - y + 3, center_x + r*cos(arc * (j - i + (i - 1))) , center_y - r*sin(arc * (j - i + (i - 1))) + 3);
                //Arrow
                double x1, x2, y1, y2;
                calcArrow(start_x, start_y, end_x, end_y, x1, y1, x2, y2);
                painter.drawLine(end_x, end_y, x1, y1);
                painter.drawLine(end_x, end_y, x2, y2);

            }
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
}

int MainWindow::findIndex(char ch){
    for(int i = 1; i < node.size(); i++){
        if(node.at(i) == ch){
            return i;
        }
    }
    return -1;
}

void MainWindow::calcArrow(double start_x, double start_y, double end_x, double end_y, double &x1, double &y1, double &x2, double &y2){
    double arrowLength = 20;
    double arrowDegrees = 0.5;

    double angle = atan2(end_y - start_y, end_x - start_x) + M_PI;

    x1 = end_x + arrowLength * cos(angle - arrowDegrees);
    y1 = end_y + arrowLength * sin(angle - arrowDegrees);

    x2 = end_x + arrowLength * cos(angle + arrowDegrees);
    y2 = end_y + arrowLength * sin(angle + arrowDegrees);
}


void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    if(flag){
        drawNode(painter);
    }
}

