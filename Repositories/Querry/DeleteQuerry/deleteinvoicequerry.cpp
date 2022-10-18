#include "deleteinvoicequerry.h"

DeleteInvoiceQuerry::DeleteInvoiceQuerry()
{
    nameTable = "invoice";
}

bool DeleteInvoiceQuerry::Delete(int id)
{
    return DeleteQuerry::Delete(id, nameTable);
}
