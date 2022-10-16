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
    currentScrollValue = 0;
}

ShowInvoicePage::~ShowInvoicePage()
{
    delete ui;
}

void ShowInvoicePage::wheelEvent(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0) //wheel up
        currentScrollValue += 50;
    else //wheel down
        currentScrollValue -= 50;

    if (currentScrollValue >= 0)
        currentScrollValue = 0;

    ui->graphicsView->move(0,currentScrollValue);
    ui->verticalScrollBar->setValue(-currentScrollValue/50);
    qDebug() << currentScrollValue;
    ui->graphicsView->update();
}

void ShowInvoicePage::SetInvoice(InvoiceEntity *invoice)
{
    qDebug() << "set from showinvoice";
    ui->graphicsView->SetInvoice(invoice);
}

void ShowInvoicePage::setValue(int i)
{
    ui->graphicsView->move(0,-i*50);
    ui->graphicsView->update();
}

void ShowInvoicePage::on_buttonBack_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void ShowInvoicePage::on_verticalScrollBar_sliderMoved(int position)
{
    ui->graphicsView->move(0,-position*50);
}
