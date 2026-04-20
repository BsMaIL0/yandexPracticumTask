#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDir>
#include <prac/QFileDialog>
#include <QResizeEvent>
#include <prac/QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void FitImage();
    void SetPixmap(const QString path);
    void SetFolder(const QString& d);

    QString GetCurrentFile();
    void UpdateButtonsState();
private slots:
    void on_btn_left_clicked();
    void on_btn_right_clicked();
    void on_action_up_windows_triggered(bool checked);
    void on_action_use_resources_triggered();
    void on_action_choose_dir_triggered();
    void slotNextPicture();
    void on_close_prog_triggered();
    void on_action_0sec_triggered(bool checked);

    void on_action_1sec_triggered(bool checked);

    void on_action_5sec_triggered(bool checked);

    void on_action_10sec_triggered(bool checked);

private:
    QLabel lbl_new_{this};
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::MainWindow *ui;
    QPixmap active_pixmap;
    QString current_folder_;
    int cur_file_index_ = 0;
    prac::QTimer *timer_ = nullptr;
    int timer_interval_ = 0;
};
#endif // MAINWINDOW_H
