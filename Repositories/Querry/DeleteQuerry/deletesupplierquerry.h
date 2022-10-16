#ifndef DELETESUPPLIERQUERRY_H
#define DELETESUPPLIERQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletequerry.h>

class DeleteSupplierQuerry : public DeleteQuerry
{
public:
    DeleteSupplierQuerry();

    bool Delete(int id);

protected:
    QString nameTable;
};

#endif // DELETESUPPLIERQUERRY_H
