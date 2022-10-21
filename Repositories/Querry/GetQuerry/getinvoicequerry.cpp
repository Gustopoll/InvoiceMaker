#include "getcustomersavedquerry.h"
#include "getinvoicequerry.h"
#include "getsuppliersavedquerry.h"

#include <Extensions/datehelper.h>

GetInvoiceQuerry::GetInvoiceQuerry()
{
    nameTable = "invoice";
}

InvoiceEntity *GetInvoiceQuerry::GetOneById(int id)
{

    QSqlQuery q;
    DateHelper helper;
    q.prepare("SELECT * FROM " + nameTable + " WHERE id = :value");
    q.bindValue(":value",id);

    q.exec();
    q.next();
    lastError = q.lastError().text();

    InvoiceEntity* entity = new InvoiceEntity();

    entity->setId(q.value("id").toInt());
    entity->setInvoiceType((InvoiceType)q.value("invoicetype").toInt());
    entity->setPaymentMethon((Payment)q.value("payment").toInt());
    entity->setDateV(helper.getDate(q.value("dateV").toString()));
    entity->setDateD(helper.getDate(q.value("dateD").toString()));
    entity->setDateS(helper.getDate(q.value("dateS").toString()));
    entity->setFactureNumber(q.value("factureNumber").toInt());
    entity->setIdSupplier(q.value("idSupplier").toInt());
    entity->setIdCustomer(q.value("idCustomer").toInt());

    GetSupplierSavedQuerry sq;
    auto supplier = sq.GetOneById(q.value("idSupplierSaved").toInt());
    entity->setSupplierSaved(supplier);
    GetCustomerSavedQuerry cq;
    auto customer = cq.GetOneById(q.value("idCustomerSaved").toInt());
    entity->setCustomerSaved(customer);

    /*
    for (int i = 0; i < items.size(); i++)
        entity->addItem(items[i]);
    */
    qDebug() << q.value("dateV").toString();
    return entity;
}

