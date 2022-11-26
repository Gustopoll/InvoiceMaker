#include "canceledinvoice.h"

#include <Extensions/typeinvoicemapper.h>

CanceledInvoice::CanceledInvoice(QString pathfile) : Invoice(pathfile)
{

}

CanceledInvoice::CanceledInvoice(QPainter *paint) : Invoice(paint)
{

}

void CanceledInvoice::Generate(InvoiceEntity *invoice)
{
    painter->setFont(classic);
    painter->setPen(pen);

    factureNumber = invoice->getSupplierSaved()->getFactureNumberClassic();
    factureNumberCanceled = invoice->getSupplierSaved()->getFactureNumberCanceled();
    SupplierGenerate(invoice->getSupplierSaved());
    CustomerGenerate(invoice->getCustomerSaved());

    newLine();
    newLine();
    newLine();
    LineGenerate(newLine());

    OtherGenerate(invoice);
    if (AllItemHasSameDPH(invoice) == true)
        ItemsGeneratorSameDPH(invoice);
    else
        ItemsGeneratorNoSameDPH(invoice);
    painter->end();
}

CanceledInvoice::~CanceledInvoice()
{

}

void CanceledInvoice::SupplierGenerate(SupplierEntity *entity)
{
    painter->drawText(leftBorder,newLine(),"Dobropis číslo: " + QString::number(factureNumberCanceled));
    painter->drawText(leftBorder,newLine(),"K faktúre číslo: " + QString::number(factureNumber));
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

void CanceledInvoice::CustomerGenerate(CustomerEntity *entity)
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

void CanceledInvoice::OtherGenerate(InvoiceEntity *invoice)
{
    newLine();
    int sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Dátum vystavenia");
    painter->drawText(leftBorder + 200,sameLine,"Dátum dodania");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine, invoice->getDateV().toString("dd.MM.yyyy"));
    painter->drawText(leftBorder + 200,sameLine,invoice->getDateD().toString("dd.MM.yyyy"));

    newLine(); newLine(); newLine();
    sameLine = newLine();

    //draw rectangle
    painter->setPen(QPen(Qt::black, 1));
    painter->drawRect(leftBorder - 20, sameLine - 20, 600, 46);
    painter->setPen(pen);

    painter->drawText(leftBorder,sameLine,"IBAN");
    painter->drawText(leftBorder + 200,sameLine,"SWIFT");
    painter->drawText(leftBorder + 300,sameLine,"VS");
    painter->drawText(leftBorder + 400,sameLine,"Suma na úhradu");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,invoice->getSupplierSaved()->getBankinfo()->getIBAN());
    painter->drawText(leftBorder + 200,sameLine,invoice->getSupplierSaved()->getBankinfo()->getSWIFT());
    painter->drawText(leftBorder + 300,sameLine,invoice->getSupplierSaved()->getBankinfo()->getVS());
    painter->drawText(leftBorder + 400,sameLine, QString::number(invoice->GetTotalPrice(),'f',2) + " EUR");

    newLine(); newLine();
    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Spôsob úhrady");
    painter->drawText(leftBorder + 200,sameLine,"Objednávky");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,TypeInvoiceMapper::toString(invoice->getPaymentMethon()));
    QString objednavky = QString::number(invoice->getSupplierSaved()->getFactureNumberCanceled()) + "/" + invoice->getDateV().toString("yyyy");
    painter->drawText(leftBorder + 200,sameLine,objednavky);
}
