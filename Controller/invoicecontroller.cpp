#include "invoicecontroller.h"

InvoiceController::InvoiceController()
{
    idCustomer = -1;
    idSupplier = -1;
}

InvoiceEntity *InvoiceController::Create()
{
    InvoiceEntity* entity = new InvoiceEntity();
    entity->setInvoiceType((InvoiceType)comboBoxType->currentIndex());
    entity->setPaymentMethon((Payment)comboBoxPayment->currentIndex());
    entity->setDateV(dateEditV->date());
    entity->setDateD(dateEditD->date());
    entity->setDateS(dateEditS->date());

    entity->setSupplierSaved(supplierSavedEntity);
    entity->setCustomerSaved(customerSavedEntity);
    entity->setIdSupplier(idSupplier);
    entity->setIdCustomer(idCustomer);

    for (int i = 0; i < items.size(); i++)
        entity->addItem(items[i]);

    return entity;
}

void InvoiceController::setComboBoxType(QComboBox *value)
{
    comboBoxType = value;
}

void InvoiceController::setDateEditV(QDateEdit *value)
{
    dateEditV = value;
}

void InvoiceController::setDateEditD(QDateEdit *value)
{
    dateEditD = value;
}

void InvoiceController::setDateEditS(QDateEdit *value)
{
    dateEditS = value;
}

void InvoiceController::setComboBoxPayment(QComboBox *value)
{
    comboBoxPayment = value;
}

void InvoiceController::setSupplierSavedEntity(SupplierEntity *value)
{
    supplierSavedEntity = value;
}

void InvoiceController::setCustomerSavedEntity(CustomerEntity *value)
{
    customerSavedEntity = value;
}

void InvoiceController::setIdCustomer(int value)
{
    idCustomer = value;
}

void InvoiceController::setIdSupplier(int value)
{
    idSupplier = value;
}

void InvoiceController::addItem(ItemEntity* value)
{
    items.push_back(value);
}
