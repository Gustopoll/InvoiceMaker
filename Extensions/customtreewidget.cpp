#include "customtreewidget.h"

CustomTreeWidget::CustomTreeWidget(QTreeWidget *parent) : QTreeWidgetItem(parent)
{

}

bool CustomTreeWidget::operator<(const QTreeWidgetItem &other) const
{
    const int column = treeWidget()->sortColumn();

    if (column == 1) //No
    {
        const int role = Qt::DisplayRole;
        return( data( column, role ).toInt() < other.data( column, role ).toInt() );
    }

    if (column == 4) //Price
    {
        const int role = Qt::DisplayRole;
        return( data( column, role ).toDouble() < other.data( column, role ).toDouble() );
    }
    else //Other - comapre strings
    {
       QString val = text(column);
       QString otherVal = other.text(column);
       return val < otherVal;
    }

}
