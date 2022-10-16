#ifndef QUESTIONDELETECUSTOMERPAGE_H
#define QUESTIONDELETECUSTOMERPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <Pages/PagesNumbers.h>
#include <Repositories/Querry/DeleteQuerry/deletecustomerquerry.h>
#include <Repositories/Querry/UpdateQuerry/updatecustomerquerry.h>

namespace Ui {
class QuestionDeleteCustomerPage;
}

class QuestionDeleteCustomerPage : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionDeleteCustomerPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~QuestionDeleteCustomerPage();

    void SetName(QString name);
    void SetID(int id);
    void ResetAll();

private slots:
    void on_buttonYes_clicked();

    void on_buttonNo_clicked();

private:
    Ui::QuestionDeleteCustomerPage *ui;
    QStackedWidget *stackedWidget;
    int idCustomer;
};

#endif // QUESTIONDELETECUSTOMERPAGE_H
