#ifndef TYPEINVOICEMAPPER_H
#define TYPEINVOICEMAPPER_H

#include <Entities/PaymentMethod.h>
#include <Entities/InvoiceType.h>
#include <QColor>
#include <QString>

class TypeInvoiceMapper
{
public:
    TypeInvoiceMapper();

    static QString toString(Payment payment);
    static QString toString(InvoiceType type);

    static QColor getInvoiceTypeColor(InvoiceType type);
};

#endif // TYPEINVOICEMAPPER_H
