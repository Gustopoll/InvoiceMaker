#include "suppliercontroller.h"


SupplierController::SupplierController()
{
    listSuppliers = QList<SupplierEntity*>();
}

void SupplierController::SetSuppliers(QString firstValue, QComboBox *comboBox)
{
    comboBox->clear();
    comboBox->addItem(firstValue);

    if (listSuppliers.isEmpty() == true)
    {
        GetSupplierQuerry q;
        auto suppliers = q.GetAllNoDeleted();
        for (int i = 0; i < suppliers.size(); i++)
        {
            comboBox->addItem(suppliers[i]->getName());
            listSuppliers.push_back(suppliers[i]);
        }
        return;
    }

    for (int i = 0; i < listSuppliers.size(); i++)
    {
        comboBox->addItem(listSuppliers[i]->getName());
    }
}

void SupplierController::Update()
{
    qDeleteAll(listSuppliers);
    listSuppliers.clear();
}

SupplierEntity *SupplierController::GetEntityByIndex(int index)
{
    if (index < 0)
        return nullptr;
    if (listSuppliers.isEmpty() == true)
    {
        GetSupplierQuerry q;
        auto suppliers = q.GetAllNoDeleted();
        for (int i = 0; i < suppliers.size(); i++)
        {
            listSuppliers.push_back(suppliers[i]);
        }
    }
    return listSuppliers[index];
}

SupplierEntity *SupplierController::GetEntityById(int id)
{
    if (id < 0)
        return nullptr;
    if (listSuppliers.isEmpty() == true)
    {
        GetSupplierQuerry q;
        auto suppliers = q.GetAllNoDeleted();
        for (int i = 0; i < suppliers.size(); i++)
        {
            listSuppliers.push_back(suppliers[i]);
        }
    }

    for (int i = 0; i < listSuppliers.size(); i++)
    {
        if (listSuppliers[i]->getId() == id)
            return listSuppliers[i];
    }
    return nullptr;
}

