#include "addquerry.h"

AddQuerry::AddQuerry()
{
    lastError = "";
}

int AddQuerry::AddBankInfo(BankInfoEntity *entity)
{
    if (entity == nullptr)
        return -1;

    QSqlQuery q;
    q.prepare("INSERT INTO bankinfo (IBAN, SWIFT, VS) "
    "VALUES (:IBAN_value, :SWIFT_value, :VS_value);");

    q.bindValue(":IBAN_value",entity->getIBAN());
    q.bindValue(":SWIFT_value",entity->getSWIFT());
    q.bindValue(":VS_value",entity->getVS());

    q.exec();
    lastError = q.lastError().text();
    return q.lastInsertId().toInt();
}

int AddQuerry::AddAdress(AdressEntity *entity)
{
    if (entity == nullptr)
        return -1;

    QSqlQuery q;
    q.prepare("INSERT INTO adress (street, streetnumber, psc, city, state) "
    "VALUES (:street_value, :streetnumber_value, :psc_value, :city_value, :state_value);");

    q.bindValue(":street_value",entity->getStreet());
    q.bindValue(":streetnumber_value",entity->getStreetNumber());
    q.bindValue(":psc_value",entity->getPsc());
    q.bindValue(":city_value",entity->getCity());
    q.bindValue(":state_value",entity->getState());

    q.exec();
    lastError = q.lastError().text();
    return q.lastInsertId().toInt();
}
