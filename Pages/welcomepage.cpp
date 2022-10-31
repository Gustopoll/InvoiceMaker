#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "mainpage.h"
#include "showinvoicepage.h"
#include "Suppliers/supplierspage.h"
#include "Suppliers/addsupplierpage.h"
#include "Suppliers/questionpage.h"
#include "settingspage.h"
#include "loadingpage.h"
#include "Repositories/dbcontext.h"
#include "NewInvoice/invoicepage.h"
#include "Pages/Customers/addcustomerpage.h"
#include "Pages/Customers/customerspage.h"
#include "Pages/Customers/questiondeletecustomerpage.h"

#include <Pages/Invoice/questiondeleteinvoicepage.h>

#include <Pages/DeleteAllQuestion/deleteallquestion.h>

WelcomePage::WelcomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WelcomePage)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WelcomePage::LoadAllPages);

    LoadingPage* loadingPage = new LoadingPage(this,ui->stackedWidget);
    ui->stackedWidget->addWidget(loadingPage);
    this->resize(900,600);

    ui->stackedWidget->setCurrentWidget(loadingPage);

    DBContext *d = new DBContext();
    qDebug() << d->Connect();
    qDebug() << d->CreateTables();

    timer->start();
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::on_actionQuit_triggered()
{
    this->close();
}

void WelcomePage::on_actiondSettings_triggered()
{
    ui->stackedWidget->setCurrentIndex((int)PageNumber::SETTINGS);
}

void WelcomePage::on_actionSuppliers_triggered()
{
    ui->stackedWidget->setCurrentIndex((int)PageNumber::SUPPLIERS);
}

void WelcomePage::on_actionOdberatelia_triggered()
{
    ui->stackedWidget->setCurrentIndex((int)PageNumber::CUSTOMERS);
}

void WelcomePage::LoadAllPages()
{
    qDebug() << "starting timer" << isLoaded;
    if (isLoaded == false)
    {
        //set main page
        MainPage *mainPage = new MainPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(mainPage);
        this->resize(900,600);

        InvoicePage *i = new InvoicePage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(i);

        ShowInvoicePage *p = new ShowInvoicePage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(p);

        SuppliersPage *s = new SuppliersPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(s);

        SettingsPage *n = new SettingsPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(n);

        AddSupplierPage *np = new AddSupplierPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(np);

        QuestionPage* qp = new QuestionPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(qp);

        CustomersPage *customersPage = new CustomersPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(customersPage);

        AddCustomerPage *addCustomerPage = new AddCustomerPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(addCustomerPage);

        QuestionDeleteCustomerPage* question2 = new QuestionDeleteCustomerPage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(question2);

        QuestionDeleteInvoicePage *question3 = new QuestionDeleteInvoicePage(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(question3);

        DeleteAllQuestion *deleteAll = new DeleteAllQuestion(this,ui->stackedWidget);
        ui->stackedWidget->addWidget(deleteAll);

        isLoaded = true;
    }
    else
    {
        timer->stop();
        ui->stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);

    }
}
