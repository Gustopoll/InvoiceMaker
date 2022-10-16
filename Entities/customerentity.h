#ifndef CUSTOMERENTITY_H
#define CUSTOMERENTITY_H

#include <QString>
#include "payerdphentity.h"
#include "adressentity.h"

class CustomerEntity
{
public:
    CustomerEntity();


    QString getName();
    void setName(QString value);

    AdressEntity *getAdress();
    void setAdress(AdressEntity *value);

    PayerDPHEntity *getPayer();

    int getId();
    void setId(int value);

    QString getIco();
    void setIco(QString value);

private:
    int id;
    QString name;
    QString ico;

    AdressEntity *adress;
    PayerDPHEntity *payer;

};

#endif // CUSTOMERENTITY_H
