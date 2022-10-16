#ifndef ADDSUPPLIERPAGE_H
#define ADDSUPPLIERPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <Extensions/customstyle.h>
#include <Entities/supplierentity.h>
#include <Repositories/Querry/AddQuerry/addsupplierquerry.h>
#include <Repositories/Querry/UpdateQuerry/updatesupplierquerry.h>
#include <Controller/requireditemscontroller.h>
#include "supplierspage.h"

namespace Ui {
class AddSupplierPage;
}

class AddSupplierPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddSupplierPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~AddSupplierPage();

    void ResetAll();
    void SetSupplierEntity(SupplierEntity* entity);

private slots:
    void on_buttonSave_clicked();
    void on_buttonBack_clicked();
    void on_checkBoxDPHPayer_stateChanged(int arg1);

    void Saving_event();
private:
    Ui::AddSupplierPage *ui;
    QStackedWidget *stackedWidget;

    bool modeEdit = false;
    int idSupplierEntity;

    SupplierEntity* CreateSuppliersEntity();
    RequiredItemsController* controller;
    RequiredItemsController* controllerOnlyDPHPayer;

    void BackToSuppliers();

};

#endif // ADDSUPPLIERPAGE_H
