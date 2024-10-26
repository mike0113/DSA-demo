#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <iostream>

using namespace::std;

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
    struct store {
        char color;
        int num;
    };
    //start
    QString q_str = ui-> lineEdit -> text();    //從圖形化介面取得資料
    string c_str = q_str.toStdString() +",";    //QString to string
    string del = ",", sub;   //分隔符號 子字串
    int end, start = 0, len = 0, count = 0;
    store show[256];

    //讀入資料
    while((end = c_str.find(del, start))!= string::npos){   //分隔符的位置 = 字串.find (分隔符號, 初始位置);
        len = end - start;
        sub = c_str.substr(start, len);    //切割的子字串 = 字串.substr(初始位置, 長度);
        show[count].color = sub[0];     //字串第一個字為英文字母
        sub = sub.substr(1);  //.substr(初始位置);
        show[count].num = stoi(sub);    //數字 = stoi(字串);    string to integer
        start = end+1;      //指到下一個新的字首
        //cout << show[count].color << " " << show[count].num << "\n";
        count++;
    }
    //ui -> label -> setText(q_str);
    c_str.clear();  //清空 string  c_str 資料
    int flag, i;

    //存入原始資料
    for(i = 0; i < count-1; i++){
        //cout << show[i].color << show[i].num << ",";
        c_str += show[i].color + to_string(show[i].num) +",";   //to_string() 數字轉字串
    }
    //cout << show[i].color << show[i].num << "\n";
    c_str += show[i].color + to_string(show[i].num) +"\n";  //寫入初始資料
    store tmp;
    int out;

        //bubble sort
        do{
            tmp = show[0];
            flag = 0;
            for(int j = 1; j < count; j++){
                out = 0;
                if(show[j].color != show[j-1].color){   //英文字不同
                    if(show[j].color == 'R'){
                        tmp = show[j-1];
                        show[j-1] = show[j];
                        show[j] = tmp;
                        flag = 1;   //有交換才繼續迴圈 (做一輪)
                        out = 1;    //有交換才輸出 (做一次)
                    }else if(show[j].color == 'B' && show[j-1].color != 'R'){
                        tmp = show[j-1];
                        show[j-1] = show[j];
                        show[j] = tmp;
                        flag = 1;
                        out = 1;
                    }else if(show[j].color == 'G' && show[j-1].color != 'R' && show[j-1].color != 'B'){
                        tmp = show[j-1];
                        show[j-1] = show[j];
                        show[j] = tmp;
                        flag = 1;
                        out = 1;
                    }else if(show[j].color == 'Y' && show[j-1].color != 'R' && show[j-1].color != 'B' && show[j-1].color != 'G'){
                        tmp = show[j-1];
                        show[j-1] = show[j];
                        show[j] = tmp;
                        flag = 1;
                        out = 1;
                    }
                }else if(show[j-1].color == show[j].color){  //英文字相同
                    if(show[j].num > show[j-1].num){    //數字不同
                        tmp = show[j-1];
                        show[j-1] = show[j];
                        show[j] = tmp;
                        flag = 1;
                        out = 1;
                    }
                }
                //輸出
                if(out == 1){   //有交換才輸出
                    for(i = 0; i < count-1; i++){
                        //cout << show[i].color << show[i].num << ",";
                        c_str += show[i].color + to_string(show[i].num) +",";
                    }
                    //cout << show[i].color << show[i].num << "\n";
                    c_str += show[i].color + to_string(show[i].num) +"\n";
                }
            }
        }while(flag == 1);
        QString fin = QString::fromStdString(c_str);    //string to QString
        ui -> label -> setText(fin);    //輸出到圖形化介面

    //ui -> label -> setText(str);
}
