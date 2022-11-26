#include "mainpage.h"
#include "ui_mainpage.h"
#include <QDebug>

#include <QTreeWidgetItem>
#include <QResizeEvent>
#include <QFileDialog>

#include <Repositories/Querry/GetQuerry/getinvoicequerry.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Controller/suppliercontroller.h>
#include <Pages/NewInvoice/invoicepage.h>
#include <Pages/Invoice/questiondeleteinvoicepage.h>
#include <PDF/classicinvoice.h>
#include <Extensions/typeinvoicemapper.h>
#include <PDF/Creator/invoicecreator.h>

MainPage::MainPage(QWidget *parent, QStackedWidget *stackedWidget)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonNewInvoice->setStyleSheet(cs.ClassicButtonStyle());

    ui->labelMSG->setVisible(false);
    ui->treeWidget->setIconSize(QSize(30,30));
    ui->treeWidget->setColumnHidden(0,true);

    temporaryMessageController = new TemporaryMessageController(this,20);
    Start();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::Start()
{
    ui->treeWidget->clear();
    int month = QDate::currentDate().month();
    ui->comboBoxMonth->setCurrentIndex(month);

    ui->spinBoxYear->setValue(QDate::currentDate().year());
    SupplierController supplierController;
    supplierController.SetSuppliers("Všetci",ui->comboBoxSupplier);
    Update();
}


void MainPage::Update()
{
    ui->treeWidget->clear();
    SupplierController supplierController;

    int idSupplier = 0;
    auto entity = supplierController.GetEntityByIndex(ui->comboBoxSupplier->currentIndex()-1);
    if (entity != nullptr)
    {
        idSupplier = entity->getId();
    }
    GetInvoiceQuerry q;
    auto list = q.GetAllWhere(ui->spinBoxYear->value(),ui->comboBoxMonth->currentIndex(),idSupplier);
    qDebug() << q.GetLastError();

    double totalPrice = 0;
    for (int i = 0; i < list.size(); i++)
    {
        AddInvoiceEntity(list[i],i+1);
        totalPrice += list[i]->GetTotalPrice();
    }
    ui->labelTotalPrice->setText("Celková cena: " + QString::number(totalPrice) + " €");
}

void MainPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/7;
    ui->treeWidget->setColumnWidth(1,sizeOne/3);
    ui->treeWidget->setColumnWidth(2,sizeOne*1.5);
    ui->treeWidget->setColumnWidth(3,sizeOne);
    ui->treeWidget->setColumnWidth(4,sizeOne);
    ui->treeWidget->setColumnWidth(5,sizeOne);
    ui->treeWidget->setColumnWidth(6,sizeOne*0.8);
    ui->treeWidget->setColumnWidth(7,5);
    ui->treeWidget->setColumnWidth(8,10);
}

void MainPage::AddInvoiceEntity(InvoiceEntity *entity, int number)
{
    DateHelper helper;
    auto item = new QTreeWidgetItem();
    item->setText(0,QString::number(entity->getId()));
    item->setText(1,QString::number(number));
    item->setText(2,entity->getSupplierSaved()->getName());
    item->setTextColor(3,TypeInvoiceMapper::getInvoiceTypeColor(entity->getInvoiceType()));
    item->setText(3,TypeInvoiceMapper::toString(entity->getInvoiceType()));
    item->setText(4,QString::number(entity->GetTotalPrice()) + " €");
    item->setText(5,helper.toString(entity->getDateV()));
    item->setText(6,QString::number(entity->getFactureNumberByInvoiceType()));
    item->setIcon(7,QIcon(":/icon/Data/savePDF.png"));
    item->setIcon(8,QIcon(":/icon/Data/deleteClose.png"));

    item->setTextAlignment(6,5);

    this->ui->treeWidget->addTopLevelItem(item);
}

void MainPage::SaveInvoice(InvoiceEntity *entity)
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
    temporaryMessageController->StartVisibleLabel(ui->labelMSG);
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
    if (column == 7) //save invoice
    {
        SaveInvoice(entity);
        return;
    }
    if (column == 8) //delete invoice
    {
        auto w = (QuestionDeleteInvoicePage*)stackedWidget->widget((int)PageNumber::QUESTION_INVOICE);
        w->SetName(entity->getSupplierSaved()->getName());
        w->SetID(entity->getId());
        stackedWidget->setCurrentIndex((int)PageNumber::QUESTION_INVOICE);
        return;
    }
}

void MainPage::on_spinBoxYear_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    Update();
    qDebug() << "year changed";
}

void MainPage::on_comboBoxMonth_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    Update();

    qDebug() << "month changed";
}

void MainPage::on_comboBoxSupplier_activated(int index)
{
    Q_UNUSED(index);
    Update();

    qDebug() << "supplier changed";
}

void MainPage::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if ((column == 7) || (column == 8))
        return;

    GetInvoiceQuerry q;
    auto entity = q.GetOneById(item->text(0).toInt());

    ShowInvoicePage *w = (ShowInvoicePage*)stackedWidget->widget((int)PageNumber::SHOW_INVOICE);
    w->SetInvoice(entity);
    stackedWidget->setCurrentIndex((int)PageNumber::SHOW_INVOICE);
}
