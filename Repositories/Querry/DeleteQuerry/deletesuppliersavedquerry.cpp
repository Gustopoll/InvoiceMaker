#include "deletesuppliersavedquerry.h"
#include <Repositories/Querry/GetQuerry/getsuppliersavedquerry.h>

DeleteSupplierSavedQuerry::DeleteSupplierSavedQuerry()
{
    nameTable = "suppliersaved";
}

bool DeleteSupplierSavedQuerry::Delete(int id)
{
    bool value = false;
    GetSupplierSavedQuerry q;
    auto addressID = q.GetAdressId(id);
    auto bankinfoID = q.GetBankInfoId(id);

    value |= DeleteAdress(addressID);
    value |= DeleteBankInfo(bankinfoID);
    value |= DeleteQuerry::Delete(id, nameTable);
    return value;
}
