#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    num = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::koch(int num, int x1, int y1,int x5, int y5, QPainter& painter){
    int x2,y2,x3,y3,x4,y4,dx,dy;
    if(num == 0){
        //QPainter painter(this);
        painter.drawLine(x1, y1, x5, y5);
    }
    else{
        dx = (x5-x1)/3;     // 1/3長度
        dy = (y5-y1)/3;

        x2 = x1 + dx;
        y2 = y1 + dy;

        x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y5 - y1) / 6);
        y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x1 - x5) / 6);

        x4 = 2 * dx + x1;
        y4 = 2 * dy + y1;

        koch(num-1, x1, y1, x2, y2, painter);
        koch(num-1, x2, y2, x3, y3, painter);
        koch(num-1, x3, y3, x4, y4, painter);
        koch(num-1, x4, y4, x5, y5, painter);
    }

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
//while(true)
        //if(num !=-1)
    update();       //更新畫面
    koch(num,100, 400, 300 ,53.6, painter);
    koch(num, 300, 53.6, 500 ,400, painter);
    koch(num, 500, 400, 100 ,400, painter);
    //painter.drawLine(80, 100, 650, 500);

}

void MainWindow::on_pushButton_clicked()
{
    QString q_str = ui -> lineEdit -> text();   //從圖形化介面取得資料
    num = q_str.toInt();

    //koch(num, 100, 200, 420 ,200);


}

