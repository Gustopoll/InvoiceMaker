QT       += core gui sql
QT       += printsupport
#QT += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/customercontroller.cpp \
    Controller/iteminvoicecontroller.cpp \
    Controller/requireditemscontroller.cpp \
    Controller/settingscontroller.cpp \
    Controller/suppliercontroller.cpp \
    Entities/adressentity.cpp \
    Entities/bankinfoentity.cpp \
    Entities/customerentity.cpp \
    Entities/invoiceentity.cpp \
    Entities/itementity.cpp \
    Entities/payerdphentity.cpp \
    Entities/settingsentity.cpp \
    Entities/supplierentity.cpp \
    Extensions/customgraphicsview.cpp \
    Extensions/customstyle.cpp \
    Extensions/datehelper.cpp \
    Pages/Customers/addcustomerpage.cpp \
    Pages/Customers/customerspage.cpp \
    Pages/Customers/questiondeletecustomerpage.cpp \
    Pages/NewInvoice/invoicepage.cpp \
    Pages/Suppliers/addsupplierpage.cpp \
    Pages/Suppliers/questionpage.cpp \
    Pages/Suppliers/supplierspage.cpp \
    Pages/loadingpage.cpp \
    Pages/mainpage.cpp \
    Pages/settingspage.cpp \
    Pages/showinvoicepage.cpp \
    Pages/welcomepage.cpp \
    Repositories/Querry/AddQuerry/addcustomerquerry.cpp \
    Repositories/Querry/AddQuerry/addcustomersavedquerry.cpp \
    Repositories/Querry/AddQuerry/addquerry.cpp \
    Repositories/Querry/AddQuerry/addsettingsquerry.cpp \
    Repositories/Querry/AddQuerry/addsupplierquerry.cpp \
    Repositories/Querry/AddQuerry/addsuppliersavedquerry.cpp \
    Repositories/Querry/DeleteQuerry/deletecustomerquerry.cpp \
    Repositories/Querry/DeleteQuerry/deletecustomersavedquerry.cpp \
    Repositories/Querry/DeleteQuerry/deletequerry.cpp \
    Repositories/Querry/DeleteQuerry/deletesupplierquerry.cpp \
    Repositories/Querry/DeleteQuerry/deletesuppliersavedquerry.cpp \
    Repositories/Querry/GetQuerry/getcustomerquerry.cpp \
    Repositories/Querry/GetQuerry/getcustomersavedquerry.cpp \
    Repositories/Querry/GetQuerry/getquerry.cpp \
    Repositories/Querry/GetQuerry/getsettingsquerry.cpp \
    Repositories/Querry/GetQuerry/getsupplierquerry.cpp \
    Repositories/Querry/GetQuerry/getsuppliersavedquerry.cpp \
    Repositories/Querry/UpdateQuerry/updatecustomerquerry.cpp \
    Repositories/Querry/UpdateQuerry/updatequerry.cpp \
    Repositories/Querry/UpdateQuerry/updatesupplierquerry.cpp \
    Repositories/Querry/basequerry.cpp \
    Repositories/dbcontext.cpp \
    main.cpp \
    pdfinvoicegenerator.cpp

HEADERS += \
    Controller/customercontroller.h \
    Controller/iteminvoicecontroller.h \
    Controller/requireditemscontroller.h \
    Controller/settingscontroller.h \
    Controller/suppliercontroller.h \
    Entities/InvoiceType.h \
    Entities/PaymentMethod.h \
    Entities/adressentity.h \
    Entities/bankinfoentity.h \
    Entities/customerentity.h \
    Entities/invoiceentity.h \
    Entities/itementity.h \
    Entities/payerdphentity.h \
    Entities/settingsentity.h \
    Entities/supplierentity.h \
    Extensions/customgraphicsview.h \
    Extensions/customstyle.h \
    Extensions/datehelper.h \
    Pages/Customers/addcustomerpage.h \
    Pages/Customers/customerspage.h \
    Pages/Customers/questiondeletecustomerpage.h \
    Pages/NewInvoice/invoicepage.h \
    Pages/PagesNumbers.h \
    Pages/Suppliers/addsupplierpage.h \
    Pages/Suppliers/questionpage.h \
    Pages/Suppliers/supplierspage.h \
    Pages/loadingpage.h \
    Pages/mainpage.h \
    Pages/settingspage.h \
    Pages/showinvoicepage.h \
    Pages/welcomepage.h \
    Repositories/Querry/AddQuerry/addcustomerquerry.h \
    Repositories/Querry/AddQuerry/addcustomersavedquerry.h \
    Repositories/Querry/AddQuerry/addquerry.h \
    Repositories/Querry/AddQuerry/addsettingsquerry.h \
    Repositories/Querry/AddQuerry/addsupplierquerry.h \
    Repositories/Querry/AddQuerry/addsuppliersavedquerry.h \
    Repositories/Querry/DeleteQuerry/deletecustomerquerry.h \
    Repositories/Querry/DeleteQuerry/deletecustomersavedquerry.h \
    Repositories/Querry/DeleteQuerry/deletequerry.h \
    Repositories/Querry/DeleteQuerry/deletesupplierquerry.h \
    Repositories/Querry/DeleteQuerry/deletesuppliersavedquerry.h \
    Repositories/Querry/GetQuerry/getcustomerquerry.h \
    Repositories/Querry/GetQuerry/getcustomersavedquerry.h \
    Repositories/Querry/GetQuerry/getquerry.h \
    Repositories/Querry/GetQuerry/getsettingsquerry.h \
    Repositories/Querry/GetQuerry/getsupplierquerry.h \
    Repositories/Querry/GetQuerry/getsuppliersavedquerry.h \
    Repositories/Querry/UpdateQuerry/updatecustomerquerry.h \
    Repositories/Querry/UpdateQuerry/updatequerry.h \
    Repositories/Querry/UpdateQuerry/updatesupplierquerry.h \
    Repositories/Querry/basequerry.h \
    Repositories/dbcontext.h \
    pdfinvoicegenerator.h

FORMS += \
    Pages/Customers/addcustomerpage.ui \
    Pages/Customers/customerspage.ui \
    Pages/Customers/questiondeletecustomerpage.ui \
    Pages/NewInvoice/invoicepage.ui \
    Pages/Suppliers/addsupplierpage.ui \
    Pages/Suppliers/questionpage.ui \
    Pages/Suppliers/supplierspage.ui \
    Pages/loadingpage.ui \
    Pages/mainpage.ui \
    Pages/settingspage.ui \
    Pages/showinvoicepage.ui \
    Pages/welcomepage.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icons.qrc
