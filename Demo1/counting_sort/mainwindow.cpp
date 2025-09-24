#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <iostream>
#include <QTableWidget>
using namespace std;

#define KEY 101     //key的數量

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setHidden(true);      //隱藏水平標頭
    ui->tableWidget->verticalHeader()->setHidden(true);     //隱藏垂直標頭
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);   //表格寬度隨著資料大小改變
    for(int x = 0; x < 25; x++)
        ui->tableWidget->setColumnHidden(x, true);    //隱藏所有欄

    for(int y = 0; y < 26; y++)     //多一列 因為初始資料
        ui->tableWidget->setRowHidden(y, true);     //隱藏所有列(可只做一)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString q_str = ui -> lineEdit -> text();   //從圖形化介面取得資料
    string c_str = q_str.toStdString() + ',';   //QString to string
    string del = ",", sub;  //分隔符號 子字串
    int end, start = 0, len = 0, sum = 0;
    int show[256];

    //切割字串存入陣列
    while((end = c_str.find(del, start)) != string::npos){      //分隔符的位置 = 字串.find (分隔符號, 初始位置);
        len = end - start;
        sub = c_str.substr(start, len);     //切割的子字串 = 字串.substr(初始位置, 長度);
        show[sum] = stoi(sub);    //數字 = stoi(字串);    string to integer
        start = end + 1;      //指到下一個新的字首
        //cout << show[sum] << "\n";
        sum++;
    }

    //輸出初始資料
    for(int i = 0; i < sum; i++){
        c_str = "?";
        q_str = QString::fromStdString(c_str);
        ui->tableWidget->setItem( 0, i, new QTableWidgetItem(q_str));   //setItem( row, column, new QTableWidgetItem(字串));
    }

    //顯示全部欄位
    for(int x = 0; x < 25; x++)     //顯示全部欄
        ui->tableWidget->setColumnHidden(x, false);
    for(int y = 0; y < 26; y++)     //顯示全部列
        ui->tableWidget->setRowHidden(y, false);


    //counting sort
    int i, j, z = 1;
    int count[KEY], tmp[KEY];

    for(j = 0; j < KEY; j++){   //初始化
        count[j] = 0;   //記數陣列設為0
        tmp[j] = -1;    //輸出陣列設為-1
    }
    for(i = 0; i < sum; i++)    //計算每種key出現的次數
        count[show[i]]++;
    for(j = 1; j < KEY; j++)    //決定每種key最後的位置Index(多1)
        count[j] = count[j-1] + count[j];
    for(i = sum-1 ; i >= 0; i--){   //由後往前複製到tmp裡的每種key最後的位置(減1)
        tmp[count[show[i]]-1] = show[i];    //(減1)因為最後位置的索引值(多1)
        count[show[i]]--;   //每種key最後的位置往前一格

        //輸出資料
        for(j = 0; j < sum; j++){   //欄數
            if(tmp[j] == -1) c_str = "?";       //-1代表未排序
            else c_str = to_string(tmp[j]);     //integer to string

            q_str = QString::fromStdString(c_str);      //string to QString
            ui->tableWidget->setItem( z, j, new QTableWidgetItem(q_str));
            //cout << tmp[j] <<" ";
        }
        z++;    //列數
        //cout << "\n";

    }
    /*for(i = 1; i <= sum; i++)   //複製回原先排序的show陣列
        show[i] = tmp[i];*/

    //隱藏未使用到的欄位
    for(int x = sum; x < 25; x++)
        ui->tableWidget->setColumnHidden(x, true);
    for(int y = sum+1; y < 26; y++)
        ui->tableWidget->setRowHidden(y, true);
}

