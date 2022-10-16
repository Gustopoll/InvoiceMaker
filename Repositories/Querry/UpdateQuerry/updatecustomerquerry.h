#ifndef UPDATECUSTOMERQUERRY_H
#define UPDATECUSTOMERQUERRY_H

#include <Repositories/Querry/UpdateQuerry/updatequerry.h>
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>
#include <Entities/customerentity.h>

class UpdateCustomerQuerry : public UpdateQuerry
{
public:
    UpdateCustomerQuerry();

    bool UpdateParameter(int id, QString param, QString value);
    bool Update(CustomerEntity* entity);

protected:
    QString nameTable;
};

#endif // UPDATECUSTOMERQUERRY_H
