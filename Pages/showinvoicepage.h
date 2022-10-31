#ifndef SHOWINVOICEPAGE_H
#define SHOWINVOICEPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include "PagesNumbers.h"
#include "../Extensions/customstyle.h"
#include "../Entities/invoiceentity.h"

namespace Ui {
class ShowInvoicePage;
}

class ShowInvoicePage : public QWidget
{
    Q_OBJECT

public:
    explicit ShowInvoicePage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~ShowInvoicePage();

    void wheelEvent(QWheelEvent *event);
    void SetInvoice(InvoiceEntity *invoice);
private slots:
    void on_buttonBack_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

private:
    Ui::ShowInvoicePage *ui;
    QStackedWidget *stackedWidget;
};

#endif // SHOWINVOICEPAGE_H
