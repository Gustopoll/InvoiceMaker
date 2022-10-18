#include "pdfinvoicegenerator.h"

PDFInvoiceGenerator::PDFInvoiceGenerator()
{
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(QCoreApplication::applicationDirPath() + "/realTEST.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    bold = QFont("Calibri", 11);
    bold.setBold(true);
    classic = QFont("Calibri", 11);
    qDebug() << printer.width() << printer.height();

    if (!painter->begin(&printer))
    {
        qDebug() << "no draw";
        return;
    }
}

PDFInvoiceGenerator::PDFInvoiceGenerator(QPainter *paint)
{
    painter = paint;
    bold = QFont("Calibri", 11);
    bold.setBold(true);
    classic = QFont("Calibri", 11);
    qDebug() << printer.width() << printer.height();
}

void PDFInvoiceGenerator::Generate(InvoiceEntity *invoice)
{
    painter->setFont(classic);
    painter->setPen(pen);

    SupplierGenerate(invoice->getSupplierSaved());
    CustomerGenerate(invoice->getCustomerSaved());

    newLine();
    newLine();
    newLine();
    LineGenerate(newLine());

    OtherGenerate(invoice);

    painter->end();

}

void PDFInvoiceGenerator::SupplierGenerate(SupplierEntity *entity)
{
    painter->drawText(leftBorder,newLine(),"Faktúra číslo: 1/2022");
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

void PDFInvoiceGenerator::CustomerGenerate(CustomerEntity *entity)
{
    countLine = 135; // nový stĺpec
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

void PDFInvoiceGenerator::LineGenerate(int posY)
{
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(leftBorder,posY,653,posY);
    painter->setPen(pen);
}

void PDFInvoiceGenerator::OtherGenerate(InvoiceEntity *invoice)
{
    newLine();
    int sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Dátum vystavenia");
    painter->drawText(leftBorder + 200,sameLine,"Dátum dodania");
    painter->drawText(leftBorder + 400,sameLine,"Dátum splatnosti");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"15.8.2022");
    painter->drawText(leftBorder + 200,sameLine,"31.07.2022");
    painter->drawText(leftBorder + 400,sameLine,"25.8.2022");

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
    painter->drawText(leftBorder,sameLine,"NL66ABNA1272753638");
    painter->drawText(leftBorder + 200,sameLine,"UNCRSKBX");
    painter->drawText(leftBorder + 300,sameLine,"2622");
    painter->drawText(leftBorder + 400,sameLine,"93 542,22 EUR");

    newLine(); newLine();
    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Spôsob úhrady");
    painter->drawText(leftBorder + 200,sameLine,"Objednávky");

    sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Hotovosť");
    painter->drawText(leftBorder + 200,sameLine,"1/2022");


}

int PDFInvoiceGenerator::newLine()
{
    countLine += 20;
    return countLine;
}
