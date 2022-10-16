#ifndef SETTINGSENTITY_H
#define SETTINGSENTITY_H

#include <QString>
#include <QDate>

class SettingsEntity
{
public:
    SettingsEntity();

    int getId();

    int getIndexV();
    void setIndexV(int value);

    int getIndexD();
    void setIndexD(int value);

    int getIndexD2();
    void setIndexD2(int value);

    int getIndexS();
    void setIndexS(int value);

    QDate getDateV();
    void setDateV(QDate value);

    QDate getDateD();
    void setDateD(QDate value);

    QDate getDateS();
    void setDateS(QDate value);

    double getDPH();
    void setDPH(double value);

private:
    int id;
    int indexV;
    int indexD;
    int indexD2;
    int indexS;

    QDate dateV;
    QDate dateD;
    QDate dateS;
    double DPH;
};

#endif // SETTINGSENTITY_H
