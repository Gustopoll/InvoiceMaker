#ifndef GETINVOICEQUERRY_H
#define GETINVOICEQUERRY_H

#include <Repositories/Querry/GetQuerry/getquerry.h>
#include <Entities/invoiceentity.h>

class GetInvoiceQuerry : public GetQuerry
{
public:
    GetInvoiceQuerry();

    InvoiceEntity* GetOneById(int id);
    InvoiceEntity* GetAll();
protected:
    QString nameTable;
};

#endif // GETINVOICEQUERRY_H
