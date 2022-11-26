#include "customgraphicsview.h"

#include <PDF/Creator/invoicecreator.h>

CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QWidget(parent)
{
}

void CustomGraphicsView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    if (invoice == nullptr)
        return;
    QPainter paint(this);

    InvoiceCreator creator;
    auto invoiceGenerator = creator.Create(&paint,invoice->getInvoiceType());
    invoiceGenerator->scroll(scrollValue);
    invoiceGenerator->Generate(invoice);
    delete invoiceGenerator;
}

void CustomGraphicsView::SetInvoice(InvoiceEntity *invoice)
{
    this->invoice = invoice;
}
