#ifndef DEPOSTIINVOICE_H
#define DEPOSTIINVOICE_H

#include "invoice.h"

class DepostiInvoice : public Invoice
{
public:
    DepostiInvoice(QString pathfile);
    DepostiInvoice(QPainter *paint);

    void Generate(InvoiceEntity *invoice) override;

    ~DepostiInvoice();
private:
    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);
    void OtherGenerate(InvoiceEntity *invoice);
};

#endif // DEPOSTIINVOICE_H
