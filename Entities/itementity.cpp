#include "itementity.h"

ItemEntity::ItemEntity()
{

}

int ItemEntity::getId()
{
    return id;
}

void ItemEntity::setId(int value)
{
    id = value;
}

double ItemEntity::getPrice()
{
    return price;
}

void ItemEntity::setPrice(double value)
{
    price = value;
}

int ItemEntity::getCount()
{
    return count;
}

void ItemEntity::setCount(int value)
{
    count = value;
}

QString ItemEntity::getDescription()
{
    return description;
}

void ItemEntity::setDescription(QString value)
{
    description = value;
}

double ItemEntity::getDPH()
{
    return dph;
}

void ItemEntity::setDPH(double value)
{
    dph = value;
}

double ItemEntity::getTotalPrice()
{
    return totalPrice;
}

void ItemEntity::setTotalPrice(double value)
{
    totalPrice = value;
}
