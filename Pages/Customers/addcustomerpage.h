#ifndef ADDCUSTOMERPAGE_H
#define ADDCUSTOMERPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <Extensions/customstyle.h>
#include <Entities/customerentity.h>
#include <Repositories/Querry/AddQuerry/addcustomerquerry.h>
#include <Repositories/Querry/UpdateQuerry/updatecustomerquerry.h>
#include <Controller/requireditemscontroller.h>

namespace Ui {
class AddCustomerPage;
}

class AddCustomerPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddCustomerPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~AddCustomerPage();

    void SetCustomerEntity(CustomerEntity* entity);
    void Saving_event();
    void ResetAll();
private slots:
    void on_buttonSave_clicked();

    void on_buttonBack_clicked();

private:
    Ui::AddCustomerPage *ui;
    QStackedWidget *stackedWidget;

    CustomerEntity* CreateCustomerEntity();
    int idCustomerEntity;
    bool modeEdit = false;
    RequiredItemsController* controller;
};

#endif // ADDCUSTOMERPAGE_H
