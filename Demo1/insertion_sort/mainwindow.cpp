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
    class store{
    public:
        char color;
        int eleindex;
        int num;
    };

    QString q_str = ui -> lineEdit -> text();   //從圖形化介面取得資料
    string c_str = q_str.toStdString() + ',';   //QString to string
    string del = ",", sub;  //分隔符號 子字串
    int end, start = 0, len = 0, count = 0;
    store show[256];

    while((end = c_str.find(del, start)) != string::npos){
        len = end - start;
        sub = c_str.substr(start, len);     //切割的子字串 = 字串.substr(初始位置, 長度);
        show[count].color = sub[0];     //字串第一個字為英文字母
        if(sub[0]=='R') show[count].eleindex = 5;   //依據字母大小給定數字大小的值
        else if(sub[0]=='B') show[count].eleindex = 4;
        else if(sub[0]=='G') show[count].eleindex = 3;
        else if(sub[0]=='Y') show[count].eleindex = 2;
        else if(sub[0]=='P') show[count].eleindex = 1;
        sub = sub.substr(1);    //.substr(初始位置);
        show[count].num = stoi(sub);    //數字 = stoi(字串);    string to integer
        start = end + 1;      //指到下一個新的字首
        //cout << show[count].color << show[count].num <<" "<< show[count].eleindex<<"\n";
        count++;
    }
    //c_str.clear();
    len = c_str.length();
    c_str = c_str.substr(0, len-1) + "\n";  //寫入初始資料
    //cout << c_str;
    int i, j;
    store val;

    //insertion sort
    //cout << "count:" << count ;
    for(i = 1; i < count; i++){
        val = show[i];  //未排序的第一個數值 從第二個數開始往後
        j = i;

        //if(show[j-1].eleindex != val.eleindex){
        while(show[j-1].eleindex < val.eleindex && show[j-1].eleindex != val.eleindex){     //先比英文字母的大小
            show[j] = show[j-1];    //已排序資料往後放一格
            j--;
        }
        //}

        //if(show[j-1].eleindex == val.eleindex){
        while(show[j-1].num < val.num && show[j-1].eleindex == val.eleindex){       //再比數字大小
            show[j] = show[j-1];    //已排序資料往後放一格
            j--;
        }
        //}
        show[j] = val;      //未排序的第一個數值放入已比較過的排序位置

        int x;
        if (j != i){
            for( x = 0; x < count-1; x++){
                c_str += show[x].color + to_string(show[x].num) + ",";
                //cout << show[x].color << show[x].num << ",";
            }
            c_str += show[x].color + to_string(show[x].num) + "\n";
            //cout << show[x].color << show[x].num << "\n";
        }
    }

    QString fin = QString::fromStdString(c_str);    //string to QString
    ui -> label -> setText(fin);    //輸出到圖形化介面

}




