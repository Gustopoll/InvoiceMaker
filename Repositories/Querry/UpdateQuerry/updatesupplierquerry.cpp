#include "updatesupplierquerry.h"

UpdateSupplierQuerry::UpdateSupplierQuerry()
{
    nameTable = "supplier";
}

bool UpdateSupplierQuerry::UpdateParameter(int id, QString param, QString value)
{
    return UpdateQuerry::UpdateParameter(id,param,value,nameTable);
}

bool UpdateSupplierQuerry::Update(SupplierEntity *entity)
{
    GetSupplierQuerry g;
    int idAdress = g.GetAdressId(entity->getId());
    int idBankInfo = g.GetBankInfoId(entity->getId());

    entity->getAdress()->setId(idAdress);
    entity->getBankinfo()->setId(idBankInfo);

    bool isOK = UpdateAdress(entity->getAdress());
    if (isOK == false)
        return SetErrorMSG(lastError);

    isOK = UpdateBankInfo(entity->getBankinfo());
    if (isOK == false)
        return SetErrorMSG(lastError);

    QSqlQuery q;
    q.prepare("UPDATE " + nameTable + " SET name = :name_value,"
                                  "facturenumber = :facturenumber_value, "
                                  "ico = :ico_value,"
                                  "dic = :dic_value,"
                                  "icdph = :icdph_value "
                                  "WHERE id = :id_value;");

    q.bindValue(":name_value",entity->getName());
    q.bindValue(":facturenumber_value",entity->getFactureNumber());
    q.bindValue(":ico_value",entity->getIco());
    q.bindValue(":dic_value",entity->getPayer()->getDic());
    q.bindValue(":icdph_value",entity->getPayer()->getIcdph());

    q.bindValue(":id_value",entity->getId());
    q.exec();

    return SetErrorMSG(q.lastError().text());
}
