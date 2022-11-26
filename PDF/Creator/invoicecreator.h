#ifndef INVOICECREATOR_H
#define INVOICECREATOR_H

#include <PDF/invoice.h>
#include <PDF/classicinvoice.h>
#include <PDF/depostiinvoice.h>

class InvoiceCreator
{
public:
    InvoiceCreator();

    Invoice* Create(QPainter *paint, InvoiceType type);
    Invoice* Create(QString path, InvoiceType type);
};

#endif // INVOICECREATOR_H
