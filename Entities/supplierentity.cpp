#include "supplierentity.h"

SupplierEntity::SupplierEntity()
{
    adress = new AdressEntity();
    payer = new PayerDPHEntity();
    bankinfo = new BankInfoEntity();
    id = -1;
    factureNumberClassic = 1;
    factureNumberOrder = 1;
    factureNumberCanceled = 1;
    factureNumberDeposit = 1;
    factureNumberPriceoffer = 1;
}

int SupplierEntity::getFactureNumberClassic()
{
    return factureNumberClassic;
}

void SupplierEntity::setFactureNumberClassic(int value)
{
    factureNumberClassic = value;
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

int SupplierEntity::getFactureNumberCanceled()
{
    return factureNumberCanceled;
}

void SupplierEntity::setFactureNumberCanceled(int value)
{
    factureNumberCanceled = value;
}

int SupplierEntity::getFactureNumberDeposit()
{
    return factureNumberDeposit;
}

void SupplierEntity::setFactureNumberDeposit(int value)
{
    factureNumberDeposit = value;
}

int SupplierEntity::getFactureNumberOrder()
{
    return factureNumberOrder;
}

void SupplierEntity::setFactureNumberOrder(int value)
{
    factureNumberOrder = value;
}

int SupplierEntity::getFactureNumberPriceoffer()
{
    return factureNumberPriceoffer;
}

void SupplierEntity::setFactureNumberPriceoffer(int value)
{
    factureNumberPriceoffer = value;
}

int SupplierEntity::getFactureNumberByInvoiceType(InvoiceType type)
{
    if (type == InvoiceType::Faktura)
        return getFactureNumberClassic();
    if (type == InvoiceType::Dobropis)
        return getFactureNumberCanceled();
    if (type == InvoiceType::Objednavka)
        return getFactureNumberOrder();
    if (type == InvoiceType::Cenova_ponuka)
        return getFactureNumberPriceoffer();
    if (type == InvoiceType::Zalohova_faktura)
        return getFactureNumberDeposit();
    return -1; //default value, it never should be hit
}

void SupplierEntity::setFactureNumberByInvoiceType(InvoiceType type, int value)
{
    if (type == InvoiceType::Faktura)
        setFactureNumberClassic(value);
    if (type == InvoiceType::Dobropis)
        setFactureNumberCanceled(value);
    if (type == InvoiceType::Objednavka)
        setFactureNumberOrder(value);
    if (type == InvoiceType::Cenova_ponuka)
        setFactureNumberPriceoffer(value);
    if (type == InvoiceType::Zalohova_faktura)
        setFactureNumberDeposit(value);
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
