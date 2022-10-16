#ifndef BASEQUERRY_H
#define BASEQUERRY_H

#include <QString>
#include <QtSql>
#include <QSqlQuery>

class BaseQuerry
{
public:
    BaseQuerry();

    QString GetLastError();
    int GetLastStatusCode();

protected:
    QString lastError;
    int statusCode;

    bool SetErrorMSG(QString msg);
    bool SetErrorMSG(QSqlError e);
};

#endif // BASEQUERRY_H
