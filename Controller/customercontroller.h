#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

#include <QComboBox>
#include <QString>
#include <Entities/customerentity.h>
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>

class CustomerController
{
public:
    CustomerController();

    void SetCustomers(QString firstValue, QComboBox* comboBox);
    void Update();

    CustomerEntity* GetEntityByIndex(int index);

private:
    QList<CustomerEntity*> listCustomers;
};

#endif // CUSTOMERCONTROLLER_H
