#ifndef ITEMINVOICECONTROLLER_H
#define ITEMINVOICECONTROLLER_H

#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class ItemInvoiceController
{
public:
    ItemInvoiceController();

    void AddSpinBoxCount(QSpinBox* spinBox);
    void AddLineEditDescription(QLineEdit* lineEdit);
    void AddDoubleSpinBoxPrice(QDoubleSpinBox* doubleSpinBox);
    void AddDoubleSpinBoxDPH(QDoubleSpinBox* doubleSpinBox);
    void AddLabelTotalPrice(QLabel* label);
    void AddLabelSumTotalPrice(QLabel* label);

    void CreateItem(QTreeWidget* widget);
    void Update();
    void Clear(QTreeWidget* widget);

    void DeleteItem(QTreeWidget* widget, QTreeWidgetItem *item);
private:
    QSpinBox* spinBoxCount;
    QLineEdit* lineEditDescription;
    QDoubleSpinBox* doubleSpinBoxPrice;
    QDoubleSpinBox* doubleSpinBoxDPH;
    QLabel* labelTotalPrice;
    QLabel* labelSumTotalPrice;

    double ComputeTotalPrice();
    double ComputeSumTotalPrice(QTreeWidget *widget);
};

#endif // ITEMINVOICECONTROLLER_H
