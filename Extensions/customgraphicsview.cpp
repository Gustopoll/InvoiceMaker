#include "customgraphicsview.h"

CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QWidget(parent)
{
}

void CustomGraphicsView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    if (invoice == nullptr)
        return;
    QPainter paint(this);
    PDFInvoiceGenerator g(&paint);
    g.scroll(scrollValue);
    g.Generate(invoice);
}

void CustomGraphicsView::SetInvoice(InvoiceEntity *invoice)
{
    this->invoice = invoice;
}
