#ifndef SUPPLIERENTITY_H
#define SUPPLIERENTITY_H

#include <QString>
#include "payerdphentity.h"
#include "adressentity.h"
#include "bankinfoentity.h"
#include <Entities/InvoiceType.h>

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

    int getFactureNumberClassic();
    void setFactureNumberClassic(int value);

    int getId();
    void setId(int value);

    QString getIco();
    void setIco(QString value);

    BankInfoEntity *getBankinfo();
    void setBankinfo(BankInfoEntity *value);

    int getFactureNumberCanceled();
    void setFactureNumberCanceled(int value);

    int getFactureNumberDeposit();
    void setFactureNumberDeposit(int value);

    int getFactureNumberOrder();
    void setFactureNumberOrder(int value);

    int getFactureNumberPriceoffer();
    void setFactureNumberPriceoffer(int value);

    int getFactureNumberByInvoiceType(InvoiceType type);
    void setFactureNumberByInvoiceType(InvoiceType type, int value);
private:
    int id;
    QString name;
    int factureNumberClassic;
    int factureNumberCanceled;
    int factureNumberDeposit;
    int factureNumberOrder;
    int factureNumberPriceoffer;
    QString ico;

    PayerDPHEntity *payer;
    AdressEntity *adress;
    BankInfoEntity *bankinfo;
};



#endif // SUPPLIERENTITY_H
