#include "mainpage.h"
#include "ui_mainpage.h"
#include <QDebug>
#include "pdfinvoicegenerator.h"

#include <QTreeWidgetItem>
#include <QResizeEvent>

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
    this->ui->treeWidget->clear();
    auto item = new QTreeWidgetItem();
    item->setText(0,"1");
    item->setText(1,"Dominik Švač");
    item->setText(2,"250 €");
    item->setText(3,"25. 1. 2022");
    item->setIcon(5,QIcon(":/icon/Data/savePDF.png"));
    item->setText(4,"3");
    item->setTextAlignment(4,5);

    this->ui->treeWidget->addTopLevelItem(item);
    Update();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::Update()
{
    SupplierController supplierController;
    supplierController.SetSuppliers("Všetci",ui->comboBoxSupplier);

    int month = QDate::currentDate().month();
    ui->comboBoxMonth->setCurrentIndex(month);
    ui->spinBoxYear->setValue(QDate::currentDate().year());
}

void MainPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/6;
    ui->treeWidget->setColumnWidth(0,sizeOne/3);
    ui->treeWidget->setColumnWidth(1,sizeOne*2);
    ui->treeWidget->setColumnWidth(2,sizeOne);
    ui->treeWidget->setColumnWidth(3,sizeOne);
    ui->treeWidget->setColumnWidth(4,sizeOne);
    ui->treeWidget->setColumnWidth(5,10);
}

void MainPage::on_buttonNewInvoice_clicked()
{
    auto w = (InvoicePage*)stackedWidget->widget((int)PageNumber::INVOICE);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::INVOICE);
}

void MainPage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    InvoiceEntity* entity = new InvoiceEntity();
    SupplierEntity *s = new SupplierEntity();
    CustomerEntity *c = new CustomerEntity();
    entity->setCustomer(c);
    entity->setSupplier(s);

    ShowInvoicePage *w = (ShowInvoicePage*)stackedWidget->widget((int)PageNumber::SHOW_INVOICE);
    w->SetInvoice(entity);

    stackedWidget->setCurrentIndex((int)PageNumber::SHOW_INVOICE);
}
