#ifndef DELETESUPPLIERSAVEDQUERRY_H
#define DELETESUPPLIERSAVEDQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletesupplierquerry.h>

class DeleteSupplierSavedQuerry : public DeleteSupplierQuerry
{
public:
    DeleteSupplierSavedQuerry();

    bool Delete(int id);
};

#endif // DELETESUPPLIERSAVEDQUERRY_H
