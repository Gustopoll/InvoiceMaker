#ifndef CANCELEDINVOICE_H
#define CANCELEDINVOICE_H

#include "invoice.h"

class CanceledInvoice : public Invoice
{
public:
    CanceledInvoice(QString pathfile);
    CanceledInvoice(QPainter *paint);

    void Generate(InvoiceEntity *invoice) override;

    ~CanceledInvoice();
private:
    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);
    void OtherGenerate(InvoiceEntity *invoice);

    int factureNumberCanceled = 0;
    int factureNumber = 0;
};

#endif // CANCELEDINVOICE_H
