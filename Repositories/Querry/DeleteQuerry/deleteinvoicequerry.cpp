#include "deletecustomersavedquerry.h"
#include "deleteinvoicequerry.h"
#include "deletesuppliersavedquerry.h"
#include <Repositories/Querry/GetQuerry/getinvoicequerry.h>

DeleteInvoiceQuerry::DeleteInvoiceQuerry()
{
    nameTable = "invoice";
}

bool DeleteInvoiceQuerry::Delete(int id)
{
    bool value = false;
    GetInvoiceQuerry q;
    auto entity = q.GetOneById(id);
    DeleteSupplierSavedQuerry s;
    DeleteCustomerSavedQuerry c;
    value |= s.Delete(entity->getSupplierSaved()->getId());
    value |= c.Delete(entity->getCustomerSaved()->getId());
    value |= DeleteQuerry::Delete(id, nameTable);
    delete entity;
    return value;
}
