#include "deletequerry.h"

DeleteQuerry::DeleteQuerry()
{

}

bool DeleteQuerry::Delete(int id, QString table)
{
    QSqlQuery q;
    q.prepare("DELETE FROM " + table + " WHERE id = :value;");
    q.bindValue(":value",id);

    q.exec();
    qDebug() << q.lastError().text();
    return SetErrorMSG(q.lastError().text());
}

bool DeleteQuerry::DeleteAdress(int id)
{
    return Delete(id,"adress");
}

bool DeleteQuerry::DeleteBankInfo(int id)
{
    return Delete(id,"bankinfo");
}
