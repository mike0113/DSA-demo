#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int num;

private slots:
    void on_pushButton_clicked();
    void koch(int it, int x1, int y1,int x5, int y5, QPainter& painter);

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
