#include "deletecustomersavedquerry.h"
#include "deleteinvoicequerry.h"
#include "deleteitemquerry.h"
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
    auto items = entity->getItems();

    DeleteItemQuerry deleteItem;
    for (int i = 0 ; i < items.size(); i++)
    {
        deleteItem.Delete(items[i]->getId());
    }

    DeleteSupplierSavedQuerry s;
    DeleteCustomerSavedQuerry c;
    value |= s.Delete(entity->getSupplierSaved()->getId());
    value |= c.Delete(entity->getCustomerSaved()->getId());
    value |= DeleteQuerry::Delete(id, nameTable);
    delete entity;
    return value;
}
