#ifndef SUPPLIERCONTROLLER_H
#define SUPPLIERCONTROLLER_H

#include <QString>
#include <QComboBox>
#include <QList>
#include <Entities/supplierentity.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>

class SupplierController
{
public:
    SupplierController();

    void SetSuppliers(QString firstValue, QComboBox* comboBox);
    void Update();

    SupplierEntity* GetEntityByIndex(int index);
    SupplierEntity* GetEntityById(int id);

private:
    QList<SupplierEntity*> listSuppliers;
};

#endif // SUPPLIERCONTROLLER_H
