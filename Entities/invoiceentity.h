#ifndef INVOICEENTITY_H
#define INVOICEENTITY_H

#include <QString>
#include <QDate>
#include <QList>
#include <Entities/customerentity.h>
#include <Entities/supplierentity.h>
#include <Entities/itementity.h>
#include <Entities/PaymentMethod.h>
#include <Entities/bankinfoentity.h>
#include <Entities/InvoiceType.h>

class InvoiceEntity
{
public:
    InvoiceEntity();

    SupplierEntity *getSupplierSaved();
    void setSupplierSaved(SupplierEntity *value);

    CustomerEntity *getCustomerSaved();
    void setCustomerSaved(CustomerEntity *value);

    Payment getPaymentMethon();
    void setPaymentMethon(Payment value);

    QDate getDateV();
    void setDateV(QDate value);

    QDate getDateD();
    void setDateD(QDate value);

    QDate getDateS();
    void setDateS(QDate value);

    int getId();
    void setId(int value);

    int getIdSupplier();
    void setIdSupplier(int value);

    int getIdCustomer();
    void setIdCustomer(int value);

    InvoiceType getInvoiceType();
    void setInvoiceType(InvoiceType value);

    int getFactureNumber();
    void setFactureNumber(int value);

    QList<ItemEntity*> getItems();
    void addItem(ItemEntity* value);
    double GetTotalPrice();

private:
    int id;

    int idSupplier;
    int idCustomer;

    QDate dateV;
    QDate dateD;
    QDate dateS;

    Payment paymentMethon;
    InvoiceType invoiceType;
    int factureNumber;

    SupplierEntity *supplierSaved;
    CustomerEntity *customerSaved;

    QList<ItemEntity *> items;
};

#endif // INVOICEENTITY_H
