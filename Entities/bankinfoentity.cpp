#include "bankinfoentity.h"

BankInfoEntity::BankInfoEntity()
{

}

QString BankInfoEntity::getIBAN()
{
    return IBAN;
}

void BankInfoEntity::setIBAN(QString value)
{
    IBAN = value;
}

QString BankInfoEntity::getSWIFT()
{
    return SWIFT;
}

void BankInfoEntity::setSWIFT(QString value)
{
    SWIFT = value;
}

QString BankInfoEntity::getVS()
{
    return VS;
}

void BankInfoEntity::setVS(QString value)
{
    VS = value;
}

int BankInfoEntity::getId()
{
    return Id;
}

void BankInfoEntity::setId(int value)
{
    Id = value;
}

bool BankInfoEntity::isValid()
{
    return (!IBAN.isEmpty());
}
