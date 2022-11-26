#include "invoice.h"
#include <QDebug>

Invoice::Invoice(QString pathfile)
{
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(pathfile);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    bold = QFont("Calibri", 11);
    bold.setBold(true);
    classic = QFont("Calibri", 11);
    qDebug() << printer.width() << printer.height();
    qDebug() << pathfile;

    painter = new QPainter();
    if (!painter->begin(&printer))
    {
        qDebug() << "no draw";
        return;
    }
    isPDF = true;
}

Invoice::Invoice(QPainter *paint)
{
    painter = paint;
    painter->fillRect(0,0,5000,5000,QBrush(Qt::white));
    bold = QFont("Calibri", 11);
    bold.setBold(true);
    classic = QFont("Calibri", 11);
    qDebug() << printer.width() << printer.height();
    isPDF = false;
}

void Invoice::scroll(int dx)
{
    countLine = dx;
}

int Invoice::newLine()
{
    countLine += 20;
    return countLine;
}

void Invoice::LineGenerate(int posY)
{
    painter->setPen(QPen(Qt::black, 1));
    painter->drawLine(leftBorder,posY,653,posY);
    painter->setPen(pen);
}

void Invoice::ItemsGeneratorSameDPH(InvoiceEntity *invoice)
{
    newLine();
    int sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Č.  Názov položky");
    painter->drawText(leftBorder + 300, sameLine,"Počet MJ");
    painter->drawText(leftBorder + 400, sameLine,"Jedn. cena");
    painter->drawText(leftBorder + 500, sameLine,"Cena spolu");
    LineGenerate(newLine());

    newLine();
    sameLine = newLine();
    auto items = invoice->getItems();
    double totalNoDPH = 0;
    for (int i = 0; i < items.size(); i++)
    {
        auto item = items[i];
        totalNoDPH += ( item->getCount() * item->getPrice());
        painter->drawText(leftBorder,countLine,QString::number(i+1) + ".");
        painter->drawText(leftBorder + 300, countLine, QString::number(item->getCount(),'f',2));
        painter->drawText(leftBorder + 400, countLine, QString::number(item->getPrice(),'f',2));
        painter->drawText(leftBorder + 500, countLine, QString::number(item->getCount() * item->getPrice(),'f',2));

        auto words = items[i]->getDescription().split(' ');
        QString oneLineWord;
        for (int j = 0; j < words.size(); j++)
        {
            if (oneLineWord.size() > 30)
            {
                painter->drawText(leftBorder+20,countLine,oneLineWord);
                newLine();
                oneLineWord.clear();
            }
            oneLineWord += words[j] + ' ';
        }
        if (oneLineWord.isEmpty() == false)
            painter->drawText(leftBorder+20,countLine,oneLineWord);
        newLine();
        newLine();
    }

    newLine();
    painter->drawText(leftBorder + 300, newLine(),"Celkom bez DPH");
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number(totalNoDPH,'f',2));

    painter->drawText(leftBorder + 300, newLine(),"DPH " + QString::number(items[0]->getDPH()) + "%");
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number( totalNoDPH * (items[0]->getDPH()/100) ,'f',2));

    painter->setFont(bold);
    painter->drawText(leftBorder + 300, newLine(),"Celkom s DPH");
    painter->setFont(classic);
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number(invoice->GetTotalPrice(),'f',2));
}

void Invoice::ItemsGeneratorNoSameDPH(InvoiceEntity *invoice)
{
    newLine();
    int sameLine = newLine();
    painter->drawText(leftBorder,sameLine,"Č.  Názov položky");
    painter->drawText(leftBorder + 290, sameLine,"Počet MJ");
    painter->drawText(leftBorder + 360, sameLine,"Jedn. cena");
    painter->drawText(leftBorder + 440, sameLine,"DPH(%)");
    painter->drawText(leftBorder + 500, sameLine,"Cena spolu");
    LineGenerate(newLine());

    newLine();
    sameLine = newLine();
    auto items = invoice->getItems();
    double totalNoDPH = 0;
    double totalOnlyDPHPrice = 0;
    for (int i = 0; i < items.size(); i++)
    {
        auto item = items[i];
        double noPDHPrice = item->getCount() * item->getPrice();
        totalNoDPH += noPDHPrice;
        totalOnlyDPHPrice += (noPDHPrice * (item->getDPH()/100));
        painter->drawText(leftBorder,countLine,QString::number(i+1) + ".");
        painter->drawText(leftBorder + 300, countLine, QString::number(item->getCount(),'f',2));
        painter->drawText(leftBorder + 370, countLine, QString::number(item->getPrice(),'f',2));
        painter->drawText(leftBorder + 440, countLine, QString::number(item->getDPH(),'f',2));
        painter->drawText(leftBorder + 500, countLine, QString::number(item->getTotalPrice(),'f',2));

        auto words = items[i]->getDescription().split(' ');
        QString oneLineWord;
        for (int j = 0; j < words.size(); j++)
        {
            if (oneLineWord.size() > 30)
            {
                painter->drawText(leftBorder+20,countLine,oneLineWord);
                newLine();
                oneLineWord.clear();
            }
            oneLineWord += words[j] + ' ';
        }
        if (oneLineWord.isEmpty() == false)
            painter->drawText(leftBorder+20,countLine,oneLineWord);
        newLine();
        newLine();
        if (countLine > 900)
        {
            if (isPDF == true)
            {
                printer.newPage();
                countLine = 50;
            }
            {
                countLine += 50;
            }
        }
    }

    newLine();
    painter->drawText(leftBorder + 300, newLine(),"Celkom bez DPH");
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number(totalNoDPH,'f',2));

    painter->drawText(leftBorder + 300, newLine(),"DPH");
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number( totalOnlyDPHPrice ,'f',2));

    painter->setFont(bold);
    painter->drawText(leftBorder + 300, newLine(),"Celkom s DPH");
    painter->setFont(classic);
    painter->drawText(leftBorder + 440, countLine,"EUR");
    painter->drawText(leftBorder + 500, countLine, QString::number(invoice->GetTotalPrice(),'f',2));
}

bool Invoice::AllItemHasSameDPH(InvoiceEntity *entity)
{
    auto items = entity->getItems();
    if (items.empty() == true)
        return false;

    double dph = items[0]->getDPH();
    for (int i = 1; i < items.size(); i++)
    {
        if (items[i]->getDPH() == dph)
            continue;
        return false;
    }
    return true;
}
