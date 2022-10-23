#include "addsettingsquerry.h"

#include <Extensions/datehelper.h>

AddSettingsQuerry::AddSettingsQuerry()
{
    nameTable = "settings";
}

bool AddSettingsQuerry::Add(SettingsEntity *entity)
{
    if (entity == nullptr)
        return SetErrorMSG("null " + nameTable + " entity object");

    DateHelper helper;
    QSqlQuery q;
    q.prepare("INSERT INTO " + nameTable + " (indexV, indexD, indexD2, indexS, dateV, dateD, dateS, DPH) "
    "VALUES (:indexV_value, :indexD_value, :indexD2_value, :indexS_value, :dateV_value, :dateD_value, :dateS_value, :DPH_value);");

    q.bindValue(":indexV_value",entity->getIndexV());
    q.bindValue(":indexD_value",entity->getIndexD());
    q.bindValue(":indexD2_value",entity->getIndexD2());
    q.bindValue(":indexS_value",entity->getIndexS());
    q.bindValue(":dateV_value",helper.toStringDB(entity->getDateV()));
    q.bindValue(":dateD_value",helper.toStringDB(entity->getDateD()));
    q.bindValue(":dateS_value",helper.toStringDB(entity->getDateS()));
    q.bindValue(":DPH_value",entity->getDPH());

    q.exec();

    return SetErrorMSG(q.lastError());
}
