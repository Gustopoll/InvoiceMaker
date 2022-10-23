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
    QString toStringDB(QDate date);

    QDate getDate(int day, int month, int year);
    QDate getDate(QString date);
    QDate getDateDB(QString date);
};

#endif // DATEHELPER_H
