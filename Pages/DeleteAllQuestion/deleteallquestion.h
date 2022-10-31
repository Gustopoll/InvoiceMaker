#ifndef DELETEALLQUESTION_H
#define DELETEALLQUESTION_H

#include <QStackedWidget>
#include <QWidget>
#include <Pages/PagesNumbers.h>

namespace Ui {
class DeleteAllQuestion;
}

class DeleteAllQuestion : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteAllQuestion(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~DeleteAllQuestion();

private slots:
    void on_buttonYes_clicked();

    void on_buttonNo_clicked();

private:
    Ui::DeleteAllQuestion *ui;
    QStackedWidget *stackedWidget;
};

#endif // DELETEALLQUESTION_H
