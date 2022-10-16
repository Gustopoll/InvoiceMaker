#include "getcustomerquerry.h"

GetCustomerQuerry::GetCustomerQuerry()
{
    nameTable = "customer";
}

int GetCustomerQuerry::GetAdressId(int idCustomer)
{
    return GetQuerry::GetAdressId(idCustomer,nameTable);
}

CustomerEntity *GetCustomerQuerry::GetOneById(int id)
{
    QSqlQuery q;

    q.prepare("SELECT * FROM " + nameTable + " WHERE id = :value;");
    q.bindValue(":value",id);

    q.exec();
    lastError = q.lastError().text();
    q.next();

    CustomerEntity* e = new CustomerEntity();
    e->setId(q.value("id").toInt());
    e->setName(q.value("name").toString());
    e->setIco(q.value("ico").toString());

    e->getPayer()->setDic(q.value("dic").toString());
    e->getPayer()->setIcdph(q.value("icdph").toString());

    e->setAdress(GetAdressById(q.value("idadress").toInt()));

    return e;
}

QList<CustomerEntity *> GetCustomerQuerry::GetAllNoDeleted()
{
    QSqlQuery q;

    bool isOK = q.prepare("SELECT * FROM " + nameTable + " WHERE isdeleted = 0;");
    q.exec();
    lastError = q.lastError().text();

    QList<CustomerEntity*> ret;
    if (isOK == true)
    {
        while (q.next() == true)
        {
            CustomerEntity* e = new CustomerEntity();
            e->setId(q.value("id").toInt());
            e->setName(q.value("name").toString());
            e->setIco(q.value("ico").toString());

            e->getPayer()->setDic(q.value("dic").toString());
            e->getPayer()->setIcdph(q.value("icdph").toString());

            e->setAdress(GetAdressById(q.value("idadress").toInt()));

            ret.append(e);
        }
    }
    return ret;
}
