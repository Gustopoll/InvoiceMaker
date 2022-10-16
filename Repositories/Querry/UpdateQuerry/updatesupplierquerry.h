#ifndef UPDATESUPPLIERQUERRY_H
#define UPDATESUPPLIERQUERRY_H

#include <Repositories/Querry/UpdateQuerry/updatequerry.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Entities/supplierentity.h>

class UpdateSupplierQuerry : public UpdateQuerry
{
public:
    UpdateSupplierQuerry();

    bool UpdateParameter(int id, QString param, QString value);
    bool Update(SupplierEntity* entity);

protected:
    QString nameTable;
};

#endif // UPDATESUPPLIERQUERRY_H
