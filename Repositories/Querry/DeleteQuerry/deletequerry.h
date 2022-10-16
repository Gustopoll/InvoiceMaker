#ifndef DELETEQUERRY_H
#define DELETEQUERRY_H

#include <Repositories/Querry/basequerry.h>

class DeleteQuerry : public BaseQuerry
{
public:
    DeleteQuerry();

    bool Delete(int id, QString nameTable);
};

#endif // DELETEQUERRY_H
