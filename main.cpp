#include "Pages/welcomepage.h"
#include <QDebug>
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug() << a.styleSheet();
    a.setStyle(QStyleFactory::create("Fusion")); //Fusion
    WelcomePage w;
    w.show();
    return a.exec();
}
