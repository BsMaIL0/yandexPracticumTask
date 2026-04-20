/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_up_windows;
    QAction *action_use_resources;
    QAction *action_choose_dir;
    QAction *close_prog;
    QAction *action_0sec;
    QAction *action_1sec;
    QAction *action_5sec;
    QAction *action_10sec;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *imageContainer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_left;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_right;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(756, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 217));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        action_up_windows = new QAction(MainWindow);
        action_up_windows->setObjectName("action_up_windows");
        action_up_windows->setCheckable(true);
        action_up_windows->setChecked(false);
        action_up_windows->setEnabled(true);
        action_use_resources = new QAction(MainWindow);
        action_use_resources->setObjectName("action_use_resources");
        action_choose_dir = new QAction(MainWindow);
        action_choose_dir->setObjectName("action_choose_dir");
        close_prog = new QAction(MainWindow);
        close_prog->setObjectName("close_prog");
        action_0sec = new QAction(MainWindow);
        action_0sec->setObjectName("action_0sec");
        action_0sec->setCheckable(true);
        action_0sec->setChecked(true);
        action_1sec = new QAction(MainWindow);
        action_1sec->setObjectName("action_1sec");
        action_1sec->setCheckable(true);
        action_5sec = new QAction(MainWindow);
        action_5sec->setObjectName("action_5sec");
        action_5sec->setCheckable(true);
        action_10sec = new QAction(MainWindow);
        action_10sec->setObjectName("action_10sec");
        action_10sec->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        imageContainer = new QWidget(centralwidget);
        imageContainer->setObjectName("imageContainer");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(imageContainer->sizePolicy().hasHeightForWidth());
        imageContainer->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(imageContainer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        btn_left = new QPushButton(centralwidget);
        btn_left->setObjectName("btn_left");
        btn_left->setMinimumSize(QSize(60, 40));
        btn_left->setMaximumSize(QSize(100, 60));
        btn_left->setStyleSheet(QString::fromUtf8("border: none; background: transparent;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/system/images/chevron_l.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_left->setIcon(icon);

        horizontalLayout->addWidget(btn_left);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_right = new QPushButton(centralwidget);
        btn_right->setObjectName("btn_right");
        btn_right->setMinimumSize(QSize(60, 40));
        btn_right->setMaximumSize(QSize(100, 60));
        btn_right->setStyleSheet(QString::fromUtf8("border: none; background: transparent;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/system/images/chevron_r.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_right->setIcon(icon1);

        horizontalLayout->addWidget(btn_right);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 756, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menu);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_up_windows);
        menu->addAction(action_use_resources);
        menu->addAction(action_choose_dir);
        menu->addAction(menu_2->menuAction());
        menu->addAction(close_prog);
        menu_2->addAction(action_0sec);
        menu_2->addAction(action_1sec);
        menu_2->addAction(action_5sec);
        menu_2->addAction(action_10sec);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\210\320\260\321\207\320\270\320\271 \321\204\320\276\321\202\320\276\320\260\320\273\321\214\320\261\320\276\320\274", nullptr));
        action_up_windows->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\321\205 \320\262\321\201\320\265\321\205 \320\276\320\272\320\276\320\275 (\320\263\320\260\320\273\320\276\321\207\320\272\320\260)", nullptr));
        action_use_resources->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260 \321\200\320\265\321\201\321\203\321\200\321\201\320\276\320\262", nullptr));
        action_choose_dir->setText(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\202\320\276 \320\270\320\267 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\277\320\260\320\277\320\272\320\270", nullptr));
        close_prog->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        action_0sec->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        action_1sec->setText(QCoreApplication::translate("MainWindow", "1 \321\201\320\265\320\272\321\203\320\275\320\264\320\260", nullptr));
        action_5sec->setText(QCoreApplication::translate("MainWindow", "5 \321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        action_10sec->setText(QCoreApplication::translate("MainWindow", "10 \321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        btn_left->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        btn_right->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
