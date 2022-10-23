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
    QString querry = "SELECT * FROM " + nameTable + " WHERE id = " + QString::number(id);
    auto entities = Get(querry);
    if (entities.size() > 0)
        return entities.last();
    return nullptr;
}

QList<InvoiceEntity*> GetInvoiceQuerry::GetAll()
{
    return Get("SELECT * FROM " + nameTable);
}

QList<InvoiceEntity *> GetInvoiceQuerry::GetAllWhere(int year, int month, int idSupplier)
{
    DateHelper helper;
    int lastMonth = month;
    if (month == 0) // this option allow to get all invoices from current year, from all months
    {
        month = 1;
        lastMonth = 12;
    }

    QString querry = "SELECT * FROM " + nameTable + " WHERE "
            "dateV BETWEEN '" + helper.toString(1,month,year) + "' AND '" +  helper.toString(31,lastMonth,year) + "' ";
    qDebug() << querry;
    return Get(querry);
}

QList<InvoiceEntity*> GetInvoiceQuerry::Get(QString querry)
{
    QSqlQuery q;
    DateHelper helper;
    q.prepare(querry);

    q.exec();
    lastError = q.lastError().text();

    QList<InvoiceEntity*> listEntities;
    while (q.next() == true)
    {
        InvoiceEntity* entity = new InvoiceEntity();

        entity->setId(q.value("id").toInt());
        entity->setInvoiceType((InvoiceType)q.value("invoicetype").toInt());
        entity->setPaymentMethon((Payment)q.value("payment").toInt());
        entity->setDateV(helper.getDateDB(q.value("dateV").toString()));
        entity->setDateD(helper.getDateDB(q.value("dateD").toString()));
        entity->setDateS(helper.getDateDB(q.value("dateS").toString()));
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
        listEntities.push_back(entity);
    }
    return listEntities;
}

