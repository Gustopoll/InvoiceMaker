#include "datehelper.h"

DateHelper::DateHelper()
{

}

QString DateHelper::toString(int day, int month, int year)
{
    QString dayString = QString::number(day);
    QString monthString = QString::number(month);
    if (day < 10)
        dayString = "0" + QString::number(day);
    if (month < 10)
        monthString = "0" + QString::number(month);

    return  dayString + "." + monthString + "." + QString::number(year);
}

QString DateHelper::toString(QDate date)
{
    return date.toString("dd.MM.yyyy");
}

QDate DateHelper::getDate(int day, int month, int year)
{
    QString date = toString(day,month,year);
    return QDate::fromString(date,"dd.MM.yyyy");
}

QDate DateHelper::getDate(QString date)
{
    return QDate::fromString(date,"dd.MM.yyyy");
}
