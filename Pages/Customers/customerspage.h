#ifndef CUSTOMERSPAGE_H
#define CUSTOMERSPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <Extensions/customstyle.h>
#include <Repositories/Querry/GetQuerry/getcustomerquerry.h>
#include <QResizeEvent>
#include <QTreeWidgetItem>

namespace Ui {
class CustomersPage;
}

class CustomersPage : public QWidget
{
    Q_OBJECT

public:
    explicit CustomersPage(QWidget *parent = nullptr,QStackedWidget *stackedWidget = nullptr);
    ~CustomersPage();

    void resizeEvent(QResizeEvent *event);
    void Update();
private slots:
    void on_buttonAddCustomer_clicked();

    void on_buttonBack_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::CustomersPage *ui;
    QStackedWidget *stackedWidget;
};

#endif // CUSTOMERSPAGE_H
