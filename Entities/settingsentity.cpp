#include "settingsentity.h"

SettingsEntity::SettingsEntity()
{

}

int SettingsEntity::getId()
{
    return id;
}

void SettingsEntity::setId(int value)
{
    id = value;
}

int SettingsEntity::getIndexV()
{
    return indexV;
}

void SettingsEntity::setIndexV(int value)
{
    indexV = value;
}

int SettingsEntity::getIndexD()
{
    return indexD;
}

void SettingsEntity::setIndexD(int value)
{
    indexD = value;
}

int SettingsEntity::getIndexD2()
{
    return indexD2;
}

void SettingsEntity::setIndexD2(int value)
{
    indexD2 = value;
}

int SettingsEntity::getIndexS()
{
    return indexS;
}

void SettingsEntity::setIndexS(int value)
{
    indexS = value;
}

QDate SettingsEntity::getDateV()
{
    return dateV;
}

void SettingsEntity::setDateV(QDate value)
{
    dateV = value;
}

QDate SettingsEntity::getDateD()
{
    return dateD;
}

void SettingsEntity::setDateD(QDate value)
{
    dateD = value;
}

QDate SettingsEntity::getDateS()
{
    return dateS;
}

void SettingsEntity::setDateS(QDate value)
{
    dateS = value;
}

double SettingsEntity::getDPH()
{
    return DPH;
}

void SettingsEntity::setDPH(double value)
{
    DPH = value;
}

int SettingsEntity::getIndexStyle()
{
    return indexStyle;
}

void SettingsEntity::setIndexStyle(int value)
{
    indexStyle = value;
}
