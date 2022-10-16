#ifndef ADDQUERRY_H
#define ADDQUERRY_H

#include <Entities/supplierentity.h>
#include <Entities/customerentity.h>
#include <Repositories/Querry/basequerry.h>

class AddQuerry : public BaseQuerry
{
public:
    AddQuerry();

protected:
    int AddBankInfo(BankInfoEntity* entity);
    int AddAdress(AdressEntity* entity);
};

#endif // ADDQUERRY_H
