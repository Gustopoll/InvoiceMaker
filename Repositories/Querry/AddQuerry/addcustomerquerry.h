#ifndef ADDCUSTOMERQUERRY_H
#define ADDCUSTOMERQUERRY_H

#include <Entities/customerentity.h>
#include <Repositories/Querry/AddQuerry/addquerry.h>

class AddCustomerQuerry : public AddQuerry
{
public:
    AddCustomerQuerry();

    bool Add(CustomerEntity* entity);

protected:
    QString nameTable;
};

#endif // ADDCUSTOMERQUERRY_H
