#ifndef INVOICEPAGE2_H
#define INVOICEPAGE2_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <QDate>
#include <Extensions/datehelper.h>
#include <Controller/customercontroller.h>
#include <Controller/iteminvoicecontroller.h>
#include <Controller/settingscontroller.h>
#include <Controller/suppliercontroller.h>

namespace Ui {
class InvoicePage;
}

class InvoicePage : public QWidget
{
    Q_OBJECT

public:
    explicit InvoicePage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~InvoicePage();

    void Update();
    void resizeEvent(QResizeEvent *event);
private slots:
    void on_buttonNext2_clicked();
    void on_buttonBackToMenu_clicked();
    void on_buttonBackTo1_clicked();
    void on_buttonNext3_clicked();
    void on_buttonBackTo2_clicked();
    void on_buttonSave_clicked();
    void on_comboBoxPayment_currentIndexChanged(int index);
    void on_checkBoxDPHPayer_stateChanged(int arg1);
    void on_comboBoxV_currentIndexChanged(int index);
    void on_comboBoxDday_currentIndexChanged(int index);
    void on_comboBoxS_currentIndexChanged(int index);
    void on_comboBoxDmonth_currentIndexChanged(int index);
    void on_dateEditV_dateChanged(const QDate &date);

    void on_comboBoxSupplier_currentIndexChanged(int index);
    void on_comboBoxCustomer_currentIndexChanged(int index);

    void on_buttonAddItem_clicked();
    void on_spinBoxCount_valueChanged(int arg1);
    void on_doubleSpinBoxPrice_valueChanged(double arg1);
    void on_doubleSpinBoxDPH_item_valueChanged(double arg1);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_doubleSpinBoxDPH_valueChanged(double arg1);



    void on_buttonX1_clicked();

    void on_buttonX2_clicked();

    void on_buttonX3_clicked();

private:
    Ui::InvoicePage *ui;
    QStackedWidget *stackedWidget;
    SettingsController* settingsController;
    SupplierController *supplierController;
    CustomerController *customerController;
    ItemInvoiceController* itemInvoiceController;
};

#endif // INVOICEPAGE2_H
