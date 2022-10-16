#include "customercontroller.h"

#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>

CustomerController::CustomerController()
{

}

void CustomerController::SetCustomers(QString firstValue, QComboBox *comboBox)
{
    comboBox->clear();
    comboBox->addItem(firstValue);

    if (listCustomers.isEmpty() == true)
    {
        GetCustomerQuerry q;
        auto customers = q.GetAllNoDeleted();
        for (int i = 0; i < customers.size(); i++)
        {
            comboBox->addItem(customers[i]->getName());
            listCustomers.push_back(customers[i]);
        }
        return;
    }

    for (int i = 0; i < listCustomers.size(); i++)
    {
        comboBox->addItem(listCustomers[i]->getName());
    }
}

void CustomerController::Update()
{
    qDeleteAll(listCustomers);
    listCustomers.clear();
}

CustomerEntity *CustomerController::GetEntityByIndex(int index)
{
    if (index < 0)
        return nullptr;
    if (listCustomers.isEmpty() == true)
    {
        GetCustomerQuerry q;
        auto customers = q.GetAllNoDeleted();
        for (int i = 0; i < customers.size(); i++)
        {
            listCustomers.push_back(customers[i]);
        }
    }
    return listCustomers[index];
}
