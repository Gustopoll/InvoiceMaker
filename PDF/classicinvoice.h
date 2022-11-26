#ifndef CLASSICINVOICE_H
#define CLASSICINVOICE_H

#include "invoice.h"

class ClassicInvoice : public Invoice
{
public:
    ClassicInvoice(QString pathfile);
    ClassicInvoice(QPainter *paint);

    void Generate(InvoiceEntity *invoice) override;

    ~ClassicInvoice();
private:
    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);
    void OtherGenerate(InvoiceEntity *invoice);

};

#endif // CLASSICINVOICE_H
