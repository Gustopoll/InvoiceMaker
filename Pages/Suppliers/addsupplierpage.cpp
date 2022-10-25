#include "addsupplierpage.h"
#include "ui_addsupplierpage.h"

#include <Pages/mainpage.h>

AddSupplierPage::AddSupplierPage(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::AddSupplierPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;
    CustomStyle cs;
    ui->buttonSave->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonBack->setStyleSheet(cs.RedButtonStyle());

    controller = new RequiredItemsController();
    controller->Add(ui->lineEditCityD);
    controller->Add(ui->lineEditICO_D);
    controller->Add(ui->lineEditNameD);
    controller->Add(ui->lineEditPSC_D);
    controller->Add(ui->lineEditStateD);
    controller->Add(ui->lineEditStreetD);
    controller->Add(ui->lineEditNumberFacture);
    controller->Add(ui->lineEditStreetNumberD);

    controllerOnlyDPHPayer = new RequiredItemsController();
    controllerOnlyDPHPayer->Add(ui->lineEditDIC_D);
    controllerOnlyDPHPayer->Add(ui->lineEditICDPH_D);
    ResetAll();
}

AddSupplierPage::~AddSupplierPage()
{
    delete ui;
}

void AddSupplierPage::ResetAll()
{
    controller->ClearAll();
    controllerOnlyDPHPayer->ClearAll();
    ui->lineEditIBAN->clear();
    ui->lineEditSWIFT->clear();
    ui->checkBoxDPHPayer->setCheckState(Qt::CheckState::Unchecked);
    on_checkBoxDPHPayer_stateChanged(0); //default disable dph payer
    modeEdit = false;
}

void AddSupplierPage::SetSupplierEntity(SupplierEntity *entity)
{
    ui->lineEditNameD->setText(entity->getName());
    ui->lineEditStreetD->setText(entity->getAdress()->getStreet());
    ui->lineEditStreetNumberD->setText(entity->getAdress()->getStreetNumber());
    ui->lineEditStateD->setText(entity->getAdress()->getState());
    ui->lineEditPSC_D->setText(entity->getAdress()->getPsc());
    ui->lineEditCityD->setText(entity->getAdress()->getCity());
    ui->lineEditNumberFacture->setText(QString::number(entity->getFactureNumber()));
    ui->lineEditICO_D->setText(entity->getIco());

    if (entity->isPayer())
    {
        ui->checkBoxDPHPayer->setCheckState(Qt::CheckState::Checked);
        ui->lineEditDIC_D->setText(entity->getPayer()->getDic());
        ui->lineEditICDPH_D->setText(entity->getPayer()->getIcdph());
    }

    ui->lineEditIBAN->setText(entity->getBankinfo()->getIBAN());
    ui->lineEditSWIFT->setText(entity->getBankinfo()->getSWIFT());

    idSupplierEntity = entity->getId();
    modeEdit = true;
}

void AddSupplierPage::on_buttonSave_clicked()
{
    if (ui->checkBoxDPHPayer->checkState() == Qt::CheckState::Checked)
    {
        auto value = controllerOnlyDPHPayer->isAnyEmpty() || controller->isAnyEmpty();
        if (value == true)
            return;
    }
    else
    {
        auto value = controller->isAnyEmpty();
        if (value == true)
            return;
    }

    Saving_event();

    //auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    //w->Start();
    BackToSuppliers();
}

void AddSupplierPage::on_buttonBack_clicked()
{
    ResetAll();
    stackedWidget->setCurrentIndex((int)PageNumber::SUPPLIERS);
}

void AddSupplierPage::on_checkBoxDPHPayer_stateChanged(int arg1)
{
    controllerOnlyDPHPayer->ClearAll();
    bool set = false;
    if (arg1 == 0)
        set = false;

    if (arg1 == 2)
        set = true;

    ui->labelDIC_D->setVisible(set);
    ui->labelICDPH_D->setVisible(set);

    ui->lineEditDIC_D->setVisible(set);
    ui->lineEditICDPH_D->setVisible(set);
}

void AddSupplierPage::Saving_event()
{
    auto entity = CreateSuppliersEntity();

    if (modeEdit)
    {
        UpdateSupplierQuerry q;
        entity->setId(idSupplierEntity);

        q.Update(entity);
        qDebug() << q.GetLastError();
    }
    else
    {
        AddSupplierQuerry q;
        q.Add(entity);
    }
}

SupplierEntity *AddSupplierPage::CreateSuppliersEntity()
{
    SupplierEntity* entity = new SupplierEntity();
    entity->setName(ui->lineEditNameD->text());
    entity->getAdress()->setStreet(ui->lineEditStreetD->text());
    entity->getAdress()->setStreetNumber(ui->lineEditStreetNumberD->text());
    entity->getAdress()->setState(ui->lineEditStateD->text());
    entity->getAdress()->setPsc(ui->lineEditPSC_D->text());
    entity->getAdress()->setCity(ui->lineEditCityD->text());
    entity->setFactureNumber(ui->lineEditNumberFacture->text().toInt()); //TODO test na INT
    entity->setIco(ui->lineEditICO_D->text());

    if (ui->checkBoxDPHPayer->checkState() == Qt::CheckState::Checked)
    {
        entity->getPayer()->setDic(ui->lineEditDIC_D->text());
        entity->getPayer()->setIcdph(ui->lineEditICDPH_D->text());
    }

    entity->getBankinfo()->setIBAN(ui->lineEditIBAN->text());
    entity->getBankinfo()->setSWIFT(ui->lineEditSWIFT->text());
    return entity;
}

void AddSupplierPage::BackToSuppliers()
{
    ResetAll();
    auto w = (SuppliersPage*)stackedWidget->widget((int)PageNumber::SUPPLIERS);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::SUPPLIERS);
}
