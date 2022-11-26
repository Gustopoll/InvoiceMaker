#ifndef CUSTOMTREEWIDGET_H
#define CUSTOMTREEWIDGET_H

#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QHeaderView>
#include <QString>

class CustomTreeWidget : public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    CustomTreeWidget(QTreeWidget* parent = 0);
    bool operator<(const QTreeWidgetItem &other) const override;

};

#endif // CUSTOMTREEWIDGET_H
