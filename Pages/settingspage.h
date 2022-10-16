#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <Extensions/customstyle.h>
#include <Repositories/Querry/AddQuerry/addsettingsquerry.h>
#include <Repositories/Querry/GetQuerry/getsettingsquerry.h>
#include <Controller/settingscontroller.h>

namespace Ui {
class SettingsPage;
}

class SettingsPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~SettingsPage();

    //void SetSettingsEntity(SettingsEntity* entity);
private slots:
    void on_buttonSave_clicked();
    void on_buttonBack_clicked();

    void on_comboBoxDday_currentIndexChanged(int index);
    void on_comboBoxDmonth_currentIndexChanged(int index);
    void on_dateEditV_dateChanged(const QDate &date);
    void on_comboBoxS_currentIndexChanged(int index);
    void on_comboBoxV_currentIndexChanged(int index);

private:
    Ui::SettingsPage *ui;
    QStackedWidget *stackedWidget;
    SettingsController* settingsController;

    //void UpdateDDate();
    //void UpdateSDate();

    //SettingsEntity* CreateEntity();
};

#endif // SETTINGSPAGE_H
