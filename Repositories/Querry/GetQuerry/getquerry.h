#ifndef GETQUERRY_H
#define GETQUERRY_H

#include <QString>
#include <QList>
#include <Entities/supplierentity.h>
#include <Entities/bankinfoentity.h>
#include <Entities/customerentity.h>
#include <Repositories/Querry/basequerry.h>

class GetQuerry : public BaseQuerry
{
public:
    GetQuerry();

    int GetAdressId(int id, QString nameTable);
    int GetBankInfoId(int id, QString nameTable);

protected:
    BankInfoEntity *GetBankInfoById(int id);
    AdressEntity *GetAdressById(int id);
};

#endif // GETQUERRY_H
