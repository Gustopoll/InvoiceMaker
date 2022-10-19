#include "addsupplierquerry.h"

AddSupplierQuerry::AddSupplierQuerry()
{
    nameTable = "supplier";
}

bool AddSupplierQuerry::Add(SupplierEntity *entity)
{
    if (entity == nullptr)
        return SetErrorMSG("null " + nameTable + " entity object");

    int idBankInfo = AddBankInfo(entity->getBankinfo());
    if (idBankInfo == -1)
        return SetErrorMSG(lastError);

    int idAdress = AddAdress(entity->getAdress());
    if (idAdress == -1)
        return SetErrorMSG(lastError);

    QSqlQuery q;
    q.prepare("INSERT INTO " + nameTable + " (name, facturenumber, idadress, idbankinfo, ico, dic, icdph, isdeleted) "
    "VALUES (:name_value, :facturenumber_value, :idadress_value, :idbankinfo_value, :ico_value, :dic_value, :icdph_value, :isdeleted_value);");

    q.bindValue(":name_value",entity->getName());
    q.bindValue(":facturenumber_value",entity->getFactureNumber());
    q.bindValue(":idadress_value",idAdress);
    q.bindValue(":idbankinfo_value",idBankInfo);
    q.bindValue(":ico_value",entity->getIco());
    q.bindValue(":dic_value",entity->getPayer()->getDic());
    q.bindValue(":icdph_value",entity->getPayer()->getIcdph());
    q.bindValue(":isdeleted_value","0");

    q.exec();
    id = q.lastInsertId().toInt();

    return SetErrorMSG(q.lastError());
}

int AddSupplierQuerry::GetInsertedID()
{
    return id;
}
