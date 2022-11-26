#ifndef SUPPLIERSPAGE_H
#define SUPPLIERSPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <QTreeWidgetItem>
#include <Extensions/customstyle.h>
#include <Pages/PagesNumbers.h>
#include <Repositories/Querry/GetQuerry/getsupplierquerry.h>
#include <Repositories/Querry/DeleteQuerry/deletesupplierquerry.h>
#include "questionpage.h"

namespace Ui {
class SuppliersPage;
}

class SuppliersPage : public QWidget
{
    Q_OBJECT

public:
    explicit SuppliersPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~SuppliersPage();

    void resizeEvent(QResizeEvent *event);
    void Update();
private slots:
    void on_buttonBack_clicked();

    void on_buttonAddSupplier_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::SuppliersPage *ui;
    QStackedWidget *stackedWidget;
};

#endif // SUPPLIERSPAGE_H
