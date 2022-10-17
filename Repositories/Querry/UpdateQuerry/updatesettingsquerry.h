#ifndef UPDATESETTINGSQUERRY_H
#define UPDATESETTINGSQUERRY_H

#include <Entities/settingsentity.h>
#include <Repositories/Querry/UpdateQuerry/updatequerry.h>

class UpdateSettingsQuerry : public UpdateQuerry
{
public:
    UpdateSettingsQuerry();

    bool Update(SettingsEntity* entity);

protected:
    QString nameTable;
};

#endif // UPDATESETTINGSQUERRY_H
