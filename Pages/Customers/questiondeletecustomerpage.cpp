#include "customerspage.h"
#include "questiondeletecustomerpage.h"
#include "ui_questiondeletecustomerpage.h"

QuestionDeleteCustomerPage::QuestionDeleteCustomerPage(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::QuestionDeleteCustomerPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonYes->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonNo->setStyleSheet(cs.RedButtonStyle());
}

QuestionDeleteCustomerPage::~QuestionDeleteCustomerPage()
{
    delete ui;
}

void QuestionDeleteCustomerPage::SetName(QString name)
{
    ui->labelName->setText(name);
}

void QuestionDeleteCustomerPage::SetID(int id)
{
    this->idCustomer = id;
}

void QuestionDeleteCustomerPage::ResetAll()
{
    ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
}

void QuestionDeleteCustomerPage::on_buttonYes_clicked()
{
    if (ui->checkBox->checkState() == Qt::CheckState::Checked)
    {
        DeleteCustomerQuerry q;
        q.Delete(idCustomer);
        qDebug() << q.GetLastError();
    }
    else
    {
        UpdateCustomerQuerry q;
        q.UpdateParameter(idCustomer,"isdeleted","1");
        qDebug() << q.GetLastError();
    }


    ResetAll();
    auto w = (CustomersPage*)stackedWidget->widget((int)PageNumber::CUSTOMERS);
    w->Update();
    stackedWidget->setCurrentIndex((int)PageNumber::CUSTOMERS);
}

void QuestionDeleteCustomerPage::on_buttonNo_clicked()
{
    ResetAll();
    stackedWidget->setCurrentIndex((int)PageNumber::CUSTOMERS);
}
