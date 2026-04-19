    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include <QIntValidator>
    #include <QRegularExpression>
    #include <QRegularExpressionValidator>

    void MainWindow::CheckValidity(QLineEdit* elem) {
        bool is_valid = elem->hasAcceptableInput();
        elem->setStyleSheet(is_valid ? "border:1px solid transparent" : "border:1px solid red");
    }

    int DaysPerMonth(int month, int year)
    {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29; // February in a leap year.
            } else {
                return 28; // February in a non-leap year.
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30; // April, June, September, November have 30 days.
        } else {
            return 31; // All other months have 31 days.
        }
    }

    int CalculateDaysFromStartYear(int day, int month, int year)
    {
        if(month == 0) {
            return 0;
        }
        int num_days = 0;
        for(size_t num_month = 1; num_month < static_cast<size_t>(month); ++num_month) {
            num_days += DaysPerMonth(num_month, year);
        }
        num_days += day;
        return num_days;
    }

    QString MainWindow::GetFormatType1(int day, int month, int year)
    {
        QString formated_date = "%1.%2.%3";
        return formated_date.arg(day, 2, 10, QLatin1Char('0'))
            .arg(month, 2, 10, QLatin1Char('0'))
            .arg(year);
    }

    QString MainWindow::GetFormatType2(int day, int month, int year)
    {
        QString formated_date = "%2/%1/%3";
        return formated_date.arg(day, 2, 10, QLatin1Char('0'))
            .arg(month, 2, 10, QLatin1Char('0'))
            .arg(year);
    }

    QString MainWindow::GetFormatType3(int day, int month, int year)
    {
        static const QStringList monthNames = {
            "", "января", "февраля", "марта", "апреля", "мая", "июня",
            "июля", "августа", "сентября", "октября", "ноября", "декабря"
        };

        QString formated_date = "%1 %2 %3 года";
        return formated_date.arg(day, 2, 10, QLatin1Char('0'))  // День с ведущим нулём
            .arg(monthNames.value(month, ""))
            .arg(year);
    }

    QString MainWindow::GetStrNumDays(int num_days, int year) {
        return QString("Это %1 день в %2 году").arg(num_days).arg(year);
    }

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        ui->le_day->setValidator(new QIntValidator(1, 31, this));
        ui->le_month->setValidator(new QIntValidator(1, 12, this));
        ui->le_year->setValidator(new QIntValidator(1, 9999, this));

        SetError("Некорректная дата");
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::ShowFormattedDate()
    {
        CheckValidity(ui->le_day);
        CheckValidity(ui->le_month);
        CheckValidity(ui->le_year);

        if(!ui->le_day->hasAcceptableInput() ||
            !ui->le_month->hasAcceptableInput() ||
            !ui->le_year->hasAcceptableInput() ) {
            SetError("Некорректная дата");

            return;
        }

        int day = ui->le_day->text().toInt();
        int month = ui->le_month->text().toInt();
        int year = ui->le_year->text().toInt();

        int day_in_month = DaysPerMonth(month,year);
        if(day>day_in_month){
            SetError("Такой даты не существует");
            return;
        }
        int day_from_start = CalculateDaysFromStartYear(day,month,year);
        QString l1 = GetFormatType1(day,month,year);
        QString l2 = GetFormatType2(day,month,year);
        QString l3 = GetFormatType3(day,month,year);
        QString l4 = GetStrNumDays(day_from_start,year);

        ui->le_date->setText(GetFormatType1(day, month, year));

        ui->lbl_format_type1->setText(l1);
        ui->lbl_format_type2->setText(l2);
        ui->lbl_format_type3->setText(l3);
        ui->lbl_message->setText(l4);

    }

    void MainWindow::SetError(const QString& err_text)
    {
        ui->lbl_format_type1->clear();
        ui->lbl_format_type2->clear();
        ui->lbl_format_type3->clear();
        ui->lbl_message->setText(err_text);
    }

    void MainWindow::on_le_date_textChanged(const QString&)
    {
        if(editing_now_){
            return;
        }
        editing_now_ = true;
        auto arr = ui->le_date->text().split(".");
        if(arr.size() == 3) {
            ui->le_day->setText(arr[0]);
            ui->le_month->setText(arr[1]);
            ui->le_year->setText(arr[2]);
        }
        CheckValidity(ui->le_day);
        CheckValidity(ui->le_month);
        CheckValidity(ui->le_year);
        ShowFormattedDate();
        editing_now_ = false;
    }

    void MainWindow::on_le_day_textChanged(const QString&)
    {
        if(editing_now_){
            return;
        }
        editing_now_ = true;
        ShowFormattedDate();
        editing_now_ = false;
    }

    void MainWindow::on_le_month_textChanged(const QString&)
    {
        if(editing_now_){
            return;
        }
        editing_now_ = true;
        ShowFormattedDate();
        editing_now_ = false;
    }

    void MainWindow::on_le_year_textChanged(const QString&)
    {
        if(editing_now_){
            return;
        }
        editing_now_ = true;
        ShowFormattedDate();
        editing_now_ = false;
    }
