#ifndef GETCUSTOMERQUERRY_H
#define GETCUSTOMERQUERRY_H

#include <Entities/customerentity.h>
#include <Repositories/Querry/GetQuerry/getquerry.h>

class GetCustomerQuerry : public GetQuerry
{
public:
    GetCustomerQuerry();

    int GetAdressId(int idCustomer);

    CustomerEntity* GetOneById(int id);
    QList<CustomerEntity*> GetAllNoDeleted();

protected:
    QString nameTable;
};

#endif // GETCUSTOMERQUERRY_H
