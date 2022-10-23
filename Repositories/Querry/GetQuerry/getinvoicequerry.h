#ifndef GETINVOICEQUERRY_H
#define GETINVOICEQUERRY_H

#include <Repositories/Querry/GetQuerry/getquerry.h>
#include <Entities/invoiceentity.h>

class GetInvoiceQuerry : public GetQuerry
{
public:
    GetInvoiceQuerry();

    InvoiceEntity* GetOneById(int id);
    QList<InvoiceEntity*> GetAll();
    QList<InvoiceEntity*> GetAllWhere(int year, int month, int idSupplier);

protected:
    QString nameTable;

    QList<InvoiceEntity*> Get(QString querry);
};

#endif // GETINVOICEQUERRY_H
