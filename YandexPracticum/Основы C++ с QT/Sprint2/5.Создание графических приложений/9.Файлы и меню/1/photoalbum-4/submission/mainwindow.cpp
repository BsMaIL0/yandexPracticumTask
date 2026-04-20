#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QAction>
#include <QTimer>
#include <QFileInfo>
#include <algorithm>

void MainWindow::ClearField() {
    lbl_new_.clear();
    active_pixmap = QPixmap();
    UpdateEnabled();
}

[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if (w_ratio < h_ratio) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

bool MainWindow::IsImageFile(const QString& path) const {
    QString ext = QFileInfo(path).suffix().toLower();
    return ext == "jpg" || ext == "jpeg" || ext == "png" ||
           ext == "bmp" || ext == "gif" || ext == "webp";
}

QPixmap MainWindow::GetImageByPath(QString path) const {
    QFileInfo file_info(path);
    if (!file_info.isFile() || !IsImageFile(path)) {
        return {};
    }
    return QPixmap(path);
}

void MainWindow::UpdateImageCache() {
    QDir dir(current_folder_);
    auto all_files = dir.entryList(QDir::Files);
    cached_image_files_.clear();

    for (const auto& file : all_files) {
        if (IsImageFile(file)) {
            cached_image_files_.append(file);
        }
    }
}

std::pair<QPixmap, int> MainWindow::FindNextImage(int start_index, int direction) const {
    if (cached_image_files_.isEmpty()) {
        return {{}, -1};
    }

    int count = static_cast<int>(cached_image_files_.size());
    int cur_image = start_index;

    for(int steps = 0; steps < count; ++steps, cur_image += direction) {
        cur_image = ((cur_image % count) + count) % count;

        auto pixmap = GetImageByPath(QDir(current_folder_).filePath(cached_image_files_[cur_image]));
        if (!pixmap.isNull()) {
            return {pixmap, cur_image};
        }
    }
    return {{}, -1};
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем флаг "поверх всех окон" по умолчанию
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    ui->action_up_windows->setChecked(true);

    SetFolder(":/cats/images/");
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->menu = new QMenu(this);

    auto_switch_timer_ = new QTimer(this);
    connect(ui->action_up_windows, &QAction::triggered, this, &MainWindow::action_up_windows_clicked);
    connect(ui->act_exit, &QAction::triggered, this, &MainWindow::act_exit_clicked);
    connect(ui->action_use_resources, &QAction::triggered, this, &MainWindow::action_action_use_resources_clicked);
    connect(ui->action_choose_dir, &QAction::triggered, this, &MainWindow::action_choose_dir_clicked);
    connect(ui->action_period_off, &QAction::triggered, this, &MainWindow::action_period_off);
    connect(ui->action_period_1, &QAction::triggered, this, &MainWindow::action_period_1);
    connect(ui->action_period_5, &QAction::triggered, this, &MainWindow::action_period_5);
    connect(ui->action_period_10, &QAction::triggered, this, &MainWindow::action_period_10);

    connect(auto_switch_timer_, &QTimer::timeout, this, &MainWindow::on_btn_right_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetFolder(const QString &d) {
    StopAutoSwitch();
    current_folder_ = d;
    UpdateImageCache();

    cur_file_index_ = 0;

    auto [pixmap, index] = FindNextImage(0, 1);
    if (!pixmap.isNull()) {
        active_pixmap = pixmap;
        cur_file_index_ = index;
        lbl_new_.setPixmap(pixmap);
        FitImage();
        files_finded_ = true;
    } else {
        ClearField();
        active_pixmap = QPixmap();
        files_finded_ = false;
    }
    UpdateEnabled();

    if (current_period_ > 0 && files_finded_) {
        StartAutoSwitch(current_period_);
    }
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    int win_w = width();
    int win_h = height();

    QPixmap scaled_img = ResizeImgToFit(active_pixmap, win_w, win_h);

    int new_img_w = scaled_img.width();
    int new_img_h = scaled_img.height();

    int lbl_x = (win_w - new_img_w) / 2;
    int lbl_y = (win_h - new_img_h) / 2;

    lbl_new_.setPixmap(scaled_img);
    lbl_new_.resize(new_img_w, new_img_h);
    lbl_new_.move(lbl_x, lbl_y);
}

QString MainWindow::GetCurrentFile()
{
    if (cached_image_files_.isEmpty()) {
        return QString();
    }
    int total = static_cast<int>(cached_image_files_.size());
    int file_index = std::min(cur_file_index_, total - 1);
    file_index = std::max(0, file_index);
    return QDir(current_folder_).filePath(cached_image_files_[file_index]);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    if (!active_pixmap.isNull()) {
        FitImage();
    }
}

void MainWindow::UpdateEnabled() {
    int image_count = static_cast<int>(cached_image_files_.size());

    ui->btn_left->setEnabled(files_finded_ && cur_file_index_ > 0);
    ui->btn_right->setEnabled(files_finded_ && cur_file_index_ < image_count - 1);

    if (!files_finded_ && auto_switch_timer_ && auto_switch_timer_->isActive()) {
        StopAutoSwitch();
        ui->action_period_off->setChecked(true);
    }
}

void MainWindow::on_btn_left_clicked()
{
    if (!files_finded_ || cur_file_index_ <= 0) { return; }
    cur_file_index_--;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

void MainWindow::act_exit_clicked()
{
    close();
}

void MainWindow::on_btn_right_clicked()
{
    if (!files_finded_ || cur_file_index_ >= static_cast<int>(cached_image_files_.size()) - 1) { return; }
    cur_file_index_++;
    SetPixmap(GetCurrentFile());
    FitImage();
    UpdateEnabled();
}

void MainWindow::action_up_windows_clicked(bool state)
{
    if (state) {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    } else {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
    show();
}

void MainWindow::action_action_use_resources_clicked()
{
    SetFolder(":/cats/images/");
}

void MainWindow::action_choose_dir_clicked()
{
    QString dir = prac::QFileDialog::getExistingDirectory(this,
                                                          QString("Открыть папку"),
                                                          QDir::currentPath(),
                                                          prac::QFileDialog::ShowDirsOnly
                                                              | prac::QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        SetFolder(dir);
    }
}

void MainWindow::action_period_off(bool checked) {
    if (checked) {
        StopAutoSwitch();
        ui->action_period_off->setChecked(true);
        ui->action_period_1->setChecked(false);
        ui->action_period_5->setChecked(false);
        ui->action_period_10->setChecked(false);
    }
}

void MainWindow::action_period_1(bool checked) {
    if (checked) {
        StartAutoSwitch(1);
        ui->action_period_off->setChecked(false);
        ui->action_period_1->setChecked(true);
        ui->action_period_5->setChecked(false);
        ui->action_period_10->setChecked(false);
    }
}

void MainWindow::action_period_5(bool checked) {
    if (checked) {
        StartAutoSwitch(5);
        ui->action_period_off->setChecked(false);
        ui->action_period_1->setChecked(false);
        ui->action_period_5->setChecked(true);
        ui->action_period_10->setChecked(false);
    }
}

void MainWindow::action_period_10(bool checked) {
    if (checked) {
        StartAutoSwitch(10);
        ui->action_period_off->setChecked(false);
        ui->action_period_1->setChecked(false);
        ui->action_period_5->setChecked(false);
        ui->action_period_10->setChecked(true);
    }
}

void MainWindow::StopAutoSwitch() {
    if (auto_switch_timer_ && auto_switch_timer_->isActive()) {
        auto_switch_timer_->stop();
    }
    current_period_ = 0;
}

void MainWindow::StartAutoSwitch(int seconds) {
    if (seconds <= 0 || !files_finded_) {
        StopAutoSwitch();
        return;
    }

    StopAutoSwitch();
    current_period_ = seconds;
    auto_switch_timer_->start(seconds * 1000);
}
