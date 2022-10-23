#include "getsettingsquerry.h"

#include <Extensions/datehelper.h>

GetSettingsQuerry::GetSettingsQuerry()
{
    nameTable = "settings";
}

SettingsEntity *GetSettingsQuerry::Get()
{
    QSqlQuery q;
    DateHelper helper;
    q.prepare("SELECT * FROM " + nameTable);
    q.exec();
    lastError = q.lastError().text();

    SettingsEntity* entity = nullptr;
    if (q.next() == true)
    {
        entity = new SettingsEntity();
        entity->setId(q.value("id").toInt());
        entity->setIndexV(q.value("indexV").toInt());
        entity->setIndexD(q.value("indexD").toInt());
        entity->setIndexD2(q.value("indexD2").toInt());
        entity->setIndexS(q.value("indexS").toInt());
        entity->setDateV(helper.getDateDB(q.value("dateV").toString()));
        entity->setDateD(helper.getDateDB(q.value("dateD").toString()));
        entity->setDateS(helper.getDateDB(q.value("dateS").toString()));
        entity->setDPH(q.value("DPH").toDouble());
    }

    return entity;
}

int GetSettingsQuerry::getId()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM " + nameTable);
    q.exec();
    lastError = q.lastError().text();
    int idValue = -1;
    if (q.next() == true)
    {
        idValue = q.value("id").toInt();
    }
    return idValue;
}
