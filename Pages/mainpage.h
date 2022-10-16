#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTreeWidgetItem>
#include "PagesNumbers.h"
#include "../Extensions/customstyle.h"
#include "../Entities/invoiceentity.h"
#include "showinvoicepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~MainPage();

    void Update();
private slots:
    void on_buttonNewInvoice_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;

    void resizeEvent(QResizeEvent *event);

};
#endif // MAINWINDOW_H
