#include "addcustomersavedquerry.h"
#include "addinvoicequerry.h"
#include "addsuppliersavedquerry.h"


AddInvoiceQuerry::AddInvoiceQuerry()
{
    nameTable = "invoice";
}

bool AddInvoiceQuerry::Add(InvoiceEntity *entity)
{
    if (entity == nullptr)
        return SetErrorMSG("null " + nameTable + " entity object");

    AddSupplierSavedQuerry sq;
    if (sq.Add(entity->getSupplierSaved()) == false)
        return SetErrorMSG(lastError);
    AddCustomerSavedQuerry cq;
    if (cq.Add(entity->getCustomerSaved()) == false)
        return SetErrorMSG(lastError);

    QSqlQuery q;
    q.prepare("INSERT INTO " + nameTable + " (idSupplier, idCustomer, idSupplierSaved, idCustomerSaved, dateV, dateD, dateS, payment, invoicetype, factureNumber) "
    "VALUES (:idSupplier_value, :idCustomer_value, :idSupplierSaved_value, :idCustomerSaved_value, :dateV_value, :dateD_value, :dateS_value,"
    ":payment_value, :invoicetype_value, :factureNumber_value);");

    q.bindValue(":idSupplier_value",entity->getIdSupplier());
    q.bindValue(":idCustomer_value",entity->getIdCustomer());
    q.bindValue(":idSupplierSaved_value",sq.GetInsertedID());
    q.bindValue(":idCustomerSaved_value",cq.GetInsertedID());
    q.bindValue(":dateV_value",entity->getDateV());
    q.bindValue(":dateD_value",entity->getDateD());
    q.bindValue(":dateS_value",entity->getDateS());
    q.bindValue(":payment_value",(int)entity->getPaymentMethon());
    q.bindValue(":invoicetype_value",(int)entity->getInvoiceType());
    q.bindValue(":factureNumber_value",entity->getFactureNumber());

    q.exec();

    return SetErrorMSG(q.lastError());
}
