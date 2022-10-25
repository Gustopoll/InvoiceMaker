#include "customstyle.h"

#include <QCoreApplication>
#include <QFile>

CustomStyle::CustomStyle()
{

}


QString CustomStyle::ClassicButtonStyle()
{
   QString string = " \
           QPushButton \
           {\
               background-color: #4891b4; \
               color: #fff; \
               min-width: 80px; \
               border-radius: 4px; \
               padding: 5px; \
           } \
           QPushButton::flat \
           { \
               background-color: transparent; \
               border: none; \
               color: #000; \
           } \
           QPushButton::disabled \
           { \
               background-color: #606060; \
               color: #959595; \
               border-color: #051a39; \
           } \
           QPushButton::hover \
           { \
               background-color: #54aad3; \
               border: 1px solid #46a2da; \
           } \
           QPushButton::pressed \
           { \
               background-color: #2385b4; \
               border: 1px solid #46a2da; \
           } \
           QPushButton::checked \
           { \
               background-color: #bd5355; \
               border: 1px solid #bd5355; \
           } ";
          return string;
}

QString CustomStyle::RedButtonStyle()
{
   QString string = " \
           QPushButton \
           {\
               background-color: #FF2D00; \
               color: #fff; \
               min-width: 80px; \
               border-radius: 4px; \
               padding: 5px; \
           } \
           QPushButton::flat \
           { \
               background-color: transparent; \
               border: none; \
               color: #000; \
           } \
           QPushButton::disabled \
           { \
               background-color: #606060; \
               color: #959595; \
               border-color: #051a39; \
           } \
           QPushButton::hover \
           { \
               background-color: #DE2801; \
               border: 1px solid #FFFFFF; \
           } \
           QPushButton::pressed \
           { \
               background-color: #FF6645; \
               border: 1px solid #FFFFFF; \
           } \
           QPushButton::checked \
           { \
               background-color: #bd5355; \
               border: 1px solid #bd5355; \
           } ";
           return string;
}

QString CustomStyle::GreenButtonStyle()
{
    QString string = " \
            QPushButton \
            {\
                background-color: #3EC613; \
                color: #fff; \
                min-width: 80px; \
                border-radius: 4px; \
                padding: 5px; \
            } \
            QPushButton::flat \
            { \
                background-color: transparent; \
                border: none; \
                color: #000; \
            } \
            QPushButton::disabled \
            { \
                background-color: #606060; \
                color: #959595; \
                border-color: #051a39; \
            } \
            QPushButton::hover \
            { \
                background-color: #2BB100; \
                border: 1px solid #FFFFFF; \
            } \
            QPushButton::pressed \
            { \
                background-color: #81F95B; \
                border: 1px solid #FFFFFF; \
            } \
            QPushButton::checked \
            { \
                background-color: #bd5355; \
                border: 1px solid #bd5355; \
            } ";
            return string;
}

QString CustomStyle::RedBackGround()
{
    return "background-color: rgb(255, 0, 0);";
}

QString CustomStyle::DeleteButtonStyle()
{
    return "QPushButton \
        {\
         border-image: url(:/icon/Data/eraseNoBorder.png);\
        } \
    QPushButton::hover \
    { \
       border-image: url(:/icon/Data/erase.png);\
    } ";
}
QString CustomStyle::DateStyle()
{
    QString string = " \
    QDateEdit \
    { \
        background-color: white; \
        border-style: solid; \
        border-width: 4px; \
        border-color: white; \
        border-radius: 10px; \
        spacing: 5px; \
    } \
    QDateEdit::drop-down { \
        image: url(:/new/myapp/cbarrowdn.png); \
        width:50px; \
        height:15px; \
        subcontrol-position: right top; \
        subcontrol-origin:margin; \
        background-color: white; \
        border-style: solid; \
        border-width: 4px; \
        border-color: rgb(100,100,100); \
       spacing: 5px; \
    } ";
            return string;
}

QString CustomStyle::ComboBoxStyle()
{
    QFile f(QCoreApplication::applicationDirPath() + "/style.qss");
    f.open(QIODevice::ReadOnly);
    return f.readAll();
    QString string = " \
    QComboBox \
    { \
        background-color: #D3D3D3; \
        padding-left: 10px; \
        color: #000000; \
        height: 20px; \
        border-radius: 10px; \
    } \
    QComboBox::disabled \
    { \
        background-color: #D3D3D3; \
        color: #656565; \
        border-color: #051a39; \
    } \
    QComboBox:on \
    { \
        background-color: #D3D3D3; \
        color: #fff; \
    } \
    QComboBox QAbstractItemView \
    { \
        background-color: #D3D3D3; \
        color: #fff; \
        selection-background-color: #002b2b; \
        selection-color: #fff; \
        outline: 0; \
    } \
    QComboBox::drop-down \
    { \
        background-color: #4a5157; \
        subcontrol-origin: padding; \
        subcontrol-position: top right; \
        border-radius: 4px; \
        width: 15px; \
    } \
    QComboBox::down-arrow \
    { \
        width: 8px; \
        height: 8px; \
    }";
    return string;
}
