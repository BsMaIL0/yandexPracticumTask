#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>

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

    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->action_up_windows->setChecked(true);
    ui->action_up_windows->setText("Обычный режим");

    ui->btn_left->setEnabled(false);
    ui->btn_right->setEnabled(false);

    timer_ = new prac::QTimer(this);
    connect(timer_, &prac::QTimer::timeout, this, &MainWindow::slotNextPicture);

    SetFolder(":/cats/images");
    FitImage();

    UpdateButtonsState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    if(active_pixmap.isNull()) {
        lbl_new_.clear();
        return;
    }

    Q_ASSERT(!active_pixmap.isNull());
    int window_width = width();
    int window_height = height();
    QPixmap tmp = ResizeImgToFit(active_pixmap, window_width, window_height);
    lbl_new_.setPixmap(tmp);
    int img_w = tmp.width();
    int img_h = tmp.height();
    int lbl_x = (window_width - img_w) / 2;
    int lbl_y = (window_height - img_h) / 2;
    lbl_new_.resize(img_w,img_h);
    lbl_new_.move(lbl_x,lbl_y);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    FitImage();
}

void MainWindow::SetPixmap(const QString path) {
    active_pixmap = QPixmap(path);
    UpdateButtonsState();
}

QString MainWindow::GetCurrentFile(){
    QDir dir(current_folder_);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif";
    QStringList files = dir.entryList(filters, QDir::Files);

    if (files.empty()) {
        return QString();
    }

    if (cur_file_index_ < 0 || cur_file_index_ >= files.size()) {
        return QString();
    }
    return dir.filePath(files[cur_file_index_]);
}

void MainWindow::SetFolder(const QString& d){
    current_folder_ = d;
    cur_file_index_ = 0;
    QDir dir(d);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif";

    QStringList files = dir.entryList(filters, QDir::Files);

    if(!files.empty()) {
        QString firstImagePath = dir.filePath(files[cur_file_index_]);
        SetPixmap(firstImagePath);
        FitImage();
    } else {
        active_pixmap = QPixmap();
        lbl_new_.clear();
    }
    UpdateButtonsState();
}



void MainWindow::on_btn_left_clicked()
{
    timer_->stop();
    ui->action_0sec->setChecked(true);

    if(cur_file_index_>0){
        cur_file_index_--;
        SetPixmap(GetCurrentFile());
        FitImage();
        UpdateButtonsState();
    }
}

void MainWindow::UpdateButtonsState()
{
    QDir dir(current_folder_);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif";
    QStringList files = dir.entryList(filters, QDir::Files);
    int fileCount = files.size();
    bool hasFiles = fileCount > 0;

    if (!hasFiles) {
        ui->btn_left->setEnabled(false);
        ui->btn_right->setEnabled(false);
        return;
    }

    bool leftEnabled = (cur_file_index_ > 0);
    bool rightEnabled = (cur_file_index_ < fileCount - 1);

    ui->btn_left->setEnabled(leftEnabled);
    ui->btn_right->setEnabled(rightEnabled);
}

void MainWindow::on_btn_right_clicked()
{
    timer_->stop();
    ui->action_0sec->setChecked(true);

    QDir dir(current_folder_);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif";
    QStringList list = dir.entryList(filters, QDir::Files);
    if(cur_file_index_ < list.size() - 1){
        cur_file_index_++;
        SetPixmap(GetCurrentFile());
        FitImage();
        UpdateButtonsState();
    }
}

void MainWindow::on_action_up_windows_triggered(bool checked)
{
    Qt::WindowFlags flags = windowFlags();

    if (checked) {
        flags |= Qt::WindowStaysOnTopHint;
        ui->action_up_windows->setText("Обычный режим");
    } else {
        flags &= ~Qt::WindowStaysOnTopHint;
        ui->action_up_windows->setText("Поверх всех");
    }

    setWindowFlags(flags);
    show();
}


void MainWindow::on_action_use_resources_triggered()
{
    SetFolder(":/cats");
}

void MainWindow::on_action_choose_dir_triggered()
{
    QString folderPath = prac::QFileDialog::getExistingDirectory(
        this,
        "Выберите папку с изображениями",
        QDir::homePath(),
        prac::QFileDialog::ShowDirsOnly | prac::QFileDialog::DontResolveSymlinks
        );

    if (!folderPath.isEmpty()) {
        SetFolder(folderPath);
    }
}

void MainWindow::on_close_prog_triggered()
{
    QApplication::quit();
}

void MainWindow::slotNextPicture()
{
    QDir dir(current_folder_);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif";
    QStringList list = dir.entryList(filters, QDir::Files);
    if(cur_file_index_ < list.size() - 1){
        cur_file_index_++;
        SetPixmap(GetCurrentFile());
        FitImage();
        UpdateButtonsState();
    } else {
        cur_file_index_ = 0;
    }
}

void MainWindow::on_action_0sec_triggered(bool checked)
{
    if(checked){
        ui->action_1sec->setChecked(false);
        ui->action_5sec->setChecked(false);
        ui->action_10sec->setChecked(false);
        timer_->stop();
        timer_interval_ = 0;
    }
    else{
        return;
    }
}


void MainWindow::on_action_1sec_triggered(bool checked)
{
    if(checked){
        ui->action_0sec->setChecked(false);
        ui->action_5sec->setChecked(false);
        ui->action_10sec->setChecked(false);

        timer_->stop();
        timer_interval_ = 1000;
        timer_->start(timer_interval_);
    }
    else{
        return;
    }
}


void MainWindow::on_action_5sec_triggered(bool checked)
{
    if(checked){
        ui->action_0sec->setChecked(false);
        ui->action_1sec->setChecked(false);
        ui->action_10sec->setChecked(false);

        timer_->stop();
        timer_interval_ = 5000;
        timer_->start(timer_interval_);
    }
    else{
        return;
    }
}


void MainWindow::on_action_10sec_triggered(bool checked)
{
    if(checked){
        ui->action_0sec->setChecked(false);
        ui->action_5sec->setChecked(false);
        ui->action_1sec->setChecked(false);

        timer_->stop();
        timer_interval_ = 10000;
        timer_->start(timer_interval_);
    }
    else{
        return;
    }
}

