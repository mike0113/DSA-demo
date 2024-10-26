#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    int pos = 0, end = 0, n, k;
    input = ui->textEdit->toPlainText();
    in_s = input.toStdString();
    end = in_s.find(" ",pos);
    n = stoi(in_s.substr(0,end));
    pos = end+1;
    end = in_s.find("\n",pos);
    k = stoi(in_s.substr(pos,end));
    pos = end+1;
    output = QString::number(QString::from);
    ui->textBrowser->setText(output);
    for(int i = pos; i < (int)in_s.length(); i++ ){
        if(in_s[i] ==' '){

        }
    }

}

