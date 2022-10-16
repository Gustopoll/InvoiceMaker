#include "requireditemscontroller.h"
#include <QDebug>
#include <Extensions/customstyle.h>

RequiredItemsController::RequiredItemsController(QWidget *parent) : QWidget(parent)
{

}

void RequiredItemsController::Add(QLineEdit *l)
{
    listLineEdit.push_back(l);
    QObject::connect(l, &QLineEdit::textChanged, this, &RequiredItemsController::on_QLineEditValueChanged);
}

bool RequiredItemsController::isAnyEmpty()
{
    bool result = false;
    CustomStyle cs;
    for (int i = 0; i < listLineEdit.size(); i++)
    {
        auto item = listLineEdit[i];
        if (item->text().isEmpty())
        {
            item->setStyleSheet(cs.RedBackGround());
            result = true;
        }
    }
    return result;
}

void RequiredItemsController::ClearAll()
{
    for (int i = 0; i < listLineEdit.size(); i++)
    {
        auto item = listLineEdit[i];
        item->setStyleSheet("");
        item->clear();
    }
}

void RequiredItemsController::on_QLineEditValueChanged()
{
    auto item = (QLineEdit*)QObject::sender();
    if (item->text().isEmpty() == false)
        item->setStyleSheet("");
}
