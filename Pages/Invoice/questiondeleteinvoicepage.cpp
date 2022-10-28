#include "questiondeleteinvoicepage.h"
#include "ui_questiondeleteinvoicepage.h"
#include <QDebug>
#include <Extensions/customstyle.h>
#include <Repositories/Querry/DeleteQuerry/deleteinvoicequerry.h>
#include <Pages/mainpage.h>

QuestionDeleteInvoicePage::QuestionDeleteInvoicePage(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::QuestionDeleteInvoicePage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;
    CustomStyle cs;
    ui->buttonYes->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonNo->setStyleSheet(cs.RedButtonStyle());
}

QuestionDeleteInvoicePage::~QuestionDeleteInvoicePage()
{
    delete ui;
}

void QuestionDeleteInvoicePage::SetName(QString name)
{
    ui->labelName->setText("faktúra od " + name);
}

void QuestionDeleteInvoicePage::SetID(int id)
{
    idInvoice = id;
}

void QuestionDeleteInvoicePage::ResetAll()
{
    ui->labelName->clear();
}

void QuestionDeleteInvoicePage::on_buttonYes_clicked()
{
    DeleteInvoiceQuerry q;
    q.Delete(idInvoice);
    qDebug() << q.GetLastError();

    ResetAll();
    auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    w->Start();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void QuestionDeleteInvoicePage::on_buttonNo_clicked()
{
    ResetAll();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}
