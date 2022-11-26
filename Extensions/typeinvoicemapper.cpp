#include "typeinvoicemapper.h"

TypeInvoiceMapper::TypeInvoiceMapper()
{

}

QString TypeInvoiceMapper::toString(Payment payment)
{
    if (payment == Payment::Bank)
        return "Bankový prevod";
    if (payment == Payment::Cash)
        return "Hotovosť";
    return "";
}

QString TypeInvoiceMapper::toString(InvoiceType type)
{
    if (type == InvoiceType::Faktura)
       return "Faktúra";
    if (type == InvoiceType::Dobropis)
        return "Dobropis";
    if (type == InvoiceType::Objednavka)
        return "Objednávka";
    if (type == InvoiceType::Cenova_ponuka)
        return "Cenová ponuka";
    if (type == InvoiceType::Zalohova_faktura)
        return "Zálohová faktúra";
    return "";
}

QColor TypeInvoiceMapper::getInvoiceTypeColor(InvoiceType type)
{
    if (type == InvoiceType::Faktura)
       return QColor(Qt::darkGreen);
    if (type == InvoiceType::Dobropis)
        return QColor(Qt::red);
    if (type == InvoiceType::Objednavka)
        return QColor(Qt::darkBlue);
    if (type == InvoiceType::Cenova_ponuka)
        return QColor(Qt::darkMagenta);
    if (type == InvoiceType::Zalohova_faktura)
        return QColor(Qt::darkCyan);
    return QColor(Qt::black);
}
