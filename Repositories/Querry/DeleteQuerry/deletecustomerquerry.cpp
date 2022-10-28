#include "deletecustomerquerry.h"
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>

DeleteCustomerQuerry::DeleteCustomerQuerry()
{
    nameTable = "customer";
}

bool DeleteCustomerQuerry::Delete(int id)
{
    bool value = false;
    GetCustomerQuerry q;
    auto adressID = q.GetAdressId(id);

    value |= DeleteAdress(adressID);
    value |= DeleteQuerry::Delete(id, nameTable);
    return value;
}
