#pragma once

#include <QMainWindow>
#include <prac/QTimer>
#include <prac/QMediaPlayer>
#include <prac/QTime>
#include <prac/QDateTime>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QDateTime GetAlarmMoment() const {
        return alarm_moment_;
    }

private slots:
    void OnTimer();
    void ProcessAlarm();
    void on_pb_start_stop_clicked();
    void action_load_file_clicked();

private:
    Ui::MainWindow *ui;
    QDateTime alarm_moment_;
    prac::QTimer timer_;
    prac::QMediaPlayer player_;
    QAudioOutput audio_;
    bool alarm_active_;
};
