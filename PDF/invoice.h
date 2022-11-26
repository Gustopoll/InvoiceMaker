#ifndef INVOICE_H
#define INVOICE_H

#include <QApplication>
#include <QPdfWriter>
#include <QPrinter>
#include <QTextDocument>
#include <QFile>
#include <QPainter>
#include <QGraphicsView>
#include "Entities/invoiceentity.h"

class Invoice
{
public:
    Invoice(QString pathfile);
    Invoice(QPainter *paint);

    virtual ~Invoice() {}
    virtual void Generate(InvoiceEntity *invoice) = 0;
    void scroll(int dx);

protected:
    QPrinter printer;
    QPainter *painter;

    QPen pen;
    QFont bold;
    QFont classic;

    int countLine = 90;
    int leftBorder = 100;

    int newLine();
    void LineGenerate(int posY);
    void ItemsGeneratorSameDPH(InvoiceEntity *invoice);
    void ItemsGeneratorNoSameDPH(InvoiceEntity* invoice);

    bool AllItemHasSameDPH(InvoiceEntity* entity);
    bool isPDF;
};

#endif // INVOICE_H
