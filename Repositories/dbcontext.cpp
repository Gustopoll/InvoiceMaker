#include "dbcontext.h"

DBContext::DBContext()
{

}

bool DBContext::Connect()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/db.sqlite");

    return db.open();
}

QString DBContext::CreateTables()
{
    QSqlQuery q;
    //q.exec("DROP TABLE supplier;");
    q.exec("CREATE TABLE IF NOT EXISTS supplier"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "name VARCHAR(255),"
              "facturenumber VARCHAR(255),"
              "idadress INTEGER,"
              "idbankinfo INTEGER,"
              "ico VARCHAR(255),"
              "dic VARCHAR(255),"
              "icdph VARCHAR(255),"
              "isdeleted BOOLEAN);");

    qDebug() << "supplier" << q.lastError().text();

    q.exec("CREATE TABLE IF NOT EXISTS suppliersaved"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "name VARCHAR(255),"
              "facturenumber VARCHAR(255),"
              "idadress INTEGER,"
              "idbankinfo INTEGER,"
              "ico VARCHAR(255),"
              "dic VARCHAR(255),"
              "icdph VARCHAR(255),"
              "isdeleted BOOLEAN);");

    qDebug() << "suppliersaved" << q.lastError().text();

    //q.exec("DROP TABLE adress;");
    q.exec("CREATE TABLE IF NOT EXISTS adress"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
               "street VARCHAR(255),"
               "streetnumber VARCHAR(255),"
               "psc VARCHAR(10),"
               "city VARCHAR(255),"
               "state VARCHAR(255));");

    qDebug() << "adress" << q.lastError().text();

    //q.exec("DROP TABLE bankinfo;");
    q.exec("CREATE TABLE IF NOT EXISTS bankinfo"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
               "IBAN VARCHAR(255),"
               "SWIFT VARCHAR(255),"
               "VS VARCHAR(10));");

    qDebug() << "bankinfo" << q.lastError().text();

    q.exec("CREATE TABLE IF NOT EXISTS customer"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "name VARCHAR(255),"
              "idadress INTEGER,"
              "ico VARCHAR(255),"
              "dic VARCHAR(255),"
              "icdph VARCHAR(255),"
              "isdeleted BOOLEAN);");

    qDebug() << "customer" << q.lastError().text();

    q.exec("CREATE TABLE IF NOT EXISTS customersaved"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "name VARCHAR(255),"
              "idadress INTEGER,"
              "ico VARCHAR(255),"
              "dic VARCHAR(255),"
              "icdph VARCHAR(255),"
              "isdeleted BOOLEAN);");

    qDebug() << "customersaved" << q.lastError().text();

    //q.exec("DROP TABLE settings;");
    q.exec("CREATE TABLE IF NOT EXISTS settings"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "indexV INTEGER,"
              "indexD INTEGER,"
              "indexD2 INTEGER,"
              "indexS INTEGER,"
              "dateV date,"
              "dateD date,"
              "dateS date,"
              "DPH REAL);");

    qDebug() << "settings" << q.lastError().text();

    q.exec("CREATE TABLE IF NOT EXISTS invoice"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "idSupplier INTEGER,"
              "idCustomer INTEGER,"
              "idSupplierSaved INTEGER,"
              "idCustomerSaved INTEGER,"
              "dateV date,"
              "dateD date,"
              "dateS date,"
              "payment INTEGER,"
              "invoicetype INTEGER,"
              "factureNumber INTEGER);");

    qDebug() << "invoice" << q.lastError().text();

    //q.exec("DROP TABLE item;");
    q.exec("CREATE TABLE IF NOT EXISTS item"
              "(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
              "idInvoice INTEGER,"
              "price REAL,"
              "totalPrice REAL,"
              "count REAL,"
              "dph REAL,"
              "description VARCHAR(512));");

    qDebug() << "item" << q.lastError().text();

    return q.lastError().text();
}
