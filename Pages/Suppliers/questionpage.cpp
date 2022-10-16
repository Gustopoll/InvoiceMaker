#include "questionpage.h"
#include "ui_questionpage.h"


QuestionPage::QuestionPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::QuestionPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;
    CustomStyle cs;
    ui->buttonYes->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonNo->setStyleSheet(cs.RedButtonStyle());
}

QuestionPage::~QuestionPage()
{
    delete ui;
}

void QuestionPage::SetID(int id)
{
    this->id = id;
}

void QuestionPage::SetName(QString name)
{
    ui->labelName->setText(name);
}

void QuestionPage::on_buttonYes_clicked()
{
    auto deleteAll =ui->checkBox->checkState();

    if (deleteAll == Qt::CheckState::Checked)
    {
        DeleteSupplierQuerry q;
        q.Delete(id);
        qDebug() << q.GetLastError();
    }
    else
    {
        UpdateSupplierQuerry q;
        q.UpdateParameter(id,"isdeleted","1");
        qDebug() << q.GetLastError();
    }
    ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
    auto w = (SuppliersPage*)stackedWidget->widget((int)PageNumber::SUPPLIERS);
    w->Update();

    stackedWidget->setCurrentIndex((int)PageNumber::SUPPLIERS);
}

void QuestionPage::on_buttonNo_clicked()
{
    ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
    stackedWidget->setCurrentIndex((int)PageNumber::SUPPLIERS);
}
