#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::string;
using std::cout;
using std::max;
using std::min;

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

    //Initialization
    length.clear();
    pass_by.clear();
    visited.clear();
    begin =' ';
    maximum = 0;
    length.push_back(1000);
    visited.push_back(1);
    pass_by.push_back('0');
    stop = false;

    for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = 999;
        }
    }


    QString qstr = ui->lineEdit_2->text();
    string str = qstr.toStdString();

    //A B 7,B C 10 version
    int pos = 0;
    int start = 0, end = 0;
    string substr, temp;
    while((pos = str.find(",")) != string::npos){
        substr = str.substr(0, pos);
        //cout << substr << std::endl;
        //substr
        start = substr[0] - 'A' + 1;
        end = substr[2] - 'A' + 1;
        if(max(start, end) > maximum)   //最大的字母
            maximum = max(start, end);
        //cout << start << " " << end << std::endl;
        temp = substr.substr(4);
        //cout << temp << std::endl;
        cost[start][end] = cost[end][start] = stoi(temp);

        str = str.substr(pos+1);
        //cout << str << std::endl;
    }
    //substr = str.substr(0, pos);
    start = str[0] - 'A' + 1;
    end = str[2] - 'A' + 1;
    if(max(start, end) > maximum)   //最大的字母
        maximum = max(start, end);
    temp = str.substr(4);
    cout << temp << std::endl;
    cost[start][end] = cost[end][start] = stoi(temp);


    //(A,B,2) (A,C,4) version
//    int pos = 0;
//    int start = 0, end = 0;
//    string substr, temp;
//    while((pos = str.find(" ")) != string::npos){
//        substr = str.substr(0, pos-1);
//        cout << substr << std::endl;
//        //substr
//        start = substr[1] - 'A' + 1;
//        end = substr[3] - 'A' + 1;
//        if(max(start, end) > maximum)   //最大的字母
//            maximum = max(start, end);
//        //cout << start << " " << end << std::endl;
//        temp = substr.substr(5);
//        //cout << temp << std::endl;
//        cost[start][end] = cost[end][start] = stoi(temp);

//        str = str.substr(pos+1);
//        //cout << str << std::endl;
//    }
//    //substr = str.substr(0, pos-1);
//    cout << str << std::endl;
//    start = str[1] - 'A' + 1;
//    end = str[3] - 'A' + 1;
//    if(max(start, end) > maximum)   //最大的字母
//        maximum = max(start, end);
//    temp = str.substr(5);
//    //cout << "temp: " << temp  << " " << stoi(temp)<< std::endl;
//    cost[start][end] = cost[end][start] = stoi(temp);



    /*for(int i =0 ; i < sizeof(cost)/sizeof(cost[0]); i++){
        for(int j =0 ; j < sizeof(cost[0])/sizeof(cost[0][0]); j++){
            cout << std::setw(4)<< cost[i][j] << " ";
        }
        cout << std::endl;
    }*/

    qstr = ui->lineEdit->text();
    str = qstr.toStdString();
    begin = *str.c_str();   //開始位置
    for(int i = 1; i <= maximum; i++){
        pass_by.push_back(begin);
        if (i == (begin - 'A' +1))
            visited.push_back(1);
        else
            visited.push_back(0);
        length.push_back(cost[begin - 'A' +1][i]);

    }

    string title = "<tr><td> </td>";
    for(int i = 0; i < maximum; i++){
        char node = 'A' + i;
        title = title + "<td>" + string(1, node) + "</td>";
    }
    title += "</tr>";

    //Print
    str ="<div style='font-size:14px'>Initial</div> <table border='1' cellpadding='5' style='font-size:14px' width=600>" + title + "<tr> <td>" + string(1, begin) + "</td>";
    for(int i =1 ; i < length.size(); i++){
        //cout << std::setw(4)<< length[i] << " " << visited[i] << " " << pass_by[i];
        //cout << std::endl;
        str = str + " <td> " + std::to_string(length[i]) + " </td> ";
    }
    str += "</tr> </table> ";
    //cout << std::endl;


    //dijkstra's algorithm
    int k = 0;  //index
    char node;
    while(true){
        stop = true;
        k = 0;
        for(int i = 1; i <= maximum; i++ ){ //是否還有node還沒被visited
            if(visited[i] == false){
                stop = false;
                k = length[k] > length[i] ? i : k;  //k(index)為還沒被拜訪過的最小者
            }
        }
        if(stop == true) break;
        visited[k] = true;

        for(int j = 1; j <= maximum; j++){
            //Triple operation
            if(length[j] > length[k] + cost[k][j]){
                length[j] = length[k] + cost[k][j];
                pass_by[j] = k + 'A' - 1;
            }
        }

        //Print
        node = 'A' + k - 1;
        str = str + "<div style='font-size:14px'> Including " + string(1, node) + "</div> <table border='1' cellpadding='5' style='font-size:14px' width=600>" + title + "<tr> <td>" + string(1, begin) + "</td>";
        for(int i =1 ; i < length.size(); i++){
            //cout << std::setw(4)<< length[i] << " " << visited[i] << " " << pass_by[i];
            //cout << std::endl;
            str = str + " <td> " + std::to_string(length[i]) + " </td> ";
        }
        str += "</tr> </table> ";
        //cout << std::endl;

    }

    qstr = QString::fromStdString(str);
    ui->textBrowser->setText(qstr);



}

