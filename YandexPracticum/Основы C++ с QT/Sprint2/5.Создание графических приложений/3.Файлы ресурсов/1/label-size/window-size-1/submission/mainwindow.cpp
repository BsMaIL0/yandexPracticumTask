#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UpdateSizeLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateSizeLabel() {
    ui->lbl_size->setAlignment(Qt::AlignCenter);
    int width_w = this->width();
    int height_h = this->height();
    ui->lbl_size->move(0,0);
    ui->lbl_size->resize(width_w,height_h);
    auto new_text = std::to_string(width()) + "x" + std::to_string(height());
    ui->lbl_size->setText(QString::fromStdString(new_text));
}
