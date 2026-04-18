#include "mainwindow.h"
#include "ui_mainwindow.h"

// Функция подгоняет изображение под нужный размер окна.
[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio > h_ratio ) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetPixmap(":/cats/images/cat1.jpg");
    FitImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    int win_w = width();
    int win_h = height();

    QPixmap scaled_img = ResizeImgToFit(active_pixmap,win_w,win_h);

    int new_img_w = scaled_img.width();  // Ширина скалированного изображения
    int new_img_h = scaled_img.height();

    int lbl_x = (win_w - new_img_w) / 2;
    int lbl_y = (win_h - new_img_h) / 2;

    ui->lbl_img->setPixmap(scaled_img);
    ui->lbl_img->resize(new_img_w,new_img_h);

    ui->lbl_img->move(lbl_x,lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}
