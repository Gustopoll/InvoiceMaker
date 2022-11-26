#include "orderinvoice.h"

OrderInvoice::OrderInvoice(QString pathfile) : Invoice(pathfile)
{

}

OrderInvoice::OrderInvoice(QPainter *paint) : Invoice(paint)
{

}

OrderInvoice::~OrderInvoice()
{

}

void OrderInvoice::SupplierGenerate(SupplierEntity *entity)
{
    painter->drawText(leftBorder,newLine(),"Objednávka číslo: " + QString::number(entity->getFactureNumberOrder()));
    newLine();

    painter->setFont(bold);
    painter->drawText(leftBorder, newLine(), "Dodávateľ:");
    painter->setFont(classic);

    painter->drawText(leftBorder, newLine(), entity->getName());
    painter->drawText(leftBorder, newLine(), entity->getAdress()->getStreetWithNumber());
    painter->drawText(leftBorder, newLine(), entity->getAdress()->getPSCWithCity());
    painter->drawText(leftBorder, newLine(), entity->getAdress()->getState());
    newLine();
    painter->drawText(leftBorder, newLine(), "IČO: " + entity->getIco());
    if (entity->isPayer())
    {
        painter->drawText(leftBorder, newLine(), "DIČ: " + entity->getPayer()->getDic());
        painter->drawText(leftBorder, newLine(), "IČ DPH: " + entity->getPayer()->getIcdph());
    }
    else
        painter->drawText(leftBorder, newLine(), "DIČ: Nie som platca DPH");
}

void OrderInvoice::CustomerGenerate(CustomerEntity *entity)
{
    countLine -= 155; // nový stĺpec (135)
    int len = 500; // od kade začína pravý stlpec (hodnota x)

    painter->setFont(bold);
    painter->drawText(len, newLine(), "Odberateľ:");
    painter->setFont(classic);

    painter->drawText(len, newLine(), entity->getName());
    painter->drawText(len, newLine(), entity->getAdress()->getStreetWithNumber());
    painter->drawText(len, newLine(), entity->getAdress()->getPSCWithCity());
    painter->drawText(len, newLine(), entity->getAdress()->getState());
    newLine();
    painter->drawText(len, newLine(), "IČO: " + entity->getIco());
    painter->drawText(len, newLine(), "DIČ: " + entity->getPayer()->getDic());
    painter->drawText(len, newLine(), "IČ DPH: " + entity->getPayer()->getIcdph());
}

void OrderInvoice::OtherGenerate(InvoiceEntity *invoice)
{
    newLine();
    int sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Dátum vytvorenia");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine, invoice->getDateV().toString("dd.MM.yyyy"));

    newLine();
}

void OrderInvoice::Generate(InvoiceEntity *invoice)
{
    painter->setFont(classic);
    painter->setPen(pen);

    SupplierGenerate(invoice->getSupplierSaved());
    CustomerGenerate(invoice->getCustomerSaved());

    newLine();
    LineGenerate(newLine());

    OtherGenerate(invoice);
    if (AllItemHasSameDPH(invoice) == true)
        ItemsGeneratorSameDPH(invoice);
    else
        ItemsGeneratorNoSameDPH(invoice);
    painter->end();
}
