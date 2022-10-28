#ifndef QUESTIONDELETEINVOICEPAGE_H
#define QUESTIONDELETEINVOICEPAGE_H

#include <QStackedWidget>
#include <QWidget>
#include <Pages/PagesNumbers.h>

namespace Ui {
class QuestionDeleteInvoicePage;
}

class QuestionDeleteInvoicePage : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionDeleteInvoicePage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~QuestionDeleteInvoicePage();

    void SetName(QString name);
    void SetID(int id);
    void ResetAll();
private slots:
    void on_buttonYes_clicked();

    void on_buttonNo_clicked();

private:
    Ui::QuestionDeleteInvoicePage *ui;
    QStackedWidget *stackedWidget;
    int idInvoice;
};

#endif // QUESTIONDELETEINVOICEPAGE_H
