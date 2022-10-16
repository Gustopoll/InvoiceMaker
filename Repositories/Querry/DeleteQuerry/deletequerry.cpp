#include "deletequerry.h"

DeleteQuerry::DeleteQuerry()
{

}

bool DeleteQuerry::Delete(int id, QString nameTable)
{
    QSqlQuery q;
    q.prepare("DELETE FROM " + nameTable + " WHERE id = :value;");
    q.bindValue(":value",id);

    q.exec();
    return SetErrorMSG(q.lastError().text());
}
