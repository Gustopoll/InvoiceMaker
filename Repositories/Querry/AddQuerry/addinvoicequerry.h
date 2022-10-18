#ifndef ADDINVOICEQUERRY_H
#define ADDINVOICEQUERRY_H

#include <Entities/invoiceentity.h>
#include <Repositories/Querry/AddQuerry/addquerry.h>

class AddInvoiceQuerry : public AddQuerry
{
public:
    AddInvoiceQuerry();

    bool Add(InvoiceEntity *entity);

protected:
    QString nameTable;
};

#endif // ADDINVOICEQUERRY_H
