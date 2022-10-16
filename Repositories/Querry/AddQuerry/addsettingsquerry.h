#ifndef ADDSETTINGSQUERRY_H
#define ADDSETTINGSQUERRY_H

#include <Repositories/Querry/basequerry.h>
#include <Entities/settingsentity.h>

class AddSettingsQuerry : public BaseQuerry
{
public:
    AddSettingsQuerry();

    bool Add(SettingsEntity* entity);

protected:
    QString nameTable;
};

#endif // ADDSETTINGSQUERRY_H
