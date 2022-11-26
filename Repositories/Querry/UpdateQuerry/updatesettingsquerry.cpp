#include "updatesettingsquerry.h"
#include <Repositories/Querry/GetQuerry/getsettingsquerry.h>
#include <Extensions/datehelper.h>

UpdateSettingsQuerry::UpdateSettingsQuerry()
{
    nameTable = "settings";
}

bool UpdateSettingsQuerry::Update(SettingsEntity *entity)
{
    GetSettingsQuerry getQ;
    DateHelper helper;
    int id = getQ.getId();
    if (id == -1)
        return SetErrorMSG("No settings table in db");

    QSqlQuery q;
    q.prepare("UPDATE " + nameTable + " SET indexV = :indexV_value, "
                                  "indexD = :indexD_value, "
                                  "indexD2 = :indexD2_value, "
                                  "indexS = :indexS_value, "
                                  "dateV = :dateV_value, "
                                  "dateD = :dateD_value, "
                                  "dateS = :dateS_value, "
                                  "DPH = :DPH_value, "
                                  "indexStyle = :indexStyle_value "
                                  "WHERE id = :id_value;");


    q.bindValue(":indexV_value",entity->getIndexV());
    q.bindValue(":indexD_value",entity->getIndexD());
    q.bindValue(":indexD2_value",entity->getIndexD2());
    q.bindValue(":indexS_value",entity->getIndexS());
    q.bindValue(":dateV_value",helper.toStringDB(entity->getDateV()));
    q.bindValue(":dateD_value",helper.toStringDB(entity->getDateD()));
    q.bindValue(":dateS_value",helper.toStringDB(entity->getDateS()));
    q.bindValue(":DPH_value",entity->getDPH());
    q.bindValue(":indexStyle_value",entity->getIndexStyle());

    q.bindValue(":id_value",id);
    q.exec();

    return SetErrorMSG(q.lastError().text());
}
