#include "invoicepage.h"
#include "ui_invoicepage.h"
#include <Extensions/customstyle.h>
#include <QResizeEvent>
#include <QApplication>
#include <QDebug>
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Controller/customercontroller.h>
#include <Controller/invoicecontroller.h>
#include <Controller/suppliercontroller.h>
#include <Repositories/Querry/AddQuerry/addinvoicequerry.h>

#define PAGE1 0
#define PAGE2 1
#define PAGE3 2

InvoicePage::InvoicePage(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::InvoicePage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;
    CustomStyle cs;
    ui->buttonBackToMenu->setStyleSheet(cs.RedButtonStyle());
    ui->buttonNext2->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonNext3->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonBackTo2->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonBackTo1->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonSave->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonSavePDF->setStyleSheet(cs.ClassicButtonStyle());

    on_comboBoxPayment_currentIndexChanged(0); //set value to pay by Hotovosť
    ui->buttonAddItem->setIcon(QIcon(":/icon/Data/add.png"));
    ui->buttonSave->setIcon(QIcon(":/icon/Data/save.png"));
    ui->buttonSavePDF->setIcon(QIcon(":/icon/Data/savePDF.png"));

    ui->buttonAddItem->setStyleSheet(cs.ClassicButtonStyle());

    settingsController = new SettingsController();
    settingsController->setComboBoxV(ui->comboBoxV);
    settingsController->setComboBoxS(ui->comboBoxS);
    settingsController->setComboBoxDday(ui->comboBoxDday);
    settingsController->setComboBoxDmonth(ui->comboBoxDmonth);
    settingsController->setDateEditD(ui->dateEditD);
    settingsController->setDateEditV(ui->dateEditV);
    settingsController->setDateEditS(ui->dateEditS);
    settingsController->setDPH(ui->doubleSpinBoxDPH);
    settingsController->setLabelPart1(ui->labelPart1);
    settingsController->setLabelPart2(ui->labelPart2);
    if (settingsController->Build() == false)
        qDebug() << "error";

    supplierController = new SupplierController();
    customerController = new CustomerController();
    itemInvoiceController = new ItemInvoiceController();

    itemInvoiceController->AddDoubleSpinBoxDPH(ui->doubleSpinBoxDPH_item);
    itemInvoiceController->AddSpinBoxCount(ui->spinBoxCount);
    itemInvoiceController->AddDoubleSpinBoxPrice(ui->doubleSpinBoxPrice);
    itemInvoiceController->AddLabelTotalPrice(ui->labelTotalPrice);
    itemInvoiceController->AddLabelSumTotalPrice(ui->labelSumTotalPrice);
    itemInvoiceController->AddLineEditDescription(ui->lineEditDescription);
    Update();
}

InvoicePage::~InvoicePage()
{
    delete itemInvoiceController;
    delete settingsController;
    delete supplierController;
    delete customerController;
    delete ui;
}

void InvoicePage::Update()
{
    //TODO item invoice clear
    itemInvoiceController->Clear(ui->treeWidget);
    ui->doubleSpinBoxDPH_item->setValue(ui->doubleSpinBoxDPH->value());
    ui->lineEditDescription->setText("Na základe objednávok vám fakturujeme cenu práce za mesiac " +
                                     QString::number(ui->dateEditV->date().month()) + "/" + QString::number(ui->dateEditV->date().year()));
    supplierController->Update();
    customerController->Update();
    supplierController->SetSuppliers("Vyber dodavateľa",ui->comboBoxSupplier);
    customerController->SetCustomers("Vyber odberateľa",ui->comboBoxCustomer);
    ui->comboBoxCustomer->setCurrentIndex(0);
    ui->comboBoxSupplier->setCurrentIndex(0);
    settingsController->SetFromDB();
}

void InvoicePage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/7;
    ui->treeWidget->setColumnWidth(0,10);
    ui->treeWidget->setColumnWidth(1,sizeOne*2);
    ui->treeWidget->setColumnWidth(2,80);
    ui->treeWidget->setColumnWidth(3,65);
    ui->treeWidget->setColumnWidth(4,80);
    ui->treeWidget->setColumnWidth(5,10);
}

void InvoicePage::on_buttonNext2_clicked()
{
    ui->stackedWidget->setCurrentIndex(PAGE2);
}

void InvoicePage::on_buttonBackToMenu_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void InvoicePage::on_buttonBackTo1_clicked()
{
    ui->stackedWidget->setCurrentIndex(PAGE1);
}

void InvoicePage::on_buttonNext3_clicked()
{
    ui->stackedWidget->setCurrentIndex(PAGE3);
}

void InvoicePage::on_buttonBackTo2_clicked()
{
    ui->stackedWidget->setCurrentIndex(PAGE2);
}

void InvoicePage::on_buttonSave_clicked()
{
    SupplierEntity* supplierEntity = new SupplierEntity();

    supplierEntity->setIco(ui->lineEditICO_D->text());
    supplierEntity->setName(ui->lineEditNameD->text());
    supplierEntity->setFactureNumber(ui->lineEditNumberFacture->text().toInt());
    supplierEntity->getPayer()->setDic(ui->lineEditDIC_D->text());
    supplierEntity->getPayer()->setIcdph(ui->lineEditICDPH_D->text());
    supplierEntity->getAdress()->setPsc(ui->lineEditPSC_D->text());
    supplierEntity->getAdress()->setCity(ui->lineEditCityD->text());
    supplierEntity->getAdress()->setState(ui->lineEditStateD->text());
    supplierEntity->getAdress()->setStreet(ui->lineEditAdressD->text());
    supplierEntity->getAdress()->setStreetNumber("");

    supplierEntity->getBankinfo()->setVS(ui->lineEditVS->text());
    supplierEntity->getBankinfo()->setIBAN(ui->lineEditIBAN->text());
    supplierEntity->getBankinfo()->setSWIFT(ui->lineEditSWIFT->text());

    CustomerEntity* customerEntity = new CustomerEntity();

    customerEntity->setIco(ui->lineEditICO_O->text());
    customerEntity->setName(ui->lineEditNameO->text());
    customerEntity->getPayer()->setDic(ui->lineEditDIC_O->text());
    customerEntity->getPayer()->setIcdph(ui->lineEditICDPH_O->text());
    customerEntity->getAdress()->setPsc(ui->lineEditPSC_O->text());
    customerEntity->getAdress()->setCity(ui->lineEditCityO->text());
    customerEntity->getAdress()->setState(ui->lineEditStateO->text());
    customerEntity->getAdress()->setStreet(ui->lineEditAdressO->text());
    customerEntity->getAdress()->setStreetNumber("");

    InvoiceController* invoiceController = new InvoiceController();
    invoiceController->setDateEditD(ui->dateEditD);
    invoiceController->setDateEditV(ui->dateEditV);
    invoiceController->setDateEditS(ui->dateEditS);


    auto customer = customerController->GetEntityByIndex(ui->comboBoxCustomer->currentIndex()-1);
    if (customer != nullptr)
        invoiceController->setIdCustomer(customer->getId());

    auto supplier = supplierController->GetEntityByIndex(ui->comboBoxSupplier->currentIndex()-1);
    if (supplier != nullptr)
        invoiceController->setIdSupplier(supplier->getId());

    invoiceController->setComboBoxType(ui->comboBoxType);
    invoiceController->setComboBoxPayment(ui->comboBoxPayment);
    invoiceController->setCustomerSavedEntity(customerEntity);
    invoiceController->setSupplierSavedEntity(supplierEntity);

    auto items = itemInvoiceController->GetAllEntities(ui->treeWidget);
    for (int i = 0; i < items.size(); i++)
        invoiceController->addItem(items[i]);

    auto invoice = invoiceController->Create();

    AddInvoiceQuerry q;
    q.Add(invoice);

    delete customerEntity;
    delete supplierEntity;
    delete invoice;
    delete invoiceController;

    stackedWidget->widget((int)PageNumber::MAIN_MENU);
}


void InvoicePage::on_comboBoxPayment_currentIndexChanged(int index)
{
    bool set = false;
    if (index == 0)
        set = false;
    if (index == 1)
        set = true;

    ui->labelIBAN->setVisible(set);
    ui->labelSWIFT->setVisible(set);
    ui->labelVS->setVisible(set);

    ui->lineEditIBAN->setVisible(set);
    ui->lineEditSWIFT->setVisible(set);
    ui->lineEditVS->setVisible(set);
}

void InvoicePage::on_checkBoxDPHPayer_stateChanged(int arg1)
{
    bool set = true;
    if (arg1 == 0)
        set = false;

    if (arg1 == 2)
        set = true;

    ui->labelICO_D->setVisible(set);
    ui->labelDIC_D->setVisible(set);
    ui->labelICDPH_D->setVisible(set);

    ui->lineEditICO_D->setVisible(set);
    ui->lineEditDIC_D->setVisible(set);
    ui->lineEditICDPH_D->setVisible(set);
}

void InvoicePage::on_comboBoxV_currentIndexChanged(int index)
{
    settingsController->comboBoxVUpdate(index);
}

void InvoicePage::on_comboBoxDday_currentIndexChanged(int index)
{
    settingsController->comboBoxDdayUpate(index);
}

void InvoicePage::on_comboBoxS_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    settingsController->Update();
}

void InvoicePage::on_comboBoxDmonth_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    settingsController->Update();
}

void InvoicePage::on_dateEditV_dateChanged(const QDate &date)
{
    Q_UNUSED(date);
    settingsController->Update();
}

void InvoicePage::on_comboBoxSupplier_currentIndexChanged(int index)
{
    int indexSupplier = index - 1;
    auto entity = supplierController->GetEntityByIndex(indexSupplier);
    if (entity == nullptr)
    {
        ui->comboBoxPayment->setCurrentIndex(0);
        ui->checkBoxDPHPayer->setCheckState(Qt::CheckState::Checked);
        ui->lineEditIBAN->setText("");
        ui->lineEditSWIFT->setText("");
        ui->lineEditNameD->setText("");
        ui->lineEditICO_D->setText("");
        ui->lineEditDIC_D->setText("");
        ui->lineEditICDPH_D->setText("");
        ui->lineEditStateD->setText("");
        ui->lineEditCityD->setText("");
        ui->lineEditPSC_D->setText("");
        ui->lineEditAdressD->setText("");
        ui->lineEditNumberFacture->setText("");
        return;
    }
    if (entity->getBankinfo()->isValid() == true)
        ui->comboBoxPayment->setCurrentIndex(1);// bankový prevod
    else
        ui->comboBoxPayment->setCurrentIndex(0); // hotovsť

    if (entity->isPayer() == true)
        ui->checkBoxDPHPayer->setCheckState(Qt::CheckState::Checked);
    else
        ui->checkBoxDPHPayer->setCheckState(Qt::CheckState::Unchecked);
    ui->lineEditIBAN->setText(entity->getBankinfo()->getIBAN());
    ui->lineEditSWIFT->setText(entity->getBankinfo()->getSWIFT());
    ui->lineEditNameD->setText(entity->getName());
    ui->lineEditICO_D->setText(entity->getIco());
    ui->lineEditDIC_D->setText(entity->getPayer()->getDic());
    ui->lineEditICDPH_D->setText(entity->getPayer()->getIcdph());
    ui->lineEditCityD->setText(entity->getAdress()->getCity());
    ui->lineEditStateD->setText(entity->getAdress()->getState());
    ui->lineEditPSC_D->setText(entity->getAdress()->getPsc());
    ui->lineEditAdressD->setText(entity->getAdress()->getStreetWithNumber());
    ui->lineEditNumberFacture->setText(QString::number(entity->getFactureNumber()));
}

void InvoicePage::on_comboBoxCustomer_currentIndexChanged(int index)
{
    int indexCustomer = index - 1;
    auto entity = customerController->GetEntityByIndex(indexCustomer);
    if (entity == nullptr)
    {
        ui->lineEditNameO->setText("");
        ui->lineEditICO_O->setText("");
        ui->lineEditDIC_O->setText("");
        ui->lineEditICDPH_O->setText("");
        ui->lineEditStateO->setText("");
        ui->lineEditCityO->setText("");
        ui->lineEditPSC_O->setText("");
        ui->lineEditAdressO->setText("");
        return;
    }
    ui->lineEditNameO->setText(entity->getName());
    ui->lineEditICO_O->setText(entity->getIco());
    ui->lineEditDIC_O->setText(entity->getPayer()->getDic());
    ui->lineEditICDPH_O->setText(entity->getPayer()->getIcdph());
    ui->lineEditCityO->setText(entity->getAdress()->getCity());
    ui->lineEditStateO->setText(entity->getAdress()->getState());
    ui->lineEditPSC_O->setText(entity->getAdress()->getPsc());
    ui->lineEditAdressO->setText(entity->getAdress()->getStreetWithNumber());
}

void InvoicePage::on_buttonAddItem_clicked()
{
    itemInvoiceController->CreateItem(ui->treeWidget);
    ui->doubleSpinBoxPrice->setValue(0.0);
    ui->spinBoxCount->setValue(1);
    ui->doubleSpinBoxDPH_item->setValue(ui->doubleSpinBoxDPH->value());
    ui->lineEditDescription->setText("Na základe objednávok vám fakturujeme cenu práce za mesiac " +
                                     QString::number(ui->dateEditV->date().month()) + "/" + QString::number(ui->dateEditV->date().year()));
}

void InvoicePage::on_spinBoxCount_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    itemInvoiceController->Update();
}

void InvoicePage::on_doubleSpinBoxPrice_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    itemInvoiceController->Update();
}

void InvoicePage::on_doubleSpinBoxDPH_item_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
    itemInvoiceController->Update();
}

void InvoicePage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (column == 5) // last column
    {
        itemInvoiceController->DeleteItem(ui->treeWidget, item);
    }
}

void InvoicePage::on_doubleSpinBoxDPH_valueChanged(double arg1)
{
    ui->doubleSpinBoxDPH_item->setValue(arg1);
}

