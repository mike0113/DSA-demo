#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <iostream>
using namespace std;

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



QString quick_sort(int left, int right, char show[], int len){

    //cout << show[1];
    QString str;
    int i, j;
    char val, tmp;
    if(right >= left){
        val = show[right];
        i = left-1;
        j = right;

        //輸出第一次
        for(int x = 0; x < len; x++){
            if(x == right)  //pivot 為 right
                str= str +"<font color=#FF0000>" + QString(show[x]) + "</font>,";
            //cout << show[x] << "* ";
            else str = str + QString(show[x])+",";
            //cout << show[x] << " ";
        }
        str = str.mid(0,str.length()-1) +"<br>";        //.mid(初始位置,長度)
        //cout << "\n";

        do{
            do i++; while(show[i] < val);       //左向右找比val大或等於的
            do j--; while(show[j] >= val);      //右向左找比val小的
            if(i < j){      // show[i] 和 show[j] 交換
                tmp = show[i];
                show[i] = show[j];
                show[j] = tmp;

                //輸出第二次
                for(int x = 0; x < len; x++){
                    if(x == right)  //pivot 為 right
                        str= str +"<font color=#FF0000>" + QString(show[x]) + "</font>,";
                    //cout << show[x] << "* ";
                    else str = str + QString(show[x])+",";
                    //cout << show[x] << " ";
                }
                str = str.mid(0,str.length()-1) +"<br>";
                //cout << "\n";

            }
        }while(i < j);  //此時 j = i - 1
        tmp = show[i];          //show[i]和show[right]交換
        show[i] = show[right];  //i == right時 就等於沒交換
        show[right] = tmp;

        if(i != right){     //有交換才輸出
            for(int x = 0; x < len; x++){
                if(x == i)
                    str= str +"<font color=#FF0000>" + QString(show[x]) + "</font>,";
                //cout << show[x] << "* ";
                else str = str + QString(show[x])+",";
                //cout << show[x] << " ";
            }
            str = str.mid(0,str.length()-1) +"<br>";
            //cout << "\n";
        }

// ABCDEFGHIJKLMNOPQRSTUVWXYZ
        //cout << str ;
        str += quick_sort(left, i-1, &show[0], len);
        str += quick_sort(i+1, right, &show[0], len);
        return str;



    }

}


void MainWindow::on_pushButton_clicked()
{
    QString q_str = ui -> lineEdit -> text();   //從圖形化介面取得資料
    string c_str = q_str.toStdString() + ',';   //QString to string
    string del = ",", sub;  //分隔符號 子字串
    int end, start = 0, len = 0, sum = 0;
    char show[256];


    //切割字串存入陣列
    while((end = c_str.find(del, start)) != string::npos){      //分隔符的位置 = 字串.find (分隔符號, 初始位置);
        len = end - start;
        sub = c_str.substr(start, len);     //切割的子字串 = 字串.substr(初始位置, 長度);
        show[sum] = *sub.c_str();       // .c_str()回傳型態為char* 所以需dereference
        start = end + 1;      //指到下一個新的字首
        //cout << show[sum] << "\n";
        sum++;
    }
    len = c_str.length();
    c_str = c_str.substr(0, len-1);  //寫入初始資料
    //cout << c_str;
    /*c_str += */
    q_str = QString::fromStdString(c_str) + "<br>"; //<br>換行
    q_str += quick_sort(0, sum-1, &show[0], sum);

    ui->label->setText(q_str);


}


/*for(int x = 0; x < len; x++){
    if(x == right)
        str= str + show[x]+"* ";
    //cout << show[x] << "* ";
    else str = str + show[x]+" ";
    //cout << show[x] << " ";
}
str+="\n";*/
