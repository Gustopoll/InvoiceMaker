#ifndef DELETECUSTOMERSAVEDQUERRY_H
#define DELETECUSTOMERSAVEDQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletecustomerquerry.h>

class DeleteCustomerSavedQuerry : public DeleteCustomerQuerry
{
public:
    DeleteCustomerSavedQuerry();

    bool Delete(int id);
};

#endif // DELETECUSTOMERSAVEDQUERRY_H
