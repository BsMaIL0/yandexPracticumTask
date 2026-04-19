#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

// Функция подгоняет изображение под нужный размер окна.
[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio < h_ratio ) {
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
    SetFolder(":/cats/images/");
    FitImage();
    UpdateEnabled();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetFolder(const QString &d)
{
    current_folder_ = d;
    cur_file_index_ = 0;
    SetPixmap(GetCurrentFile());
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

    lbl_new_.setPixmap(scaled_img);
    lbl_new_.resize(new_img_w,new_img_h);

    lbl_new_.move(lbl_x,lbl_y);
}

QString MainWindow::GetCurrentFile()
{
    QDir dir(current_folder_);
    QStringList list_files = dir.entryList();
    int total = int(list_files.size());
    int file_index = std::min(cur_file_index_, total - 1);
    file_index = std::max(0, file_index);
    return dir.filePath(list_files[file_index]);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

void MainWindow::UpdateEnabled() {
    // Количество изображений в папке.
    int max_images = QDir(current_folder_).entryList().size();

    // Устанавливаем активность кнопки «влево».
    ui->btn_left->setEnabled(cur_file_index_ > 0);

    // Устанавливаем активность кнопки «вправо».
    ui->btn_right->setEnabled(cur_file_index_ < max_images - 1);
}
void MainWindow::on_btn_left_clicked()
{
    cur_file_index_--;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

void MainWindow::on_btn_right_clicked()
{
    cur_file_index_++;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

