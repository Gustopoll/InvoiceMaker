#include "getsupplierquerry.h"

GetSupplierQuerry::GetSupplierQuerry()
{
    nameTable = "supplier";
}

int GetSupplierQuerry::GetAdressId(int idSupplier)
{
    return GetQuerry::GetAdressId(idSupplier,nameTable);
}

int GetSupplierQuerry::GetBankInfoId(int idSupplier)
{
    return GetQuerry::GetBankInfoId(idSupplier,nameTable);
}

SupplierEntity *GetSupplierQuerry::GetOneById(int id)
{
    QSqlQuery q;

    q.prepare("SELECT * FROM " + nameTable + " WHERE id = :value;");
    q.bindValue(":value",id);

    q.exec();
    lastError = q.lastError().text();
    q.next();

    SupplierEntity* e = new SupplierEntity();
    e->setId(q.value("id").toInt());
    e->setName(q.value("name").toString());
    e->setIco(q.value("ico").toString());
    e->setFactureNumberClassic(q.value("numberClassic").toInt());
    e->setFactureNumberCanceled(q.value("numberCanceled").toInt());
    e->setFactureNumberDeposit(q.value("numberDeposit").toInt());
    e->setFactureNumberOrder(q.value("numberOrder").toInt());
    e->setFactureNumberPriceoffer(q.value("numberPriceoffer").toInt());

    e->getPayer()->setDic(q.value("dic").toString());
    e->getPayer()->setIcdph(q.value("icdph").toString());

    e->setAdress(GetAdressById(q.value("idadress").toInt()));
    e->setBankinfo(GetBankInfoById(q.value("idbankinfo").toInt()));

    return e;
}

QList<SupplierEntity *> GetSupplierQuerry::GetAll()
{
    QSqlQuery q;

    bool isOK = q.prepare("SELECT * FROM " + nameTable);
    q.exec();
    lastError = q.lastError().text();

    QList<SupplierEntity*> ret;
    if (isOK == true)
    {
        while (q.next() == true)
        {
            SupplierEntity* e = new SupplierEntity();
            e->setId(q.value("id").toInt());
            e->setName(q.value("name").toString());
            e->setIco(q.value("ico").toString());
            e->setFactureNumberClassic(q.value("numberClassic").toInt());
            e->setFactureNumberCanceled(q.value("numberCanceled").toInt());
            e->setFactureNumberDeposit(q.value("numberDeposit").toInt());
            e->setFactureNumberOrder(q.value("numberOrder").toInt());
            e->setFactureNumberPriceoffer(q.value("numberPriceoffer").toInt());

            e->getPayer()->setDic(q.value("dic").toString());
            e->getPayer()->setIcdph(q.value("icdph").toString());

            e->setAdress(GetAdressById(q.value("idadress").toInt()));
            e->setBankinfo(GetBankInfoById(q.value("idbankinfo").toInt()));

            ret.append(e);
        }
    }
    return ret;
}

QList<SupplierEntity *> GetSupplierQuerry::GetAllNoDeleted()
{
    QSqlQuery q;

    bool isOK = q.prepare("SELECT * FROM " + nameTable + " WHERE isdeleted = 0;");
    q.exec();
    lastError = q.lastError().text();

    QList<SupplierEntity*> ret;
    if (isOK == true)
    {
        while (q.next() == true)
        {
            SupplierEntity* e = new SupplierEntity();
            e->setId(q.value("id").toInt());
            e->setName(q.value("name").toString());
            e->setIco(q.value("ico").toString());
            e->setFactureNumberClassic(q.value("numberClassic").toInt());
            e->setFactureNumberCanceled(q.value("numberCanceled").toInt());
            e->setFactureNumberDeposit(q.value("numberDeposit").toInt());
            e->setFactureNumberOrder(q.value("numberOrder").toInt());
            e->setFactureNumberPriceoffer(q.value("numberPriceoffer").toInt());

            e->getPayer()->setDic(q.value("dic").toString());
            e->getPayer()->setIcdph(q.value("icdph").toString());

            e->setAdress(GetAdressById(q.value("idadress").toInt()));
            e->setBankinfo(GetBankInfoById(q.value("idbankinfo").toInt()));

            ret.append(e);
        }
    }
    return ret;
}
