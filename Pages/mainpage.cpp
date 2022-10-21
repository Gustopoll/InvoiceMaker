#include "mainpage.h"
#include "ui_mainpage.h"
#include <QDebug>
#include "pdfinvoicegenerator.h"

#include <QTreeWidgetItem>
#include <QResizeEvent>
#include <QFileDialog>

#include <Repositories/Querry/GetQuerry/getinvoicequerry.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Controller/suppliercontroller.h>
#include <Pages/NewInvoice/invoicepage.h>

MainPage::MainPage(QWidget *parent, QStackedWidget *stackedWidget)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonNewInvoice->setStyleSheet(cs.ClassicButtonStyle());

    //PDFInvoiceGenerator *gen = new PDFInvoiceGenerator();
    //gen->Generate();

    ui->treeWidget->setIconSize(QSize(30,30));
    ui->treeWidget->setColumnHidden(0,true);
    Update();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::Update()
{
    ui->treeWidget->clear();
    SupplierController supplierController;
    supplierController.SetSuppliers("Všetci",ui->comboBoxSupplier);

    int month = QDate::currentDate().month();
    ui->comboBoxMonth->setCurrentIndex(month);
    ui->spinBoxYear->setValue(QDate::currentDate().year());

    InvoiceEntity* entity = new InvoiceEntity();
    entity->setId(1);
    entity->setSupplierSaved(new SupplierEntity());
    entity->getSupplierSaved()->setName("Dominik");
    entity->setFactureNumber(1);
    entity->setDateV(QDate::currentDate());
    AddInvoiceEntity(entity,1);
}

void MainPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/6;
    ui->treeWidget->setColumnWidth(1,sizeOne/3);
    ui->treeWidget->setColumnWidth(2,sizeOne*1.9);
    ui->treeWidget->setColumnWidth(3,sizeOne);
    ui->treeWidget->setColumnWidth(4,sizeOne);
    ui->treeWidget->setColumnWidth(5,sizeOne*0.8);
    ui->treeWidget->setColumnWidth(6,5);
    ui->treeWidget->setColumnWidth(7,10);
}

void MainPage::AddInvoiceEntity(InvoiceEntity *entity, int number)
{
    DateHelper helper;
    auto item = new QTreeWidgetItem();
    item->setText(0,QString::number(entity->getId()));
    item->setText(1,QString::number(number));
    item->setText(2,entity->getSupplierSaved()->getName());
    item->setText(3,QString::number(entity->GetTotalPrice()) + " €");
    item->setText(4,helper.toString(entity->getDateV()));
    item->setText(5,QString::number(entity->getFactureNumber()));
    item->setIcon(6,QIcon(":/icon/Data/savePDF.png"));
    item->setIcon(7,QIcon(":/icon/Data/deleteClose.png"));

    item->setTextAlignment(5,5);

    this->ui->treeWidget->addTopLevelItem(item);
}

void MainPage::SaveInvoice(InvoiceEntity *entity, QString pathfile)
{
    PDFInvoiceGenerator gen(pathfile);
    gen.Generate(entity);
}

void MainPage::on_buttonNewInvoice_clicked()
{
    auto w = (InvoicePage*)stackedWidget->widget((int)PageNumber::INVOICE);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::INVOICE);
}

void MainPage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    GetInvoiceQuerry q;
    auto entity = q.GetOneById(item->text(0).toInt());
    if (column == 6) //save invoice
    {
        QString dirpath;
        dirpath = QFileDialog::getExistingDirectory(this, tr("Vyber zložku"),
                      QCoreApplication::applicationDirPath(),
                      QFileDialog::ShowDirsOnly
                      | QFileDialog::DontResolveSymlinks);

        if (dirpath.isEmpty() == true)
            return;
        dirpath += "/invoice.pdf";
        SaveInvoice(entity,dirpath);
        //delete entity;
        return;
    }
    if (column == 7) //delete invoice
    {
        delete entity;
        return;
    }

    ShowInvoicePage *w = (ShowInvoicePage*)stackedWidget->widget((int)PageNumber::SHOW_INVOICE);
    w->SetInvoice(entity);
    stackedWidget->setCurrentIndex((int)PageNumber::SHOW_INVOICE);
}
