#include "getitemquerry.h"

GetItemQuerry::GetItemQuerry()
{
    nameTable = "item";
}

QList<ItemEntity *> GetItemQuerry::GetAllByInvoiceID(int id)
{
    QString querry = "SELECT * FROM " + nameTable + " WHERE idInvoice = " + QString::number(id);
    return Get(querry);
}

QList<ItemEntity*> GetItemQuerry::Get(QString querry)
{
    QSqlQuery q;
    q.prepare(querry);

    q.exec();
    lastError = q.lastError().text();

    QList<ItemEntity*> listEntities;
    while (q.next() == true)
    {
        ItemEntity* entity = new ItemEntity();
        entity->setId(q.value("id").toInt());
        entity->setDPH(q.value("dph").toDouble());
        entity->setCount(q.value("count").toInt());
        entity->setPrice(q.value("price").toDouble());
        entity->setTotalPrice(q.value("totalPrice").toDouble());
        entity->setDescription(q.value("description").toString());
        listEntities.push_back(entity);
    }
    return listEntities;
}
