#ifndef PRICEOFFERINVOICE_H
#define PRICEOFFERINVOICE_H

#include "invoice.h"

class PriceOfferInvoice : public Invoice
{
public:
    PriceOfferInvoice(QString pathfile);
    PriceOfferInvoice(QPainter *paint);

    void Generate(InvoiceEntity *invoice) override;

    ~PriceOfferInvoice();
private:
    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);
    void OtherGenerate(InvoiceEntity *invoice);
};

#endif // PRICEOFFERINVOICE_H
