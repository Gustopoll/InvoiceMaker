#include "updatequerry.h"

UpdateQuerry::UpdateQuerry()
{

}

bool UpdateQuerry::UpdateParameter(int id, QString param, QString value, QString nameTable)
{
    QSqlQuery q;
    q.prepare("UPDATE " + nameTable + " SET " + param  + " = :value WHERE id = :id_value");

    q.bindValue(":value",value);
    q.bindValue(":id_value",id);
    q.exec();

    return SetErrorMSG(q.lastError().text());
}


bool UpdateQuerry::UpdateAdress(AdressEntity *entity)
{
    QSqlQuery q;
    q.prepare("UPDATE adress SET street = :street_value,"
                                  "streetnumber = :streetnumber_value, "
                                  "psc = :psc_value,"
                                  "city = :city_value,"
                                  "state = :state_value "
                                  "WHERE id = :id_value;");

    q.bindValue(":street_value",entity->getStreet());
    q.bindValue(":streetnumber_value",entity->getStreetNumber());
    q.bindValue(":psc_value",entity->getPsc());
    q.bindValue(":city_value",entity->getCity());
    q.bindValue(":state_value",entity->getState());

    q.bindValue(":id_value",entity->getId());
    q.exec();

    return SetErrorMSG(q.lastError().text());
}

bool UpdateQuerry::UpdateBankInfo(BankInfoEntity *entity)
{
    QSqlQuery q;
    q.prepare("UPDATE bankinfo SET IBAN = :IBAN_value,"
                                  "SWIFT = :SWIFT_value, "
                                  "VS = :VS_value "
                                  "WHERE id = :id_value;");

    q.bindValue(":IBAN_value",entity->getIBAN());
    q.bindValue(":SWIFT_value",entity->getSWIFT());
    q.bindValue(":VS_value",entity->getVS());

    q.bindValue(":id_value",entity->getId());
    q.exec();

    return SetErrorMSG(q.lastError().text());
}
