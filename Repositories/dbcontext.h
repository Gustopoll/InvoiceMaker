#ifndef DBCONTEXT_H
#define DBCONTEXT_H

#include <QString>
#include <QtSql>
#include <QSqlQuery>

class DBContext
{
public:
    DBContext();

    bool Connect();

    QString CreateTables();

private:
    QSqlDatabase db;
};

#endif // DBCONTEXT_H
