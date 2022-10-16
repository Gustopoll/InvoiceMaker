#include "addcustomerpage.h"
#include "customerspage.h"
#include "questiondeletecustomerpage.h"
#include "ui_customerspage.h"

CustomersPage::CustomersPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::CustomersPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonBack->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonAddCustomer->setStyleSheet(cs.GreenButtonStyle());

    ui->treeWidget->setIconSize(QSize(40,40));
    Update();
}

CustomersPage::~CustomersPage()
{
    delete ui;
}
void CustomersPage::resizeEvent(QResizeEvent *event)
{
    auto sizeOne = event->size().width()/5;
    ui->treeWidget->setColumnWidth(0,sizeOne/4);
    ui->treeWidget->setColumnWidth(1,sizeOne*1.5);
    ui->treeWidget->setColumnWidth(2,sizeOne*1.5);
    ui->treeWidget->setColumnWidth(3,sizeOne);
    ui->treeWidget->setColumnWidth(4,5);
}

void CustomersPage::Update()
{
    ui->treeWidget->clear();
    GetCustomerQuerry q;
    auto customers = q.GetAllNoDeleted();

    for (int i =0; i < customers.size(); i++)
    {
        auto item = new QTreeWidgetItem();
        auto customer = customers[i];
        item->setText(0,QString::number(customer->getId()));
        item->setText(1,customer->getName());
        item->setText(2,customer->getAdress()->getStreetWithNumber());
        item->setText(3,customer->getAdress()->getCity());
        item->setIcon(4,QIcon(":/icon/Data/deleteClose.png"));
        ui->treeWidget->addTopLevelItem(item);
    }

}


void CustomersPage::on_buttonAddCustomer_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::ADDCUSTOMER);
}

void CustomersPage::on_buttonBack_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void CustomersPage::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    int lastColumn = 4;
    auto nameCustomer = item->text(1);
    int idCustomer = item->text(0).toInt();

    if (lastColumn == column)
    {
        auto w = (QuestionDeleteCustomerPage*) stackedWidget->widget((int)PageNumber::QUESTION_CUSTOMER);
        w->SetName(nameCustomer);
        w->SetID(idCustomer);
        stackedWidget->setCurrentIndex((int)PageNumber::QUESTION_CUSTOMER);
        return;
    }

    auto w = (AddCustomerPage*) stackedWidget->widget((int)PageNumber::ADDCUSTOMER);

    GetCustomerQuerry q;
    auto entity = q.GetOneById(idCustomer);
    w->SetCustomerEntity(entity);
    stackedWidget->setCurrentIndex((int)PageNumber::ADDCUSTOMER);
}
