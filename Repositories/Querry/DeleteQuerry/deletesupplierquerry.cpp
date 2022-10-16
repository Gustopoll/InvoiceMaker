#include "deletesupplierquerry.h"

DeleteSupplierQuerry::DeleteSupplierQuerry()
{
    nameTable = "supplier";
}

bool DeleteSupplierQuerry::Delete(int id)
{
    //TODO delete also adress and payer
    return DeleteQuerry::Delete(id, nameTable);
}
