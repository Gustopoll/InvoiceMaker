#include "additemquerry.h"

AddItemQuerry::AddItemQuerry()
{
    nameTable = "item";
}

bool AddItemQuerry::Add(ItemEntity *entity, int idInvoice)
{
    if (entity == nullptr)
        return SetErrorMSG("null " + nameTable + " entity object");

    QSqlQuery q;
    q.prepare("INSERT INTO " + nameTable + " (idInvoice, price, totalPrice, count, dph, description) "
    "VALUES (:idInvoice_value, :price_value, :totalPrice_value , :count_value, :dph_value, :description_value);");

    q.bindValue(":idInvoice_value",idInvoice);
    q.bindValue(":price_value",entity->getPrice());
    q.bindValue(":totalPrice_value",entity->getTotalPrice());
    q.bindValue(":count_value",entity->getCount());
    q.bindValue(":dph_value",entity->getDPH());
    q.bindValue(":description_value",entity->getDescription());

    q.exec();
    id = q.lastInsertId().toInt();

    return SetErrorMSG(q.lastError());
}
