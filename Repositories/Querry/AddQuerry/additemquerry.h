#ifndef ADDITEMQUERRY_H
#define ADDITEMQUERRY_H

#include <Repositories/Querry/AddQuerry/addquerry.h>
#include <Entities/itementity.h>

class AddItemQuerry : public AddQuerry
{
public:
    AddItemQuerry();

    bool Add(ItemEntity* entity, int id);
protected:
    QString nameTable;
    int id;
};

#endif // ADDITEMQUERRY_H
