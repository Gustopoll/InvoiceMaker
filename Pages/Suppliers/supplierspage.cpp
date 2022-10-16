#include "addsupplierpage.h"
#include "supplierspage.h"
#include "ui_supplierspage.h"

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
    Update();
}

SuppliersPage::~SuppliersPage()
{
    delete ui;
}

void SuppliersPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/7;
    ui->treeWidget->setColumnWidth(0,sizeOne/3);
    ui->treeWidget->setColumnWidth(1,sizeOne*2);
    ui->treeWidget->setColumnWidth(2,sizeOne*2);
    ui->treeWidget->setColumnWidth(3,sizeOne);
    ui->treeWidget->setColumnWidth(4,sizeOne/3);
    ui->treeWidget->setColumnWidth(5,sizeOne/2);
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
        item->setText(1,suppliers[i]->getName());
        item->setText(2,suppliers[i]->getAdress()->getStreetWithNumber());
        item->setText(3,suppliers[i]->getAdress()->getCity());

        if (suppliers[i]->isPayer())
        {
            item->setTextColor(4,QColor(0,150,0));
            item->setText(4,"ano");
        }
        else
        {
            item->setTextColor(4,QColor(255,0,0));
            item->setText(4,"nie");
        }
        item->setText(5,QString::number(suppliers[i]->getFactureNumber()));
        item->setIcon(6,QIcon(":/icon/Data/deleteClose.png"));
        ui->treeWidget->addTopLevelItem(item);
    }
    qDeleteAll(suppliers);
}

void SuppliersPage::on_buttonBack_clicked()
{
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
        w->SetName(item->text(1));
        stackedWidget->setCurrentIndex((int)PageNumber::QUESTION_SUPPLIER);
        return;
    }

    int id = item->text(0).toInt();
    GetSupplierQuerry q;
    auto entity = q.GetOneById(id);
    qDebug() << entity->getId() << entity->getName() << entity->getAdress()->getId();
    auto w = (AddSupplierPage*)stackedWidget->widget((int)PageNumber::ADDSUPPLIER);
    w->SetSupplierEntity(entity);
    stackedWidget->setCurrentIndex((int)PageNumber::ADDSUPPLIER);

}
