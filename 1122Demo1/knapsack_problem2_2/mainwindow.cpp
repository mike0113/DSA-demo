#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(999);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setHidden(true);      //隱藏水平標頭
    ui->tableWidget->verticalHeader()->setHidden(true);     //隱藏垂直標頭
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);   //表格寬度隨著資料大小改變
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    for(int x = 0 ; x < 999; x++)
        ui->tableWidget->setRowHidden(x, true);
    item ["Salmon"] = { 253, 153};
    item ["Tuna"] = { 530, 260};
    item ["Istiophoridae"] = { 153, 67};
    item ["Fenneropenaeus"] = { 196, 93};
    item ["Borealis"] = { 250, 152};
    item ["Adductor"] = { 87, 50};
    item ["Haliotis"] = { 191, 58};
    item ["Gratilla"] = { 33, 13};
    item ["Kuroge"] = { 431, 166};
    item ["Chionoecetes"] = { 90, 77};
    item ["Eriocheir"] = { 180, 151};
    item ["Palinuridae"] = { 100, 60};
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    for(int x = 0 ; x < 999; x++)
        ui->tableWidget->setRowHidden(x, false);

    name.clear();    //fish
    M = 0;
    N = 0;
    value.clear();  //price
    size.clear();   //weight
    QString qstr = ui->lineEdit->text();
    M = qstr.toInt();   //最大胃容量
    qstr = ui->lineEdit_2->text();
    string str = qstr.toStdString();
    //add this
    string out = str;
    int pos;
    name.push_back("");
    while((pos = str.find(",")) != string::npos){
        name.push_back(str.substr(0, pos));
        str = str.substr(pos+1);
    }
    name.push_back(str);

    //    for(auto it = item.begin(); it != item.end(); it++ ){   //it is an iterator(like pointer)
    //        std::cout << it-> second.price << std::endl;
    //        //if(item.find(*it) != )

    //        }


    size.push_back(0);  //weight
    value.push_back(0); //price
    for(auto it = name.begin(); it != name.end(); it++ ){   //it is an iterator(like pointer)
        //std::cout << *it << std::endl;
        if(item.find(*it) != item.end()){
            size.push_back(item[*it].weight);
            value.push_back(item[*it].price);
            N++;
        }

    }

    /*for(auto it = size.begin(); it != size.end(); it++ ){   //it is an iterator(like pointer)
        std::cout << *it << std::endl;
        //if(item.find(*it) != )

    }*/

    int cost[M+1] ={0};
    int best[M+1] ={0};
    //str ="";
    string used="";
    int total[N+1] ={0};
    int a = 0;    //rows
    int b = 0;    //columns
    // add this
    str = "過程（物品以 " + out + " 命名）";
    ui->tableWidget->setSpan(a,0,1,6);
    ui->tableWidget->setItem(a,0,new QTableWidgetItem(QString::fromStdString(str)));
    ui->tableWidget->item(a,0)->setForeground(Qt::blue);
    a++;


    //knapsack problem      //N = 物品數量, M = 胃容量上限
    for(int j=1; j<=N; j++){    //先考慮只有編號一海鮮，然後逐一增加海鮮
        b = 0;
        for(int i=1; i<=M; i++){    //j = 海鮮編號, i = 胃容量大小
            if((i - size[j]) >= 0 ){    //對於現在胃容量 i 的空間，放得下一個 j
                     //原來的值  < 清出一個j的空位後的價值 + j 的價值
                if(cost[i] < (cost[i - size[j]] + value[j])){   //三項操作
                    cost[i] = cost[i - size[j]] + value[j]; //size = 胃大小, value = price
                    best[i] = j;    //新答案
                }
            }
        }


        //print
        used += name[j];
        str = "僅考慮" + used;
               used += "、";
        ui->tableWidget->setSpan(a,0,1,6);
        ui->tableWidget->setItem(a,0,new QTableWidgetItem(QString::fromStdString(str)));
        ui->tableWidget->item(a,0)->setForeground(Qt::green);
        a++;    //rows
        for(int x = M; x > 0; x-=size[best[x]]){
            if (x <= 0 || best[x] == 0 ) break;
            //std::cout << x << " : " << cost[x] << " " << name[best[x]]<< std::endl;
            str = name[best[x]];
            ui->tableWidget->setItem(a,b,new QTableWidgetItem(QString::fromStdString(str)));
            b++;    //columns
            if(b == 6){
                b=0;
                a++;
            }
            if(j==N)
                total[best[x]]++;
        }
        a++;
        //ui->tableWidget->setItem(a,b,new QTableWidgetItem(QString::fromStdString(str)));
    }
    b = 0;
    str = "當胃容量大小為" + std::to_string(M) + "，拿";
           int sum=0;
    for(int x = 1; x<= N ; x++){
        if(total[x]!=0){
            str+= name[x] + " " + std::to_string(total[x]) + " 個 ";
            sum = sum + total[x] * value[x];
        }
    }
    str += "，得總價值 " + std::to_string(sum);
    ui->tableWidget->setSpan(a,0,2,6);
    ui->tableWidget->setItem(a,b,new QTableWidgetItem(QString::fromStdString(str)));
    ui->tableWidget->item(a,0)->setForeground(Qt::red);
    a+=2;

    for(int x = a ; x < 999; x++)
        ui->tableWidget->setRowHidden(x, true);
}



