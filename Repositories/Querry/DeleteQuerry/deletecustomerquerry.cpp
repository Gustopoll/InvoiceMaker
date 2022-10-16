#include "deletecustomerquerry.h"

DeleteCustomerQuerry::DeleteCustomerQuerry()
{
    nameTable = "customer";
}

bool DeleteCustomerQuerry::Delete(int id)
{
    //TODO delete also adress
    return DeleteQuerry::Delete(id, nameTable);
}
