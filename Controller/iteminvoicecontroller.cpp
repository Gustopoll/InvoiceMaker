#include "iteminvoicecontroller.h"
#include <QDebug>

ItemInvoiceController::ItemInvoiceController()
{
    spinBoxCount = nullptr;
    lineEditDescription = nullptr;
    doubleSpinBoxPrice = nullptr;
    doubleSpinBoxDPH = nullptr;
    labelTotalPrice = nullptr;
    labelSumTotalPrice = nullptr;
}

void ItemInvoiceController::AddSpinBoxCount(QSpinBox *spinBox)
{
    this->spinBoxCount = spinBox;
}

void ItemInvoiceController::AddLineEditDescription(QLineEdit *lineEdit)
{
    this->lineEditDescription = lineEdit;
}

void ItemInvoiceController::AddDoubleSpinBoxPrice(QDoubleSpinBox *spinBox)
{
    this->doubleSpinBoxPrice = spinBox;
}

void ItemInvoiceController::AddDoubleSpinBoxDPH(QDoubleSpinBox *spinBox)
{
    this->doubleSpinBoxDPH = spinBox;
}

void ItemInvoiceController::AddLabelTotalPrice(QLabel *label)
{
    this->labelTotalPrice = label;
}

void ItemInvoiceController::AddLabelSumTotalPrice(QLabel *label)
{
    this->labelSumTotalPrice = label;
}

void ItemInvoiceController::CreateItem(QTreeWidget *widget)
{
    widget->setIconSize(QSize(30,30));
    auto item = new QTreeWidgetItem();
    item->setText(0,spinBoxCount->text());
    item->setText(1,lineEditDescription->text());
    item->setText(2,doubleSpinBoxPrice->text());
    item->setText(3,doubleSpinBoxDPH->text());

    double sum  = ComputeTotalPrice();
    item->setText(4,QString::number(sum,'f', 2));

    item->setIcon(5,QIcon(":/icon/Data/deleteClose.png"));

    widget->addTopLevelItem(item);

    double totalSum = ComputeSumTotalPrice(widget);
    labelSumTotalPrice->setText("Cena Celkom: " + QString::number(totalSum,'f', 2) + " €");
}

QList<ItemEntity *> ItemInvoiceController::GetAllEntities(QTreeWidget *widget)
{
    QList<ItemEntity*> items;
    for( int i = 0; i < widget->topLevelItemCount(); ++i )
    {
        auto item = widget->topLevelItem(i);
        ItemEntity* entity = new ItemEntity();
        entity->setCount(item->text(0).toInt());
        entity->setDescription(item->text(1));
        entity->setPrice(item->text(2).replace(",", ".").toDouble());
        entity->setDPH(item->text(3).replace(",", ".").toDouble());
        qDebug() << entity->getPrice() << entity->getDPH();
        entity->setTotalPrice(item->text(4).toDouble());
        items.push_back(entity);
    }
    return items;
}

void ItemInvoiceController::Update()
{
    double sum = ComputeTotalPrice();
    labelTotalPrice->setText(QString::number(sum,'f', 2) + " €");
}

void ItemInvoiceController::Clear(QTreeWidget* widget)
{
    spinBoxCount->setValue(1);
    doubleSpinBoxPrice->setValue(0.0);
    doubleSpinBoxDPH->setValue(0.0);
    lineEditDescription->setText("");
    labelTotalPrice->setText("0 €");
    labelSumTotalPrice->setText("Cena celkom 0 €");
    widget->clear();
}

void ItemInvoiceController::DeleteItem(QTreeWidget* widget, QTreeWidgetItem *item)
{
    delete item;
    double totalSum = ComputeSumTotalPrice(widget);
    labelSumTotalPrice->setText("Cena Celkom: " + QString::number(totalSum,'f', 2) + " €");
}

double ItemInvoiceController::ComputeTotalPrice()
{
    int count = spinBoxCount->value();
    double price = doubleSpinBoxPrice->value();
    double dph = doubleSpinBoxDPH->value() / 100.0;
    return ((double)count * price) + (dph * price);
}

double ItemInvoiceController::ComputeSumTotalPrice(QTreeWidget *widget)
{
    double totalSum = 0;
    for( int i = 0; i < widget->topLevelItemCount(); ++i )
    {
        auto item = widget->topLevelItem(i);
        totalSum += item->text(4).toDouble(); //index of total sum

    }
    return totalSum;
}
