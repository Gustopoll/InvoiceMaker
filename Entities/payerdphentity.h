#ifndef PAYERDPHENTITY_H
#define PAYERDPHENTITY_H

#include <QString>

class PayerDPHEntity
{
public:
    PayerDPHEntity();

    QString getDic();
    void setDic(QString value);

    QString getIcdph();
    void setIcdph(QString value);

private:
    QString dic;
    QString icdph;
};

#endif // PAYERDPHENTITY_H
