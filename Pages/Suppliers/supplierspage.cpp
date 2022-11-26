#include "addsupplierpage.h"
#include "supplierspage.h"
#include "ui_supplierspage.h"

#include <Pages/mainpage.h>

SuppliersPage::SuppliersPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::SuppliersPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonBack->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonAddSupplier->setStyleSheet(cs.GreenButtonStyle());

    ui->treeWidget->setIconSize(QSize(40,40));
    ui->treeWidget->setColumnHidden(0,true);
    Update();
}

SuppliersPage::~SuppliersPage()
{
    delete ui;
}

void SuppliersPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/7;
    ui->treeWidget->setColumnWidth(1,sizeOne/3);
    ui->treeWidget->setColumnWidth(2,sizeOne*2);
    ui->treeWidget->setColumnWidth(3,sizeOne*2);
    ui->treeWidget->setColumnWidth(4,sizeOne);
    ui->treeWidget->setColumnWidth(5,sizeOne);
    ui->treeWidget->setColumnWidth(6,5);
}


void SuppliersPage::Update()
{
    ui->treeWidget->clear();
    GetSupplierQuerry q;
    auto suppliers = q.GetAllNoDeleted();
    for (int i = 0; i < suppliers.size(); i++)
    {
        auto item = new QTreeWidgetItem();
        item->setText(0,QString::number(suppliers[i]->getId()));
        item->setText(1,QString::number(i+1));
        item->setText(2,suppliers[i]->getName());
        item->setText(3,suppliers[i]->getAdress()->getStreetWithNumber());
        item->setText(4,suppliers[i]->getAdress()->getCity());

        if (suppliers[i]->isPayer())
        {
            item->setTextColor(5,QColor(0,150,0));
            item->setText(5,"ano");
        }
        else
        {
            item->setTextColor(5,QColor(255,0,0));
            item->setText(5,"nie");
        }
        item->setIcon(6,QIcon(":/icon/Data/deleteClose.png"));
        ui->treeWidget->addTopLevelItem(item);
    }
    qDeleteAll(suppliers);
}

void SuppliersPage::on_buttonBack_clicked()
{
    auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    w->Start();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void SuppliersPage::on_buttonAddSupplier_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::ADDSUPPLIER);
}


void SuppliersPage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << column;
    int lastColumn = 6;
    if (lastColumn == column)
    {
        int id = item->text(0).toInt();
        auto w = (QuestionPage*)stackedWidget->widget((int)PageNumber::QUESTION_SUPPLIER);
        w->SetID(id);
        w->SetName(item->text(2));
        stackedWidget->setCurrentIndex((int)PageNumber::QUESTION_SUPPLIER);
        return;
    }
}

void SuppliersPage::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (column == 6)
        return;
    int id = item->text(0).toInt();
    GetSupplierQuerry q;
    auto entity = q.GetOneById(id);
    qDebug() << entity->getId() << entity->getName() << entity->getAdress()->getId();
    auto w = (AddSupplierPage*)stackedWidget->widget((int)PageNumber::ADDSUPPLIER);
    w->SetSupplierEntity(entity);
    stackedWidget->setCurrentIndex((int)PageNumber::ADDSUPPLIER);
}
