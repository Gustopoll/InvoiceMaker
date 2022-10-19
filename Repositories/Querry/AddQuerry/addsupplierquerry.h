#ifndef ADDSUPPLIERQUERRY_H
#define ADDSUPPLIERQUERRY_H

#include <Entities/supplierentity.h>
#include <Repositories/Querry/AddQuerry/addquerry.h>

class AddSupplierQuerry : public AddQuerry
{
public:
    AddSupplierQuerry();

    bool Add(SupplierEntity* entity);
    int GetInsertedID();

protected:
    QString nameTable;
    int id;
};

#endif // ADDSUPPLIERQUERRY_H
