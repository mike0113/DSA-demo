/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 30, 431, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 30, 80, 24));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 25)
            tableWidget->setColumnCount(25);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(24, __qtablewidgetitem24);
        if (tableWidget->rowCount() < 26)
            tableWidget->setRowCount(26);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem50);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 761, 491));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(24);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\346\254\204\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
