#include "invoiceentity.h"

InvoiceEntity::InvoiceEntity()
{
    paymentMethon = Payment::Cash;
    invoiceType = InvoiceType::TypeA;
    customerSaved = nullptr;
    supplierSaved = nullptr;
    items.clear();
}


SupplierEntity *InvoiceEntity::getSupplierSaved()
{
    return supplierSaved;
}

void InvoiceEntity::setSupplierSaved(SupplierEntity *value)
{
    supplierSaved = value;
}

CustomerEntity *InvoiceEntity::getCustomerSaved()
{
    return customerSaved;
}

void InvoiceEntity::setCustomerSaved(CustomerEntity *value)
{
    customerSaved = value;
}

Payment InvoiceEntity::getPaymentMethon()
{
    return paymentMethon;
}

void InvoiceEntity::setPaymentMethon(Payment value)
{
    paymentMethon = value;
}

QDate InvoiceEntity::getDateV()
{
    return dateV;
}

void InvoiceEntity::setDateV(QDate value)
{
    dateV = value;
}

QDate InvoiceEntity::getDateD()
{
    return dateD;
}

void InvoiceEntity::setDateD(QDate value)
{
    dateD = value;
}

QDate InvoiceEntity::getDateS()
{
    return dateS;
}

void InvoiceEntity::setDateS(QDate value)
{
    dateS = value;
}

int InvoiceEntity::getId()
{
    return id;
}

void InvoiceEntity::setId(int value)
{
    id = value;
}

int InvoiceEntity::getIdSupplier()
{
    return idSupplier;
}

void InvoiceEntity::setIdSupplier(int value)
{
    idSupplier = value;
}

int InvoiceEntity::getIdCustomer()
{
    return idCustomer;
}

void InvoiceEntity::setIdCustomer(int value)
{
    idCustomer = value;
}

int InvoiceEntity::getFactureNumber()
{
    return factureNumber;
}

void InvoiceEntity::setFactureNumber(int value)
{
    factureNumber = value;
}

QList<ItemEntity*> InvoiceEntity::getItems()
{
    return items;
}

void InvoiceEntity::addItem(ItemEntity* value)
{
    items.push_back(value);
}

InvoiceType InvoiceEntity::getInvoiceType()
{
    return invoiceType;
}

void InvoiceEntity::setInvoiceType(InvoiceType value)
{
    invoiceType = value;
}
