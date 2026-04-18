#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    void resizeEvent(QResizeEvent *event) {
        QMainWindow::resizeEvent(event);  // Вызов базового метода
        UpdateSizeLabel();                // Ваш метод для обновления позиции и размера
    }

    void UpdateSizeLabel();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
