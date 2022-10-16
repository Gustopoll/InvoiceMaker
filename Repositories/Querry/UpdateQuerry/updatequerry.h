#ifndef UPDATEQUERRY_H
#define UPDATEQUERRY_H

#include <Repositories/Querry/basequerry.h>
#include <Entities/adressentity.h>
#include <Entities/bankinfoentity.h>

class UpdateQuerry : public BaseQuerry
{
public:
    UpdateQuerry();

    bool UpdateParameter(int id, QString param, QString value, QString nameTable);

protected:
    bool UpdateAdress(AdressEntity *entity);
    bool UpdateBankInfo(BankInfoEntity *entity);
};

#endif // UPDATEQUERRY_H
