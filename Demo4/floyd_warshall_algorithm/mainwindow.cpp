#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

using std::setw;
using std::cout;
using std::endl;
using std::max;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    maximum = 0;
    for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 1000;
            pass_by[i][j] = '0';
        }
    }

    QString qstr = ui->lineEdit->text();
    string str = qstr.toStdString();


    //(A,B,2) (A,C,4) version
//    int pos = 0;
//    int start = 0, end = 0;
//    string substr, temp;
//    while((pos = str.find(" ")) != string::npos){
//        substr = str.substr(0, pos-1);
//        cout << substr << std::endl;    //cout
//        //substr
//        start = substr[1] - 'A' + 1;
//        end = substr[3] - 'A' + 1;
//        if(max(start, end) > maximum)   //最大的字母
//            maximum = max(start, end);
//        temp = substr.substr(5);
//        cout << "temp: " << stoi(temp) << std::endl;    //cout
//        cost[start][end] = cost[end][start] = stoi(temp);

//        str = str.substr(pos+1);
//    }
//    //substr = str.substr(0, pos);
//    cout << str << std::endl;   //cout
//    start = str[1] - 'A' + 1;
//    end = str[3] - 'A' + 1;
//    if(max(start, end) > maximum)   //最大的字母
//        maximum = max(start, end);
//    temp = str.substr(5);
//    cout << "temp: " << stoi(temp) << std::endl << std::endl;   //cout
//    cost[start][end] = cost[end][start] = stoi(temp);


    //A B 7,B C 10 version
    int pos = 0;
    int start = 0, end = 0;
    string substr, temp;
    while((pos = str.find(",")) != string::npos){
        substr = str.substr(0, pos);
        cout << substr << std::endl;  //cout
        //substr
        start = substr[0] - 'A' + 1;
        end = substr[2] - 'A' + 1;
        if(max(start, end) > maximum)   //最大的字母
            maximum = max(start, end);
        temp = substr.substr(4);
        cout << "temp: " << stoi(temp) << std::endl;    //cout
        cost[start][end] = cost[end][start] = stoi(temp);

        str = str.substr(pos+1);    //注意逗號後是否有空格
    }
    cout << str << std::endl;  //cout
    start = str[0] - 'A' + 1;
    end = str[2] - 'A' + 1;
    if(max(start, end) > maximum)   //最大的字母
        maximum = max(start, end);
    temp = str.substr(4);
    cout << "temp: " << stoi(temp) << std::endl << std::endl;    //cout
    cost[start][end] = cost[end][start] = stoi(temp);


    //Initialization
    for(int i =1; i <= maximum; i++){
        for(int j =1; j <= maximum; j++){
            pass_by[i][j] = char('A' + j - 1);
        }
    }

    /*for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cout << std::setw(4)<< cost[i][j] << " ";
        }
        cout << std::endl;
    }*/

    /*for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cout << std::setw(4)<< pass_by[i][j] << " ";
        }
        cout << std::endl;
    }*/

    string title = "<tr><td> </td>";
    for(int i = 1; i <= maximum; i++){
        char node = 'A' + i - 1;
        title = title + "<td>" + string(1, node) + "</td>";
    }
    title += "</tr>";

    //Initial Print
    char node = ' ';
    str ="<div style='font-size:14px'>Initial</div> <table border='1' cellpadding='5' style='font-size:14px' width=90%>" + title;
    for(int i =1 ; i <= maximum; i++){
        node = 'A' + i - 1;
        str = str + "<tr> <td>" + string(1, node) ;
        for(int j =1 ; j <= maximum; j++){
            //cout << std::setw(4)<< cost[i][j] << " ";
            str = str + "<td>" + std::to_string(cost[i][j]) + "</td>";
        }
        //cout << std::endl;
        str = str + "</tr>";
    }
    str = str + "</table>";
    //cout << std::endl;



    //floyd-warshall
    int tmp = 0;
    for(int j = 1; j <= maximum; j++){  //j為目前要檢查的第二站
        for(int i = 1; i <= maximum; i++){  //i為起點
            for(int k = 1; k <= maximum; k++){  //k為終點
                if(j != i && j != k){
                    tmp = cost[i][j] + cost[j][k];  // (由 i...經 j...到 k) 的距離
                    if(tmp < cost[i][k]){
                        cost[i][k] = tmp;
                        pass_by[i][k] = pass_by[i][j];  //第二站
                    }
                }
            }
        }

        //Including Print
        str = str + "<div style='font-size:14px'>Including " + string(1, 'A' + j - 1) + "</div> <table border='1' cellpadding='5' style='font-size:14px' width=90%>" + title;
        for(int i =1 ; i <= maximum; i++){
            node = 'A' + i - 1;
            str = str + "<tr> <td>" + string(1, node) ;
            for(int j =1 ; j <= maximum; j++){
                //cout << std::setw(4)<< cost[i][j] << " ";
                str = str + "<td>" + std::to_string(cost[i][j]) + "</td>";
            }
            //cout << std::endl;
            str = str + "</tr>";
        }
        str = str + "</table>";

    }


    /*for(int i =1 ; i <= maximum; i++){
        for(int j =1 ; j <= maximum; j++){
            cout << std::setw(4)<< cost[i][j] << " ";
        }
        cout << std::endl;
    }
    cout << std::endl;

    for(int i = 1 ; i <= maximum; i++){
        for(int j = 1 ; j <= maximum; j++){
            cout << std::setw(4)<< pass_by[i][j] << " ";
        }
        cout << std::endl;
    }*/

    qstr = QString::fromStdString(str);
    ui->textBrowser->setText(qstr);


}

