#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <Entities/settingsentity.h>

class SettingsController
{
public:
    SettingsController();

    bool Build();
    void setComboBoxV(QComboBox *value);
    void setComboBoxDday(QComboBox *value);
    void setComboBoxDmonth(QComboBox *value);
    void setComboBoxS(QComboBox *value);
    void setDateEditV(QDateEdit *value);
    void setDateEditD(QDateEdit *value);
    void setDateEditS(QDateEdit *value);
    void setDPH(QDoubleSpinBox *value);
    void setLabelPart1(QLabel *value);
    void setLabelPart2(QLabel *value);

    SettingsEntity* CreateEnity();
    void SetSettingsEntity(SettingsEntity *entity);
    void SetFromDB();
    void Update();

    void comboBoxDdayUpate(int index);
    void comboBoxVUpdate(int index);

private:
    void UpdateDDate();
    void UpdateSDate();

    QComboBox* comboBoxV;
    QComboBox* comboBoxDday;
    QComboBox* comboBoxDmonth;
    QComboBox* comboBoxS;
    QDateEdit* dateEditV;
    QDateEdit* dateEditD;
    QDateEdit* dateEditS;
    QDoubleSpinBox* doubleSpinBoxDPH;
    QLabel* labelPart1;
    QLabel* labelPart2;
};

#endif // SETTINGSCONTROLLER_H
