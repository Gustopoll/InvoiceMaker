#ifndef ITEMENTITY_H
#define ITEMENTITY_H

#include <QString>

class ItemEntity
{
public:
    ItemEntity();

    int getId();
    void setId(int value);

    double getPrice();
    void setPrice(double value);

    int getCount();
    void setCount(int value);

    QString getDescription();
    void setDescription(QString value);

private:
    int id;
    double price;
    int count;
    QString description;
};

#endif // ITEMENTITY_H
