/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *le_input;
    QLabel *lbl_result;
    QPushButton *btn_hello;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(320, 240);
        MainWindow->setMinimumSize(QSize(320, 240));
        MainWindow->setMaximumSize(QSize(320, 240));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        le_input = new QLineEdit(centralwidget);
        le_input->setObjectName("le_input");
        le_input->setGeometry(QRect(100, 100, 113, 22));
        lbl_result = new QLabel(centralwidget);
        lbl_result->setObjectName("lbl_result");
        lbl_result->setGeometry(QRect(70, 40, 181, 31));
        lbl_result->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btn_hello = new QPushButton(centralwidget);
        btn_hello->setObjectName("btn_hello");
        btn_hello->setGeometry(QRect(120, 140, 75, 24));
        btn_hello->setLocale(QLocale(QLocale::Rombo, QLocale::Tanzania));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 320, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hello Button", nullptr));
        lbl_result->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_hello->setText(QCoreApplication::translate("MainWindow", "Hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
