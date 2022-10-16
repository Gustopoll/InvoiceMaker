#ifndef ADDSUPPLIERQUERRY_H
#define ADDSUPPLIERQUERRY_H

#include <Entities/supplierentity.h>
#include <Repositories/Querry/AddQuerry/addquerry.h>

class AddSupplierQuerry : public AddQuerry
{
public:
    AddSupplierQuerry();

    bool Add(SupplierEntity* entity);

protected:
    QString nameTable;
};

#endif // ADDSUPPLIERQUERRY_H
