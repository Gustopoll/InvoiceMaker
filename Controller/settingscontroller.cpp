#include "settingscontroller.h"

#include <Extensions/datehelper.h>
#include <QStyleFactory>
#include <Repositories/Querry/GetQuerry/getsettingsquerry.h>

SettingsController::SettingsController()
{
    comboBoxV = nullptr;
    comboBoxDday = nullptr;
    comboBoxDmonth = nullptr;
    comboBoxS = nullptr;
    dateEditV = nullptr;
    dateEditD = nullptr;
    dateEditS = nullptr;
    doubleSpinBoxDPH = nullptr;
    labelPart1 = nullptr;
    labelPart2 = nullptr;
    comboBoxStyle = nullptr;
}

bool SettingsController::Build()
{
    if (comboBoxV == nullptr)
        return false;
    if (comboBoxDday == nullptr)
        return false;
    if (comboBoxDmonth == nullptr)
        return false;
    if (comboBoxS == nullptr)
        return false;
    if (dateEditV == nullptr)
        return false;
    if (dateEditD == nullptr)
        return false;
    if (dateEditS == nullptr)
        return false;
    if (doubleSpinBoxDPH == nullptr)
        return false;
    if (labelPart1 == nullptr)
        return false;
    if (labelPart2 == nullptr)
        return false;
    comboBoxVUpdate(0);
    comboBoxDdayUpate(0);
    return true;
}

void SettingsController::setComboBoxV(QComboBox *value)
{
    comboBoxV = value;
}

void SettingsController::setComboBoxDday(QComboBox *value)
{
    comboBoxDday = value;
}

void SettingsController::setComboBoxDmonth(QComboBox *value)
{
    comboBoxDmonth = value;
}

void SettingsController::setComboBoxS(QComboBox *value)
{
    comboBoxS = value;
}

void SettingsController::setDateEditV(QDateEdit *value)
{
    dateEditV = value;
}

void SettingsController::setDateEditD(QDateEdit *value)
{
    dateEditD = value;
}

void SettingsController::setDateEditS(QDateEdit *value)
{
    dateEditS = value;
}

void SettingsController::setDPH(QDoubleSpinBox *value)
{
    doubleSpinBoxDPH = value;
}

SettingsEntity *SettingsController::CreateEnity()
{
    SettingsEntity *entity = new SettingsEntity();
    entity->setIndexV(comboBoxV->currentIndex());
    entity->setIndexD(comboBoxDday->currentIndex());
    entity->setIndexD2(comboBoxDmonth->currentIndex());
    entity->setIndexS(comboBoxS->currentIndex());
    entity->setDateV(dateEditV->date());
    entity->setDateD(dateEditD->date());
    entity->setDateS(dateEditS->date());
    entity->setDPH(doubleSpinBoxDPH->value());
    if (comboBoxStyle != nullptr)
    {
        entity->setIndexStyle(comboBoxStyle->currentIndex());
    }
    else
        entity->setIndexStyle(0);
    return entity;
}

void SettingsController::SetSettingsEntity(SettingsEntity *entity)
{
    if (entity == nullptr)
        return;

    comboBoxV->setCurrentIndex(entity->getIndexV());
    comboBoxDday->setCurrentIndex(entity->getIndexD());
    comboBoxDmonth->setCurrentIndex(entity->getIndexD2());
    comboBoxS->setCurrentIndex(entity->getIndexS());

    if (entity->getIndexV() == 1) //last
        dateEditV->setDate(entity->getDateV());
    if (entity->getIndexD() == 4) //last
        dateEditD->setDate(entity->getDateD());
    if (entity->getIndexS() == 5) //last
        dateEditS->setDate(entity->getDateS());

    doubleSpinBoxDPH->setValue(entity->getDPH());
    if (comboBoxStyle != nullptr)
    {
        auto keys = QStyleFactory::keys();
        if (entity->getIndexStyle() < keys.size())
            comboBoxStyle->setCurrentIndex(entity->getIndexStyle());
    }
    delete entity;

}

void SettingsController::SetFromDB()
{
    GetSettingsQuerry q;
    auto entity = q.Get();
    SetSettingsEntity(entity);
    delete entity;
}

void SettingsController::Update()
{
    UpdateDDate();
    UpdateSDate();
}

void SettingsController::UpdateDDate()
{
    QDate today = dateEditV->date();
    int indexDay = comboBoxDday->currentIndex();
    if (indexDay == 1)
    {
        dateEditD->setDate(today);
        return;
    }

    int indexMonth = comboBoxDmonth->currentIndex();
    int monthMinus = 0; // current month
    if (indexMonth == 1) //last month
        monthMinus = -1;
    if (indexMonth == 2) // future month
        monthMinus = 1;
    today = today.addMonths(monthMinus);

    int day = 0;
    if (indexDay == 2) //first day
        day = 1;
    if (indexDay == 3) //last day
        day = today.daysInMonth();

    DateHelper date;
    dateEditD->setDate(date.getDate(day,today.month(),today.year()));
}

void SettingsController::UpdateSDate()
{
    int index = comboBoxS->currentIndex();
    if (index == 0) //ihned
    {
        dateEditS->setEnabled(false);
        QDate now = dateEditV->date();
        dateEditS->setDate(now);
        return;
    }

    if (index == 5) //custom date
    {
        dateEditS->setEnabled(true);
        return;
    }

    dateEditS->setEnabled(false);
    int days = 0;
    if (index == 1) // 7 days
        days = 7;
    if (index == 2) // 10 days
        days = 10;
    if (index == 3) //14 days
        days = 14;
    if (index == 4)
        days = 30;

    QDate now = dateEditV->date();
    now = now.addDays(days);
    dateEditS->setDate(now);
}

void SettingsController::setComboBoxStyle(QComboBox *value)
{
    comboBoxStyle = value;
}

void SettingsController::setLabelPart2(QLabel *value)
{
    labelPart2 = value;
}

void SettingsController::setLabelPart1(QLabel *value)
{
    labelPart1 = value;
}

void SettingsController::comboBoxDdayUpate(int index)
{
    if (index == 0) //current time
    {
        dateEditD->setDate(QDate::currentDate());
        dateEditD->setEnabled(false);
        labelPart1->setVisible(false);
        labelPart2->setVisible(false);
        comboBoxDmonth->setVisible(false);
        return;
    }

    if (index == 1) //time from vystavenia
    {
        QDate now = dateEditV->date();
        dateEditD->setDate(now);
        dateEditD->setEnabled(false);
        labelPart1->setVisible(false);
        labelPart2->setVisible(false);
        comboBoxDmonth->setVisible(false);
        return;
    }

    if (index == 4) // custom time
    {
        dateEditD->setEnabled(true);
        labelPart1->setVisible(false);
        labelPart2->setVisible(false);
        comboBoxDmonth->setVisible(false);
        return;
    }
    dateEditD->setEnabled(false);
    labelPart1->setVisible(true);
    labelPart2->setVisible(true);
    comboBoxDmonth->setVisible(true);
    UpdateDDate();
}

void SettingsController::comboBoxVUpdate(int index)
{
    if (index == 0) //enabled current time
    {
        dateEditV->setDate(QDate::currentDate());
        dateEditV->setEnabled(false);
    }
    else
    {
        dateEditV->setEnabled(true);
    }
    UpdateDDate();
}
