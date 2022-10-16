#ifndef DATEHELPER_H
#define DATEHELPER_H

#include <QString>
#include <QDate>

class DateHelper
{
public:
    DateHelper();

    QString toString(int day, int month, int year);
    QString toString(QDate date);
    QDate getDate(int day, int month, int year);
    QDate getDate(QString date);
};

#endif // DATEHELPER_H
