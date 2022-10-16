#include "payerdphentity.h"

PayerDPHEntity::PayerDPHEntity()
{
    dic = "";
    icdph = "";
}

QString PayerDPHEntity::getIcdph()
{
    return icdph;
}

void PayerDPHEntity::setIcdph(QString value)
{
    icdph = value;
}

QString PayerDPHEntity::getDic()
{
    return dic;
}

void PayerDPHEntity::setDic(QString value)
{
    dic = value;
}
