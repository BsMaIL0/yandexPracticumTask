#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>
#include <QFileInfo>

QString TimeToString(QTime time) {
    return QString("%1:%2:%3").arg(time.hour(), 2, 10, QChar('0')).arg(time.minute(), 2, 10, QChar('0')).arg(time.second(), 2, 10, QChar('0'));
}

QString TimeToString(std::chrono::milliseconds ms) {
    return TimeToString(QTime::fromMSecsSinceStartOfDay(ms.count() + 500));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , alarm_active_(false)
{
    ui->setupUi(this);
    connect(&timer_, &prac::QTimer::timeout, this, &MainWindow::OnTimer);
    connect(ui->action_load_file, &QAction::triggered, this, &MainWindow::action_load_file_clicked);
    OnTimer();
    player_.setAudioOutput(&audio_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnTimer()
{
    QTime time = prac::QTime::currentTime();
    QString string_time = TimeToString(time);
    ui->lbl_now->setText(string_time);
    timer_.start(1000 - time.msec());
    ProcessAlarm();
}

void MainWindow::ProcessAlarm()
{
    if (!alarm_active_) {
        ui->lbl_timeout->setText("Установите будильник");
        return;
    }

    auto now = prac::QDateTime::currentDateTime();

    if (now >= alarm_moment_) {
        ui->lbl_timeout->setText("Пора вставать");
        if (player_.playbackState() != QMediaPlayer::PlaybackState::PlayingState) {
            player_.play();
        }
        return;
    }

    auto time_to_alarm = alarm_moment_ - now;
    QString string_time = TimeToString(time_to_alarm);
    ui->lbl_timeout->setText(string_time);
}

void MainWindow::on_pb_start_stop_clicked()
{
    if (!alarm_active_) {
        auto now = prac::QDateTime::currentDateTime();
        QTime alarm_time = QTime(ui->sb_hour->value(), ui->sb_min->value(), ui->sb_sec->value());
        alarm_moment_ = QDateTime(now.date(), alarm_time);
        if (alarm_time < now.time()) {
            alarm_moment_ = alarm_moment_.addDays(1);
        }
        alarm_active_ = true;
        ui->pb_start_stop->setText("Стоп");
        ProcessAlarm();
    } else {
        alarm_active_ = false;
        alarm_moment_ = QDateTime();
        ui->pb_start_stop->setText("Старт");
        if (player_.playbackState() == QMediaPlayer::PlaybackState::PlayingState) {
            player_.stop();
        }
        ui->lbl_timeout->setText("Установите будильник");
    }
}

void MainWindow::action_load_file_clicked()
{
    QString file_name = prac::QFileDialog::getOpenFileName(this,
                                                           QString::fromUtf8("Открыть файл"),
                                                           QDir::currentPath(),
                                                           "*.wav;*.mp3");

    if (!file_name.isEmpty()) {
        player_.setSource(QUrl::fromLocalFile(file_name));
        ui->lbl_melody->setText(QFileInfo(file_name).fileName());
    }
}
