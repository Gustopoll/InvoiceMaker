#include "showinvoicepage.h"
#include "ui_showinvoicepage.h"

#include "../pdfinvoicegenerator.h"

ShowInvoicePage::ShowInvoicePage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::ShowInvoicePage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonBack->setStyleSheet(cs.ClassicButtonStyle());
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
    ui->graphicsView->SetInvoice(invoice);
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
