#include "deletesupplierquerry.h"
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>

DeleteSupplierQuerry::DeleteSupplierQuerry()
{
    nameTable = "supplier";
}

bool DeleteSupplierQuerry::Delete(int id)
{
    bool value = false;
    GetSupplierQuerry q;
    auto addressID = q.GetAdressId(id);
    auto bankinfoID = q.GetBankInfoId(id);

    value |= DeleteAdress(addressID);
    value |= DeleteBankInfo(bankinfoID);
    value |= DeleteQuerry::Delete(id, nameTable);
    return value;
}
