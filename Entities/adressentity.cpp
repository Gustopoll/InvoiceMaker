#include "adressentity.h"

AdressEntity::AdressEntity()
{

}

QString AdressEntity::getStreet()
{
    return street;
}

void AdressEntity::setStreet(QString value)
{
    street = value;
}

QString AdressEntity::getStreetNumber()
{
    return streetNumber;
}

void AdressEntity::setStreetNumber(QString value)
{
    streetNumber = value;
}

QString AdressEntity::getPsc()
{
    return psc;
}

void AdressEntity::setPsc(QString value)
{
    psc = value;
}

QString AdressEntity::getCity()
{
    return city;
}

void AdressEntity::setCity(QString value)
{
    city = value;
}

QString AdressEntity::getState()
{
    return state;
}

void AdressEntity::setState(QString value)
{
    state = value;
}

QString AdressEntity::getStreetWithNumber()
{
    return street + " " + streetNumber;
}

QString AdressEntity::getPSCWithCity()
{
    return psc + " " + city;
}

int AdressEntity::getId()
{
    return id;
}

void AdressEntity::setId(int value)
{
    id = value;
}
