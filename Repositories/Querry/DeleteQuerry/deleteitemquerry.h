#ifndef DELETEITEMQUERRY_H
#define DELETEITEMQUERRY_H

#include <Repositories/Querry/DeleteQuerry/deletequerry.h>

class DeleteItemQuerry : public DeleteQuerry
{
public:
    DeleteItemQuerry();

    bool Delete(int id);

private:
    QString nameTable;
};

#endif // DELETEITEMQUERRY_H
