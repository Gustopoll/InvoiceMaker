#ifndef BANKINFOENTITY_H
#define BANKINFOENTITY_H

#include <QString>

class BankInfoEntity
{
public:
    BankInfoEntity();

    QString getIBAN();
    void setIBAN(QString value);

    QString getSWIFT();
    void setSWIFT(QString value);

    QString getVS();
    void setVS(QString value);

    int getId();
    void setId(int value);

    bool isValid();
private:
    int Id;
    QString IBAN;
    QString SWIFT;
    QString VS;
};

#endif // BANKINFOENTITY_H
