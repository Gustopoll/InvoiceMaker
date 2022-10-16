#include "addcustomerquerry.h"

AddCustomerQuerry::AddCustomerQuerry()
{
    nameTable = "customer";
}

bool AddCustomerQuerry::Add(CustomerEntity *entity)
{
    if (entity == nullptr)
        return SetErrorMSG("null " + nameTable + " entity object");

    int idAdress = AddAdress(entity->getAdress());
    if (idAdress == -1)
        return SetErrorMSG(lastError);

    QSqlQuery q;
    q.prepare("INSERT INTO " + nameTable + " (name, idadress, ico, dic, icdph, isdeleted) "
    "VALUES (:name_value, :idadress_value, :ico_value, :dic_value, :icdph_value, :isdeleted_value);");

    q.bindValue(":name_value",entity->getName());
    q.bindValue(":idadress_value",idAdress);
    q.bindValue(":ico_value",entity->getIco());
    q.bindValue(":dic_value",entity->getPayer()->getDic());
    q.bindValue(":icdph_value",entity->getPayer()->getIcdph());
    q.bindValue(":isdeleted_value","0");

    q.exec();

    return SetErrorMSG(q.lastError());
}
