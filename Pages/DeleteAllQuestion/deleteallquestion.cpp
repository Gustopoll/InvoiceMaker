#include "deleteallquestion.h"
#include "ui_deleteallquestion.h"
#include <Pages/mainpage.h>
#include <QDebug>
#include <Repositories/dbcontext.h>

DeleteAllQuestion::DeleteAllQuestion(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::DeleteAllQuestion)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;
    CustomStyle cs;
    ui->buttonYes->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonNo->setStyleSheet(cs.RedButtonStyle());
}

DeleteAllQuestion::~DeleteAllQuestion()
{
    delete ui;
}

void DeleteAllQuestion::on_buttonYes_clicked()
{
    DBContext context;
    context.DeleteTables();
    context.CreateTables();

    auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    w->Start();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void DeleteAllQuestion::on_buttonNo_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::SETTINGS);
}
