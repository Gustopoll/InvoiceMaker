#ifndef GETITEMQUERRY_H
#define GETITEMQUERRY_H

#include <Repositories/Querry/GetQuerry/getquerry.h>
#include <Entities/itementity.h>

class GetItemQuerry : public GetQuerry
{
public:
    GetItemQuerry();

    QList<ItemEntity*> GetAllByInvoiceID(int id);

protected:
    QString nameTable;

    QList<ItemEntity*> Get(QString querry);
};

#endif // GETITEMQUERRY_H
