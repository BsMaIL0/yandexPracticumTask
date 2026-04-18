#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_le_edit_textChanged(const QString &arg1)
{
    if(ui->le_edit->text().isEmpty()){
        ui->lbl_result->setText("Введите имя");
    }
    else{
        QString greating = "Привет из Qt, ";
        QString name = ui->le_edit->text();
        greating = greating + name + "!";
        ui->lbl_result->setText(greating);
    }
}

