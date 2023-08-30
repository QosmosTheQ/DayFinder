#ifndef DAYFINDER_H
#define DAYFINDER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DayFinder; }
QT_END_NAMESPACE

class DayFinder : public QMainWindow
{
    Q_OBJECT

public:
    DayFinder(QWidget *parent = nullptr);
    ~DayFinder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DayFinder *ui;
};
#endif // DAYFINDER_H
