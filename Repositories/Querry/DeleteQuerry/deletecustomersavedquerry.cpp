#include "deletecustomersavedquerry.h"
#include <Repositories/Querry/GetQuerry/getcustomersavedquerry.h>

DeleteCustomerSavedQuerry::DeleteCustomerSavedQuerry()
{
    nameTable = "customersaved";
}

bool DeleteCustomerSavedQuerry::Delete(int id)
{
    bool value = false;
    GetCustomerSavedQuerry q;
    auto adressID = q.GetAdressId(id);

    value |= DeleteAdress(adressID);
    value |= DeleteQuerry::Delete(id, nameTable);
    return value;
}

