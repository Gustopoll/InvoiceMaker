#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include "../pdfinvoicegenerator.h"

class CustomGraphicsView : public QWidget
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);
    void SetInvoice(InvoiceEntity *invoice);
signals:

private:
    InvoiceEntity *invoice;
};

#endif // CUSTOMGRAPHICSVIEW_H
