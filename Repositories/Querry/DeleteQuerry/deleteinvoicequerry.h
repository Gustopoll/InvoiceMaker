#ifndef DELETEINVOICEQUERRY_H
#define DELETEINVOICEQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletequerry.h>
#include <Entities/invoiceentity.h>

class DeleteInvoiceQuerry : public DeleteQuerry
{
public:
    DeleteInvoiceQuerry();

    bool Delete(int id);

protected:
    QString nameTable;
};

#endif // DELETEINVOICEQUERRY_H
