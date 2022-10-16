#include "customgraphicsview.h"

CustomGraphicsView::CustomGraphicsView(QWidget *parent) : QWidget(parent)
{
}

void CustomGraphicsView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    if (invoice == nullptr)
        return;
    qDebug() << "InvoiceEntity creating";
    QPainter paint(this);
    PDFInvoiceGenerator g(&paint);
    g.Generate(invoice);
}

void CustomGraphicsView::SetInvoice(InvoiceEntity *invoice)
{
    qDebug() << "set from CustomGraphicsView";
    this->invoice = invoice;
}
