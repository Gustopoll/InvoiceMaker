#ifndef REQUIREDITEMSCONTROLLER_H
#define REQUIREDITEMSCONTROLLER_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

class RequiredItemsController : public QWidget
{
public:
    RequiredItemsController(QWidget *parent = nullptr);

    void Add(QLineEdit* l);

    bool isAnyEmpty();
    void ClearAll();

private:
    QList<QLineEdit*> listLineEdit;

private slots:
    void on_QLineEditValueChanged();
};

#endif // REQUIREDITEMSCONTROLLER_H
