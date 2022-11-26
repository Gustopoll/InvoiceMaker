#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsView>

#include <PDF/classicinvoice.h>

class CustomGraphicsView : public QWidget
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget *parent = nullptr);

    virtual void paintEvent(QPaintEvent *e) override;
    void SetInvoice(InvoiceEntity *invoice);
    int scrollValue = 90;

private:
    InvoiceEntity *invoice;
};

#endif // CUSTOMGRAPHICSVIEW_H
