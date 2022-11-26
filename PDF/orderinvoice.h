#ifndef ORDERINVOICE_H
#define ORDERINVOICE_H

#include "invoice.h"

class OrderInvoice : public Invoice
{
public:
    OrderInvoice(QString pathfile);
    OrderInvoice(QPainter *paint);

    void Generate(InvoiceEntity *invoice) override;

    ~OrderInvoice();
private:
    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);
    void OtherGenerate(InvoiceEntity *invoice);
};

#endif // ORDERINVOICE_H
