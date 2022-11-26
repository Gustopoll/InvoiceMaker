#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTreeWidgetItem>
#include <Controller/temporarymessagecontroller.h>
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

    void Start();
    void Update();
    void SaveInvoice(InvoiceEntity* entity);

private slots:
    void on_buttonNewInvoice_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_spinBoxYear_valueChanged(int arg1);
    void on_comboBoxMonth_currentIndexChanged(int index);
    void on_comboBoxSupplier_activated(int index);

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QTimer *timerMSG;
    TemporaryMessageController *temporaryMessageController;
    void resizeEvent(QResizeEvent *event);
    void AddInvoiceEntity(InvoiceEntity* entity, int number);

};
#endif // MAINWINDOW_H
