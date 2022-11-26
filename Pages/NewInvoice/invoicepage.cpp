#include "invoicepage.h"
#include "ui_invoicepage.h"
#include <Extensions/customstyle.h>
#include <Extensions/typeinvoicemapper.h>
#include <QResizeEvent>
#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Controller/customercontroller.h>
#include <Controller/invoicecontroller.h>
#include <Controller/suppliercontroller.h>
#include <Repositories/Querry/AddQuerry/addinvoicequerry.h>
#include <Pages/mainpage.h>
#include <Repositories/Querry/UpdateQuerry/updatesupplierquerry.h>
#include <PDF/Creator/invoicecreator.h>

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

    ui->buttonX1->setStyleSheet(cs.DeleteButtonStyle());
    ui->buttonX2->setStyleSheet(cs.DeleteButtonStyle());
    ui->buttonX3->setStyleSheet(cs.DeleteButtonStyle());

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

    ui->comboBoxType->clear();
    int i = 0;
    auto name = TypeInvoiceMapper::toString((InvoiceType)i);
    while (name != "")
    {
        ui->comboBoxType->addItem(name);
        i++;
        name = TypeInvoiceMapper::toString((InvoiceType)i);
    }
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
    bool visible = true;

    ui->dateEditD->setVisible(visible);
    ui->labelDodania->setVisible(visible);
    ui->comboBoxDday->setVisible(visible);
    ui->dateEditS->setVisible(visible);
    ui->labelSplatnost->setVisible(visible);
    ui->comboBoxS->setVisible(visible);
    ui->comboBoxPayment->setVisible(visible);

    ui->labelNumberFactureFor->setVisible(false);
    ui->lineEditNumberFactureFor->setVisible(false);
    ui->labelNumberFacture->setText("Číslo faktúry");
    ui->labelVystavenia->setText("Dátum vystavenia:");
    ui->buttonNext3->setIcon(QIcon());
    ui->buttonNext3->setText("Ďalej");
    ui->progressBar_2->setValue(50);

    CustomStyle cs;
    ui->buttonNext3->setStyleSheet(cs.ClassicButtonStyle());

    ui->stackedWidget->setCurrentIndex(0);
    itemInvoiceController->Clear(ui->treeWidget);

    supplierController->Update();
    customerController->Update();
    supplierController->SetSuppliers("Vyber dodavateľa",ui->comboBoxSupplier);
    customerController->SetCustomers("Vyber odberateľa",ui->comboBoxCustomer);
    ui->comboBoxCustomer->setCurrentIndex(0);
    ui->comboBoxSupplier->setCurrentIndex(0);

    ui->doubleSpinBoxDPH_item->setValue(ui->doubleSpinBoxDPH->value());
    ui->lineEditDescription->setText("Na základe objednávok vám fakturujeme cenu práce za mesiac " +
                                     QString::number(ui->dateEditV->date().month()) + "/" + QString::number(ui->dateEditV->date().year()));

    settingsController->SetFromDB();
}

void InvoicePage::SetDobropis(InvoiceEntity *entity)
{
    SetDobropis();
    ui->comboBoxType->setCurrentIndex((int)InvoiceType::Dobropis);
    ClearCustomer();
    ClearSupplier();
    auto factureNumber = entity->getFactureNumberByInvoiceType();
    entity->getSupplierSaved()->setFactureNumberClassic(factureNumber);
    entity->getSupplierSaved()->setFactureNumberCanceled(1); //default value
    if (entity->getIdSupplier() != -1)
    {
        GetSupplierQuerry querry;
        auto e = querry.GetOneById(entity->getIdSupplier());
        entity->getSupplierSaved()->setFactureNumberCanceled(e->getFactureNumberCanceled());
        delete e;
    }

    SetCustomerEntity(entity->getCustomerSaved());
    SetSupplierEntity(entity->getSupplierSaved(),InvoiceType::Dobropis);

    //vystavenia datum
    ui->comboBoxV->setCurrentIndex(1); //custom time
    ui->dateEditV->setDate(entity->getDateV());
    //dodania datum
    ui->comboBoxDday->setCurrentIndex(4); //custom time
    ui->dateEditD->setDate(entity->getDateD());

    //items
    auto items = entity->getItems();
    for (int i = 0; i < items.size(); i++)
    {
        ui->spinBoxCount->setValue(items[i]->getCount());
        ui->lineEditDescription->setText(items[i]->getDescription());
        ui->doubleSpinBoxDPH_item->setValue(items[i]->getDPH());
        ui->doubleSpinBoxPrice->setValue(-1*std::abs(items[i]->getPrice()));
        //itemInvoiceController->CreateItem(ui->treeWidget);
        on_buttonAddItem_clicked();
    }
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
    ui->comboBoxType->setCurrentIndex(0);
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
    auto invoice = CreateInvoiceEntity();

    AddInvoiceQuerry q;
    q.Add(invoice);
    qDebug() << q.GetLastError();

    auto supplier = supplierController->GetEntityByIndex(ui->comboBoxSupplier->currentIndex()-1);
    if (supplier != nullptr) //supplier must exists
    {
        auto numberFacture = invoice->getFactureNumberByInvoiceType();
        if (ui->lineEditNumberFacture->text().toInt() == numberFacture) //user do not change facture number
        {
            numberFacture++;
            supplier->setFactureNumberByInvoiceType((InvoiceType)ui->comboBoxType->currentIndex(),numberFacture);
            UpdateSupplierQuerry updateSupplier;
            updateSupplier.Update(supplier);
        }
    }

    delete invoice;

    auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
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
    ui->lineEditDescription->setText("Na základe objednávok vám fakturujeme cenu práce za mesiac " +
                                     QString::number(ui->dateEditV->date().month()) + "/" + QString::number(ui->dateEditV->date().year()));
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
        ClearSupplier();
        return;
    }

    SetSupplierEntity(entity,(InvoiceType)ui->comboBoxType->currentIndex());
}

void InvoicePage::on_comboBoxCustomer_currentIndexChanged(int index)
{
    int indexCustomer = index - 1;
    auto entity = customerController->GetEntityByIndex(indexCustomer);
    if (entity == nullptr)
    {
        ClearCustomer();
        return;
    }

    SetCustomerEntity(entity);
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

void InvoicePage::SetSupplierEntity(SupplierEntity *entity, InvoiceType type)
{
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

    ui->lineEditNumberFacture->setText(QString::number(entity->getFactureNumberByInvoiceType(type)));
    ui->lineEditNumberFactureFor->setText(QString::number(entity->getFactureNumberClassic()));
    //ui->lineEditNumberFacture->setText(QString::number(entity->getFactureNumberByInvoiceType(type)));
    //ui->lineEditNumberFactureFor->setText(QString::number(entity->getFactureNumberClassic()));
}

void InvoicePage::SetCustomerEntity(CustomerEntity *entity)
{
    ui->lineEditNameO->setText(entity->getName());
    ui->lineEditICO_O->setText(entity->getIco());
    ui->lineEditDIC_O->setText(entity->getPayer()->getDic());
    ui->lineEditICDPH_O->setText(entity->getPayer()->getIcdph());
    ui->lineEditCityO->setText(entity->getAdress()->getCity());
    ui->lineEditStateO->setText(entity->getAdress()->getState());
    ui->lineEditPSC_O->setText(entity->getAdress()->getPsc());
    ui->lineEditAdressO->setText(entity->getAdress()->getStreetWithNumber());
}

void InvoicePage::ClearSupplier()
{
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
}

void InvoicePage::ClearCustomer()
{
    ui->lineEditNameO->setText("");
    ui->lineEditICO_O->setText("");
    ui->lineEditDIC_O->setText("");
    ui->lineEditICDPH_O->setText("");
    ui->lineEditStateO->setText("");
    ui->lineEditCityO->setText("");
    ui->lineEditPSC_O->setText("");
    ui->lineEditAdressO->setText("");
}


void InvoicePage::on_buttonX1_clicked()
{
    ui->comboBoxType->setCurrentIndex(0);
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void InvoicePage::on_buttonX2_clicked()
{
    ui->comboBoxType->setCurrentIndex(0);
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void InvoicePage::on_buttonX3_clicked()
{
    ui->comboBoxType->setCurrentIndex(0);
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void InvoicePage::SetZalohovaFaktura()
{
    ui->dateEditD->setVisible(false);
    ui->labelDodania->setVisible(false);
    ui->comboBoxDday->setVisible(false);
    ui->comboBoxDmonth->setVisible(false);
    ui->labelPart1->setVisible(false);
    ui->labelPart2->setVisible(false);
    ui->lineEditDescription->setText("Záloha za služby " + QString::number(ui->dateEditV->date().month()) + "/" + QString::number(ui->dateEditV->date().year()));
}

void InvoicePage::SetDobropis()
{
    bool value = false;
    ui->dateEditS->setVisible(value);
    ui->labelSplatnost->setVisible(value);
    ui->comboBoxS->setVisible(value);
    ui->labelNumberFactureFor->setVisible(true);
    ui->lineEditNumberFactureFor->setVisible(true);
    ui->lineEditDescription->setText("");
    ui->labelNumberFacture->setText("Číslo dobropisu");
}

void InvoicePage::SetObjednavka()
{
    bool value = false;
    ui->comboBoxPayment->setCurrentIndex(0);
    ui->comboBoxPayment->setVisible(value);
    ui->labelPayment->setVisible(false);

    ui->dateEditD->setVisible(false);
    ui->labelDodania->setVisible(false);
    ui->comboBoxDday->setVisible(false);
    ui->comboBoxDmonth->setVisible(false);
    ui->labelPart1->setVisible(false);
    ui->labelPart2->setVisible(false);

    ui->dateEditS->setVisible(value);
    ui->labelSplatnost->setVisible(value);
    ui->comboBoxS->setVisible(value);

    ui->labelNumberFacture->setText("Číslo objednávky");
    ui->labelVystavenia->setText("Dátum vytvorenia:");
}

void InvoicePage::SetCenovaPonuka()
{
    bool value = false;
    ui->comboBoxPayment->setCurrentIndex(0);
    ui->comboBoxPayment->setVisible(value);
    ui->labelPayment->setVisible(false);

    ui->labelPayment->setVisible(false);
    ui->dateEditD->setVisible(false);
    ui->labelDodania->setVisible(false);
    ui->comboBoxDday->setVisible(false);
    ui->comboBoxDmonth->setVisible(false);
    ui->labelPart1->setVisible(false);
    ui->labelPart2->setVisible(false);

    ui->labelNumberFacture->setText("Číslo ponuky");
    ui->labelVystavenia->setText("Dátum vytvorenia:");
}

void InvoicePage::on_comboBoxType_currentIndexChanged(int index)
{
    Update();
    if ((InvoiceType)index == InvoiceType::Zalohova_faktura)
        SetZalohovaFaktura();
    if ((InvoiceType)index == InvoiceType::Dobropis)
        SetDobropis();
    if ((InvoiceType)index == InvoiceType::Objednavka)
        SetObjednavka();
    if ((InvoiceType)index == InvoiceType::Cenova_ponuka)
        SetCenovaPonuka();
}

void InvoicePage::on_buttonSavePDF_clicked()
{
    //auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    auto invoice = CreateInvoiceEntity();
    SaveInvoice(invoice);
    //qDebug() << invoice->getSupplierSaved()->getName();
    //w->SaveInvoice(invoice);
    delete invoice;
}

InvoiceEntity *InvoicePage::CreateInvoiceEntity()
{
    SupplierEntity* supplierEntity = new SupplierEntity();

    supplierEntity->setIco(ui->lineEditICO_D->text());
    supplierEntity->setName(ui->lineEditNameD->text());
    supplierEntity->getPayer()->setDic(ui->lineEditDIC_D->text());
    supplierEntity->getPayer()->setIcdph(ui->lineEditICDPH_D->text());
    supplierEntity->getAdress()->setPsc(ui->lineEditPSC_D->text());
    supplierEntity->getAdress()->setCity(ui->lineEditCityD->text());
    supplierEntity->getAdress()->setState(ui->lineEditStateD->text());
    supplierEntity->getAdress()->setStreet(ui->lineEditAdressD->text());
    supplierEntity->getAdress()->setStreetNumber("");
    supplierEntity->setFactureNumberClassic(ui->lineEditNumberFactureFor->text().toInt());
    supplierEntity->setFactureNumberByInvoiceType((InvoiceType)ui->comboBoxType->currentIndex(),ui->lineEditNumberFacture->text().toInt());

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

    return invoiceController->Create();
}

void InvoicePage::SaveInvoice(InvoiceEntity *entity)
{
    std::string nameForFile = entity->getSupplierSaved()->getName().toStdString() + "_" + QString::number(entity->getFactureNumberByInvoiceType()).toStdString()  + ".pdf";
    QString dirpath;
    dirpath = QFileDialog::getSaveFileName(this,tr("Ukldanie"),tr(nameForFile.c_str()),tr("PDF(*.pdf)")),
                  QCoreApplication::applicationDirPath();

    if (dirpath.isEmpty() == true)
        return;
    qDebug() << dirpath;

    InvoiceCreator creator;
    auto invoiceGenerator = creator.Create(dirpath,entity->getInvoiceType());
    invoiceGenerator->Generate(entity);
    delete invoiceGenerator;
}
