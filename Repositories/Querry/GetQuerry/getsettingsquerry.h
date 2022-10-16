#ifndef GETSETTINGSQUERRY_H
#define GETSETTINGSQUERRY_H

#include <Repositories/Querry/GetQuerry/getquerry.h>
#include <Entities/settingsentity.h>

class GetSettingsQuerry : public GetQuerry
{
public:
    GetSettingsQuerry();

    SettingsEntity* Get();

protected:
    QString nameTable;
};

#endif // GETSETTINGSQUERRY_H
