#ifndef QUESTIONPAGE_H
#define QUESTIONPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include "supplierspage.h"
#include <Extensions/customstyle.h>
#include <Repositories/Querry/DeleteQuerry/deletesupplierquerry.h>
#include <Repositories/Querry/UpdateQuerry/updatesupplierquerry.h>

class SuppliersPage;

namespace Ui {
class QuestionPage;
}

class QuestionPage : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~QuestionPage();

    void SetID(int id);
    void SetName(QString name);
private slots:
    void on_buttonYes_clicked();

    void on_buttonNo_clicked();

private:
    Ui::QuestionPage *ui;
    QStackedWidget *stackedWidget;
    int id;
};

#endif // QUESTIONPAGE_H
