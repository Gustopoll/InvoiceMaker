#include "addcustomerpage.h"
#include "customerspage.h"
#include "ui_addcustomerpage.h"

#include <Repositories/Querry/AddQuerry/addcustomersavedquerry.h>

AddCustomerPage::AddCustomerPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::AddCustomerPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonBack->setStyleSheet(cs.RedButtonStyle());
    ui->buttonSave->setStyleSheet(cs.GreenButtonStyle());

    controller = new RequiredItemsController();
    controller->Add(ui->lineEditNameO);
    controller->Add(ui->lineEditStreetO);
    controller->Add(ui->lineEditICO_O);
    controller->Add(ui->lineEditIDIC_O);
    controller->Add(ui->lineEditICDPH_O);
    controller->Add(ui->lineEditCityO);
    controller->Add(ui->lineEditPSC_O);
    controller->Add(ui->lineEditStateO);
    controller->Add(ui->lineEditStreetO);
    controller->Add(ui->lineEditStreetNumberO);
}

AddCustomerPage::~AddCustomerPage()
{
    delete ui;
}

void AddCustomerPage::SetCustomerEntity(CustomerEntity *entity)
{
    ui->lineEditNameO->setText(entity->getName());
    ui->lineEditStreetO->setText(entity->getAdress()->getStreet());
    ui->lineEditStreetNumberO->setText(entity->getAdress()->getStreetNumber());
    ui->lineEditStateO->setText(entity->getAdress()->getState());
    ui->lineEditPSC_O->setText(entity->getAdress()->getPsc());
    ui->lineEditCityO->setText(entity->getAdress()->getCity());
    ui->lineEditICO_O->setText(entity->getIco());

    ui->lineEditIDIC_O->setText(entity->getPayer()->getDic());
    ui->lineEditICDPH_O->setText(entity->getPayer()->getIcdph());

    idCustomerEntity = entity->getId();
    modeEdit = true;
}

void AddCustomerPage::Saving_event()
{
    if (modeEdit == false)
    {
        auto entity = CreateCustomerEntity();
        AddCustomerQuerry q;
        q.Add(entity);
        qDebug() << q.GetLastError();
    }
    else
    {
        auto entity = CreateCustomerEntity();
        entity->setId(idCustomerEntity);
        UpdateCustomerQuerry q;
        q.Update(entity);
        qDebug() << q.GetLastError();
    }
}

void AddCustomerPage::ResetAll()
{
    controller->ClearAll();
    modeEdit = false;
}

void AddCustomerPage::on_buttonSave_clicked()
{
    if (controller->isAnyEmpty() == true)
        return;

    Saving_event();
    ResetAll();
    auto w = (CustomersPage*)stackedWidget->widget((int)PageNumber::CUSTOMERS);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::CUSTOMERS);
}

void AddCustomerPage::on_buttonBack_clicked()
{
    ResetAll();
    stackedWidget->setCurrentIndex((int)PageNumber::CUSTOMERS);
}

CustomerEntity *AddCustomerPage::CreateCustomerEntity()
{
    CustomerEntity* entity = new CustomerEntity();
    entity->setName(ui->lineEditNameO->text());
    entity->getAdress()->setStreet(ui->lineEditStreetO->text());
    entity->getAdress()->setStreetNumber(ui->lineEditStreetNumberO->text());
    entity->getAdress()->setState(ui->lineEditStateO->text());
    entity->getAdress()->setPsc(ui->lineEditPSC_O->text());
    entity->getAdress()->setCity(ui->lineEditCityO->text());
    entity->setIco(ui->lineEditICO_O->text());
    entity->getPayer()->setDic(ui->lineEditIDIC_O->text());
    entity->getPayer()->setIcdph(ui->lineEditICDPH_O->text());
    return entity;
}
