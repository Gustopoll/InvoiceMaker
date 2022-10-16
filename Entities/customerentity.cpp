#include "customerentity.h"

CustomerEntity::CustomerEntity()
{
    adress = new AdressEntity();
    payer = new PayerDPHEntity();
}

QString CustomerEntity::getName()
{
    return name;
}

void CustomerEntity::setName(QString value)
{
    name = value;
}

AdressEntity *CustomerEntity::getAdress()
{
    return adress;
}

void CustomerEntity::setAdress(AdressEntity *value)
{
    adress = value;
}


PayerDPHEntity *CustomerEntity::getPayer()
{
    return payer;
}

int CustomerEntity::getId()
{
    return id;
}

void CustomerEntity::setId(int value)
{
    id = value;
}

QString CustomerEntity::getIco()
{
    return ico;
}

void CustomerEntity::setIco(QString value)
{
    ico = value;
}
