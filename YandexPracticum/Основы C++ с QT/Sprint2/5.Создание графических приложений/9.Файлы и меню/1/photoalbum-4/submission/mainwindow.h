#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <prac/QFileDialog>

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

    void SetPixmap(const QString path) {
        active_pixmap = QPixmap(path);
    }
    void SetFolder(const QString& d);
    void FitImage();
    QString GetCurrentFile();
    void UpdateEnabled();
    std::pair<QPixmap, int> FindNextImage(int start_index, int direction) const;
    QPixmap GetImageByPath(QString path) const;

private slots:
    void on_btn_left_clicked();
    void act_exit_clicked();
    void on_btn_right_clicked();
    void action_up_windows_clicked(bool);
    void action_action_use_resources_clicked();
    void action_choose_dir_clicked();
    void action_period_off(bool);
    void action_period_1(bool);
    void action_period_5(bool);
    void action_period_10(bool);

private:
    void resizeEvent(QResizeEvent *event) override;
    void ClearField();
    void StopAutoSwitch();
    void StartAutoSwitch(int seconds);
    void UpdateImageCache();
    bool IsImageFile(const QString& path) const;

private:
    Ui::MainWindow *ui;
    QLabel lbl_new_{this};
    QPixmap active_pixmap;
    QString current_folder_;
    int cur_file_index_ = 0;
    bool files_finded_ = false;
    QTimer* auto_switch_timer_ = nullptr;
    int current_period_ = 0;
    QStringList cached_image_files_;  // Кэш файлов-изображений
};

#endif // MAINWINDOW_H
