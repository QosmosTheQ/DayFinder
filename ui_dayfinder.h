/********************************************************************************
** Form generated from reading UI file 'dayfinder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYFINDER_H
#define UI_DAYFINDER_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DayFinder
{
public:
    QWidget *centralwidget;
    QDateEdit *dateEdit;
    QLabel *dateLabel;
    QLabel *outputLabel;
    QPushButton *pushButton;

    void setupUi(QMainWindow *DayFinder)
    {
        if (DayFinder->objectName().isEmpty())
            DayFinder->setObjectName(QString::fromUtf8("DayFinder"));
        DayFinder->resize(711, 271);
        centralwidget = new QWidget(DayFinder);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(70, 130, 110, 27));
        dateEdit->setMinimumDateTime(QDateTime(QDate(1752, 9, 12), QTime(0, 0, 0)));
        dateEdit->setDate(QDate(2000, 12, 31));
        dateLabel = new QLabel(centralwidget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        dateLabel->setGeometry(QRect(70, 100, 111, 31));
        outputLabel = new QLabel(centralwidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setGeometry(QRect(270, 30, 411, 231));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 170, 87, 26));
        DayFinder->setCentralWidget(centralwidget);

        retranslateUi(DayFinder);

        QMetaObject::connectSlotsByName(DayFinder);
    } // setupUi

    void retranslateUi(QMainWindow *DayFinder)
    {
        DayFinder->setWindowTitle(QCoreApplication::translate("DayFinder", "DayFinder", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DayFinder", "d/M/yyyy", nullptr));
        dateLabel->setText(QCoreApplication::translate("DayFinder", "Enter the date", nullptr));
        outputLabel->setText(QCoreApplication::translate("DayFinder", ":empty:", nullptr));
        pushButton->setText(QCoreApplication::translate("DayFinder", "Calculate!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DayFinder: public Ui_DayFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYFINDER_H
