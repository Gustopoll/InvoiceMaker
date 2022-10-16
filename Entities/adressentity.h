#ifndef ADRESSENTITY_H
#define ADRESSENTITY_H

#include <QString>

class AdressEntity
{
public:
    AdressEntity();

    QString getStreet();
    void setStreet(QString value);

    QString getStreetNumber();
    void setStreetNumber(QString value);

    QString getPsc();
    void setPsc(QString value);

    QString getCity();
    void setCity(QString value);

    QString getState();
    void setState(QString value);

    QString getStreetWithNumber();
    QString getPSCWithCity();

    int getId();
    void setId(int value);

private:
    int id;
    QString street;
    QString streetNumber;
    QString psc;
    QString city;
    QString state;
};

#endif // ADRESSENTITY_H
