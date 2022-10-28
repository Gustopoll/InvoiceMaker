#ifndef DELETEQUERRY_H
#define DELETEQUERRY_H

#include <Repositories/Querry/basequerry.h>

class DeleteQuerry : public BaseQuerry
{
public:
    DeleteQuerry();

    bool Delete(int id, QString nameTable);

    bool DeleteAdress(int id);
    bool DeleteBankInfo(int id);
};

#endif // DELETEQUERRY_H
