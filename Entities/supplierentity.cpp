#include "supplierentity.h"

SupplierEntity::SupplierEntity()
{
    adress = new AdressEntity();
    payer = new PayerDPHEntity();
    bankinfo = new BankInfoEntity();
    id = -1;
    factureNumber = 1;
}

int SupplierEntity::getFactureNumber()
{
    return factureNumber;
}

void SupplierEntity::setFactureNumber(int value)
{
    factureNumber = value;
}

int SupplierEntity::getId()
{
    return id;
}

void SupplierEntity::setId(int value)
{
    id = value;
}

QString SupplierEntity::getIco()
{
    return ico;
}

void SupplierEntity::setIco(QString value)
{
    ico = value;
}

BankInfoEntity *SupplierEntity::getBankinfo()
{
    return bankinfo;
}

void SupplierEntity::setBankinfo(BankInfoEntity *value)
{
    //delete this->bankinfo;
    bankinfo = value;
}

QString SupplierEntity::getName()
{
    return name;
}

void SupplierEntity::setName(QString value)
{
    name = value;
}

PayerDPHEntity *SupplierEntity::getPayer()
{
    return payer;
}

AdressEntity *SupplierEntity::getAdress()
{
    return adress;
}

void SupplierEntity::setAdress(AdressEntity *value)
{
    //delete this->adress;
    adress = value;
}

bool SupplierEntity::isPayer()
{
    if (payer->getDic().isEmpty())
        return false;
    return true;
}

bool SupplierEntity::isAdressNull()
{
    if (adress == nullptr)
        return true;
    return false;
}
