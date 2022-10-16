#ifndef SUPPLIERENTITY_H
#define SUPPLIERENTITY_H

#include <QString>
#include "payerdphentity.h"
#include "adressentity.h"
#include "bankinfoentity.h"

class SupplierEntity
{
public:
    SupplierEntity();

    bool isPayer();
    bool isAdressNull();

    PayerDPHEntity *getPayer();
    AdressEntity *getAdress();
    void setAdress(AdressEntity *value);

    QString getName();
    void setName(QString value);

    int getFactureNumber();
    void setFactureNumber(int value);

    int getId();
    void setId(int value);

    QString getIco();
    void setIco(QString value);

    BankInfoEntity *getBankinfo();
    void setBankinfo(BankInfoEntity *value);

private:
    int id;
    QString name;
    int factureNumber;
    QString ico;

    PayerDPHEntity *payer;
    AdressEntity *adress;
    BankInfoEntity *bankinfo;
};

#endif // SUPPLIERENTITY_H
