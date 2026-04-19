#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include "magic_horoscope.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator* validator = new QIntValidator(1, 9999, this);
    ui->le_year->setValidator(validator);
    ui->sb_day->setValue(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_magic()
{
    int year = ui->le_year->text().toInt();
    if (year <= 0) {
        ui->lbl_calendar->setText("Введите год");
        return;
    }
    QString result;
    if (calendar_ == Calendar::kEastern) {
        QString animal = GetAnimalForEasternCalendar(year);
        QString element = GetElementForEasternCalendar(year);
        result = QString("%1 — это год %2. Стихия/цвет — %3")
                     .arg(year)
                     .arg(animal)
                     .arg(element);
    } else if (calendar_ == Calendar::kTibetan) {
        result = QString("%1 — это год %2")
                     .arg(year)
                     .arg(GetAnimalForTibetanCalendar(year));
    } else {
        result = QString("%1 — это год %2")
                     .arg(year)
                     .arg(GetAnimalForZoroastrianCalendar(year));
    }

    ui->lbl_calendar->setText(result);

    if (ui->gb_horoscope->isEnabled()) {
        int day = ui->sb_day->text().toInt();
        int monthIndex = ui->cb_month->currentIndex();
        int monthNumber = monthIndex + 1;

        if (horoscope_ == Horoscope::kZodiac) {
            QString zodiacSign = GetZodiac(day, monthNumber, year);
            if (zodiacSign.isEmpty()) {
                ui->lbl_horoscope->setText("Такой даты не существует");
                return;
            }

            QString formattedDay = QString("%1").arg(day, 2, 10, QChar('0'));
            QString formattedMonth = QString("%1").arg(monthNumber, 2, 10, QChar('0'));

            QString result = QString("%1.%2 — ваш знак зодиака %3 по зодиакальному гороскопу")
                                 .arg(formattedDay)
                                 .arg(formattedMonth)
                                 .arg(zodiacSign);

            ui->lbl_horoscope->setText(result);
        } else{
            QString tree = GetTree(day, monthNumber, year);
            if (tree.isEmpty()) {
                ui->lbl_horoscope->setText("Такой даты не существует");
                return;
            }

            QString formattedDay = QString("%1").arg(day, 2, 10, QChar('0'));
            QString formattedMonth = QString("%1").arg(monthNumber, 2, 10, QChar('0'));

            QString result = QString("%1.%2 — ваше тотемное дерево %3 по гороскопу друидов")
                                 .arg(formattedDay)
                                 .arg(formattedMonth)
                                 .arg(tree);
            ui->lbl_horoscope->setText(result);
        }

    }

}

void MainWindow::on_le_year_textChanged(const QString &arg1)
{
    make_magic();
}

void MainWindow::on_rb_eastern_toggled(bool checked)
{
    calendar_ = Calendar::kEastern;
    make_magic();
}

void MainWindow::on_rb_tibetan_toggled(bool checked)
{
    calendar_ = Calendar::kTibetan;
    make_magic();
}

void MainWindow::on_rb_zoroastrian_toggled(bool checked)
{
    calendar_ = Calendar::kZoroastrian;
    make_magic();
}


void MainWindow::on_cb_is_date_toggled(bool checked)
{
    if(!checked){
        ui->lbl_horoscope->setText("Ввод даты отключён");
    }
    ui->sb_day->setEnabled(checked);
    ui->cb_month->setEnabled(checked);
    ui->lbl_day->setEnabled(checked);
    ui->lbl_month->setEnabled(checked);
    ui->gb_horoscope->setEnabled(checked);
    ui->rb_druid->setEnabled(checked);
    ui->rb_zodiac->setEnabled(checked);
    make_magic();
}

void MainWindow::on_rb_zodiac_toggled(bool checked)
{
    horoscope_ = Horoscope::kZodiac;
    make_magic();
}

void MainWindow::on_rb_druid_toggled(bool checked)
{
    horoscope_ = Horoscope::kDruid;
    make_magic();
}


void MainWindow::on_sb_day_valueChanged(int arg1)
{
    make_magic();
}


void MainWindow::on_cb_month_currentIndexChanged(int index)
{
    make_magic();
}

