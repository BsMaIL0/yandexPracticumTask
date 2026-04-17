/********************************************************************************
** Form generated from reading UI file 'mywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWINDOW_H
#define UI_MYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWindow
{
public:
    QWidget *centralwidget;
    QLabel *lbl_mytext;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyWindow)
    {
        if (MyWindow->objectName().isEmpty())
            MyWindow->setObjectName("MyWindow");
        MyWindow->resize(526, 385);
        centralwidget = new QWidget(MyWindow);
        centralwidget->setObjectName("centralwidget");
        lbl_mytext = new QLabel(centralwidget);
        lbl_mytext->setObjectName("lbl_mytext");
        lbl_mytext->setGeometry(QRect(10, 10, 491, 341));
        MyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 526, 22));
        MyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyWindow);
        statusbar->setObjectName("statusbar");
        MyWindow->setStatusBar(statusbar);

        retranslateUi(MyWindow);

        QMetaObject::connectSlotsByName(MyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyWindow)
    {
        MyWindow->setWindowTitle(QCoreApplication::translate("MyWindow", "MyWindow", nullptr));
        lbl_mytext->setText(QCoreApplication::translate("MyWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; font-style:italic; color:#204130;\">\320\237\321\200\320\270\320\262\320\265\321\202, Qt!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWindow: public Ui_MyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWINDOW_H
