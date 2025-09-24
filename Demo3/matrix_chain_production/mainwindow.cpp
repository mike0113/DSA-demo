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
    int N = 0;
    matrix.clear();
    size.clear();
    matrix.push_back(0);
    size.push_back(0);
    QString qstr = ui->lineEdit->text();
    string str =  qstr.toStdString();
    while(str != ""){
        matrix.push_back(str[0]);
        str = str.substr(1);
        N++;
    }
    /*for(auto it = matrix.begin(); it != matrix.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
    qstr = ui->lineEdit_2->text();
    str =  qstr.toStdString();
    int pos;
    string one;
    while((pos = str.find(',')) != string::npos){
        one = str.substr(0,pos);
        str = str.substr(pos+1);
        pos = one.find('*');
        size.push_back(stoi(one.substr(0,pos)));
    }
    pos = str.find('*');
    size.push_back(stoi(str.substr(0,pos)));
    size.push_back(stoi(str.substr(pos+1)));

    /*for(auto it = size.begin(); it != size.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;*/
    int cost[N+1][N+1] = {0};
    int best[N+1][N+1] = {0};
    int tmp;

    //Matrix Chain Production
    for(int i = 1; i <= N; i++) //N = 矩陣個數, i = row, j = column
        for(int j = i+1; j <= N; j++)   //右上方
            cost[i][j] = INT_MAX;
    for(int i =1; i <= N; i++)  //對角線
        cost[i][i] = 0;
    for(int j = 1; j < N ; j++) //一次考慮(j+1)個矩陣
        for(int i = 1; i <= N-j; i++)   //從第i個開始，一刀切在第k個前
            for(int k = i+1; k <= i+j; k++){
                tmp = cost[i][k-1] + cost[k][i+j] + size[i]*size[k]*size[i+j+1];    //A*B需要x*y*z次陳法
                if(cost[i][i+j] > tmp){     //三相操作
                    cost[i][i+j] = tmp;
                    best[i][i+j] = k;

                }

            }
    /*for(int i=1; i <= N; i++){
        for(int j=1; j <= N; j++){
            std::cout << best[i][j] << " " ;
        }
        std::cout << std::endl;
    }*/

    int* pbest[N+1];
    for (int i = 0; i < N+1; i++)
        pbest[i] = best[i];		//取列

    str ="結果: ";
    str += PrintOptimalParens(pbest, 1, N);     //this

    str += "\n所需乘法次數：" + std::to_string(cost[1][N]) + "次";
    ui->label_3->setText(QString::fromStdString(str));



}

string MainWindow::PrintOptimalParens(int **pbest, int i, int j){
    string out = "";
    if(i ==  j){
        out += matrix[i];
    }
    else{
        out += "(";
        out += PrintOptimalParens(pbest, i, pbest[i][j]-1);  //切在pbest之前
        out += PrintOptimalParens(pbest, pbest[i][j], j);
        out += ")";
    }
    return out;
}

