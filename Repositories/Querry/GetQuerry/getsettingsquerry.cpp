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
        entity->setIndexV(q.value("indexV").toInt());
        entity->setIndexD(q.value("indexD").toInt());
        entity->setIndexD2(q.value("indexD2").toInt());
        entity->setIndexS(q.value("indexS").toInt());
        entity->setDateV(helper.getDate(q.value("dateV").toString()));
        entity->setDateD(helper.getDate(q.value("dateD").toString()));
        entity->setDateS(helper.getDate(q.value("dateS").toString()));
        entity->setDPH(q.value("DPH").toDouble());
    }

    return entity;
}
