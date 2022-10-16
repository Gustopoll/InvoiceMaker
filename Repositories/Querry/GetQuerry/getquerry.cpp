#include "getquerry.h"

GetQuerry::GetQuerry()
{

}

int GetQuerry::GetAdressId(int id, QString nameTable)
{
    QSqlQuery q;
    q.prepare("SELECT idadress FROM " + nameTable + " WHERE id = :idValue");
    q.bindValue(":idValue",id);

    q.exec();
    q.next();

    return q.value(0).toInt();
}

int GetQuerry::GetBankInfoId(int id, QString nameTable)
{
    QSqlQuery q;
    q.prepare("SELECT idadress FROM " + nameTable + " WHERE id = :idValue");
    q.bindValue(":idValue",id);

    q.exec();
    q.next();

    return q.value(0).toInt();
}

BankInfoEntity *GetQuerry::GetBankInfoById(int id)
{
    QSqlQuery q;
    q.prepare("SELECT * FROM bankinfo WHERE id = :id_value;");
    q.bindValue(":id_value",id);
    bool isOK = q.exec();
    q.first();

    BankInfoEntity* entity = new BankInfoEntity();
    if (isOK == true)
    {
        entity->setId(q.value("id").toInt());
        entity->setIBAN(q.value("IBAN").toString());
        entity->setVS(q.value("VS").toString());
        entity->setSWIFT(q.value("SWIFT").toString());
    }


    return entity;
}

AdressEntity *GetQuerry::GetAdressById(int id)
{
    QSqlQuery q;
    q.prepare("SELECT * FROM adress WHERE id = :id_value;");
    q.bindValue(":id_value",id);
    bool isOK = q.exec();
    q.first();

    AdressEntity* entity = new AdressEntity();
    if (isOK == true)
    {
        entity->setId(q.value("id").toInt());
        entity->setStreet(q.value("street").toString());
        entity->setStreetNumber(q.value("streetnumber").toString());
        entity->setPsc(q.value("psc").toString());
        entity->setCity(q.value("city").toString());
        entity->setState(q.value("state").toString());
    }

    return entity;
}
