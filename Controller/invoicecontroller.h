#ifndef INVOICECONTROLLER_H
#define INVOICECONTROLLER_H

#include <QComboBox>
#include <QDateEdit>
#include <Entities/invoiceentity.h>
#include <Entities/supplierentity.h>
#include <Entities/customerentity.h>

class InvoiceController
{
public:
    InvoiceController();

    InvoiceEntity* Create();

    void setComboBoxType(QComboBox *value);
    void setDateEditV(QDateEdit *value);
    void setDateEditD(QDateEdit *value);
    void setDateEditS(QDateEdit *value);
    void setComboBoxPayment(QComboBox *value);
    void setSupplierSavedEntity(SupplierEntity *value);
    void setCustomerSavedEntity(CustomerEntity *value);
    void setIdCustomer(int value);
    void setIdSupplier(int value);
    void addItem(ItemEntity* value);

private:
    QComboBox* comboBoxType;
    QDateEdit* dateEditV;
    QDateEdit* dateEditD;
    QDateEdit* dateEditS;
    QComboBox* comboBoxPayment;

    SupplierEntity* supplierSavedEntity;
    CustomerEntity* customerSavedEntity;
    int idCustomer;
    int idSupplier;

    QList<ItemEntity*> items;

};

#endif // INVOICECONTROLLER_H
