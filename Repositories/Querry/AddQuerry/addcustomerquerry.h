#ifndef ADDCUSTOMERQUERRY_H
#define ADDCUSTOMERQUERRY_H

#include <Entities/customerentity.h>
#include <Repositories/Querry/AddQuerry/addquerry.h>

class AddCustomerQuerry : public AddQuerry
{
public:
    AddCustomerQuerry();

    bool Add(CustomerEntity* entity);
    int GetInsertedID();

protected:
    QString nameTable;
    int id;
};

#endif // ADDCUSTOMERQUERRY_H
