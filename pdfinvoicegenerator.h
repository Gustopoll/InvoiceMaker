#ifndef PDFINVOICEGENERATOR_H
#define PDFINVOICEGENERATOR_H

#include <QApplication>
#include <QPdfWriter>
#include <QPrinter>
#include <QTextDocument>
#include <QFile>
#include <QPainter>
#include <QGraphicsView>
#include "Entities/invoiceentity.h"

#include <QDebug>

class PDFInvoiceGenerator
{
public:
    PDFInvoiceGenerator(QString pathfile);
    PDFInvoiceGenerator(QPainter *frame);

    void Generate(InvoiceEntity *invoice);
private:

    QPrinter printer;
    QPainter *painter;

    QPen pen;
    QFont bold;
    QFont classic;

    int countLine = 90;
    int leftBorder = 100;

    //on the left side of invoice
    void SupplierGenerate(SupplierEntity* entity);

    //on the right side of invoice
    void CustomerGenerate(CustomerEntity* entity);

    void LineGenerate(int posY);

    void OtherGenerate(InvoiceEntity *invoice);

    int newLine();

};

#endif // PDFINVOICEGENERATOR_H
