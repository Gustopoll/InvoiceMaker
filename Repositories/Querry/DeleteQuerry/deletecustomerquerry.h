#ifndef DELETECUSTOMERQUERRY_H
#define DELETECUSTOMERQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletequerry.h>

class DeleteCustomerQuerry : public DeleteQuerry
{
public:
    DeleteCustomerQuerry();

    bool Delete(int id);

protected:
    QString nameTable;
};

#endif // DELETECUSTOMERQUERRY_H
