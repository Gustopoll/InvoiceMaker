#include "showinvoicepage.h"
#include "ui_showinvoicepage.h"

#include <Pages/NewInvoice/invoicepage.h>


ShowInvoicePage::ShowInvoicePage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::ShowInvoicePage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonBack->setStyleSheet(cs.ClassicButtonStyle());
    ui->buttonStorno->setStyleSheet(cs.RedButtonStyle());
}

ShowInvoicePage::~ShowInvoicePage()
{
    delete ui;
}

void ShowInvoicePage::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0)
    {
        ui->graphicsView->scrollValue += 50;
        if (ui->graphicsView->scrollValue > 90)
            ui->graphicsView->scrollValue = 90;
    }
    else
    {
        ui->graphicsView->scrollValue -= 50;
    }

    ui->verticalScrollBar->setValue(-ui->graphicsView->scrollValue/50);
    ui->graphicsView->update();
}

void ShowInvoicePage::SetInvoice(InvoiceEntity *invoice)
{
    //clean before start
    ui->graphicsView->scrollValue = 50; //default value
    ui->verticalScrollBar->setValue(0);

    ui->graphicsView->SetInvoice(invoice);
    this->invoice = invoice;
    if (invoice->getInvoiceType() == InvoiceType::Dobropis)
        ui->buttonStorno->setVisible(false);
    else
        ui->buttonStorno->setVisible(true);
}

void ShowInvoicePage::on_buttonBack_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void ShowInvoicePage::on_verticalScrollBar_sliderMoved(int position)
{
    ui->graphicsView->scrollValue = (-position * 50) +90;
    ui->graphicsView->update();
}

void ShowInvoicePage::on_buttonStorno_clicked()
{
    auto w = (InvoicePage*)stackedWidget->widget((int)PageNumber::INVOICE);
    w->Update();
    //todo doplne auto info z faktury
    w->SetDobropis(invoice);
    stackedWidget->setCurrentIndex((int)PageNumber::INVOICE);
}
