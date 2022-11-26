#include "invoicecreator.h"

#include <PDF/canceledinvoice.h>
#include <PDF/orderinvoice.h>
#include <PDF/priceofferinvoice.h>

InvoiceCreator::InvoiceCreator()
{

}

Invoice* InvoiceCreator::Create(QPainter *paint, InvoiceType type)
{
    if (type == InvoiceType::Faktura)
        return new ClassicInvoice(paint);

    if (type == InvoiceType::Zalohova_faktura)
        return new DepostiInvoice(paint);

    if (type == InvoiceType::Objednavka)
        return new OrderInvoice(paint);

    if (type == InvoiceType::Cenova_ponuka)
        return new PriceOfferInvoice(paint);

    if (type == InvoiceType::Dobropis)
        return new CanceledInvoice(paint);

    return nullptr;
}

Invoice *InvoiceCreator::Create(QString path, InvoiceType type)
{
    if (type == InvoiceType::Faktura)
        return new ClassicInvoice(path);

    if (type == InvoiceType::Zalohova_faktura)
        return new DepostiInvoice(path);

    if (type == InvoiceType::Objednavka)
        return new OrderInvoice(path);

    if (type == InvoiceType::Cenova_ponuka)
        return new PriceOfferInvoice(path);

    if (type == InvoiceType::Dobropis)
        return new CanceledInvoice(path);

    return nullptr;
}
