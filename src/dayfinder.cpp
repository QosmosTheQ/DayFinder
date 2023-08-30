#include "dayfinder.h"
#include "ui_dayfinder.h"
#include <QLabel>
#include <QDebug>
#include <QDate>
#include "calculator.cpp"

DayFinder::DayFinder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DayFinder)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &DayFinder::on_pushButton_clicked);
}

DayFinder::~DayFinder()
{
    delete ui;
}

void DayFinder::on_pushButton_clicked()
{
    QDate selectedDate = ui->dateEdit->date();

    // Get the current date and time
    QDate currentDate = QDate::currentDate();

    // Calculate the time elapsed
    QDate currentDateNoTime = currentDate.addDays(1 - currentDate.day());
    QDate selectedDateNoTime = selectedDate.addDays(1 - selectedDate.day());
    int years = currentDateNoTime.year() - selectedDateNoTime.year() ;
    int months = selectedDateNoTime.month() - currentDateNoTime.month();
    int days = selectedDateNoTime.day() - currentDateNoTime.day();


    // Determine the zodiac sign
    QString zodiacSign = QString::fromStdString(determineZodiacSign(selectedDateNoTime.day(), selectedDateNoTime.month()));

    // Determine the corresponding Chinese zodiac animal
    QString chineseZodiac = QString::fromStdString(determineChineseZodiac(selectedDateNoTime.year()));

    // Determine the day of the week


    // Construct the formatted output
    QString outputText = "Entered Date: " + selectedDate.toString("dd.MM.yyyy") + "\n";
    outputText += "Current Date: " + currentDate.toString("dd.MM.yyyy") + "\n\n";
    outputText += "Time Elapsed: " + QString::number(years) + " years, " + QString::number(months) + " months, " + QString::number(days) + " days.\n";
    outputText += "Time Elapsed (in year month day): " + QString::number(years) + " years, " + QString::number(months) + " months, " + QString::number(days) + " days.\n\n";
    outputText += "Zodiac Sign: " + zodiacSign + "\n";
    outputText += "Chinese Zodiac Sign: " + chineseZodiac + "\n\n";

    // Set the text to outputLabel
    ui->outputLabel->setText(outputText);
}
