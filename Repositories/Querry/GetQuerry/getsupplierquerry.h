#ifndef GETSUPPLIERQUERRY_H
#define GETSUPPLIERQUERRY_H

#include <Entities/supplierentity.h>
#include <Repositories/Querry/GetQuerry/getquerry.h>

class GetSupplierQuerry : public GetQuerry
{
public:
    GetSupplierQuerry();

    int GetAdressId(int idSupplier);
    int GetBankInfoId(int idSupplier);

    SupplierEntity* GetOneById(int id);
    QList<SupplierEntity*> GetAll();
    QList<SupplierEntity*> GetAllNoDeleted();

protected:
    QString nameTable;
};

#endif // GETSUPPLIERQUERRY_H
