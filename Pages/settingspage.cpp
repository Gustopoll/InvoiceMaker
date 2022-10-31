#include "mainpage.h"
#include "settingspage.h"
#include "ui_settingspage.h"
#include <QApplication>
#include <QStyleFactory>

SettingsPage::SettingsPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonSave->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonBack->setStyleSheet(cs.RedButtonStyle());
    ui->buttonDeleteAll->setStyleSheet(cs.RedButtonStyle());

    settingsController = new SettingsController();
    settingsController->setComboBoxV(ui->comboBoxV);
    settingsController->setComboBoxS(ui->comboBoxS);
    settingsController->setComboBoxDday(ui->comboBoxDday);
    settingsController->setComboBoxDmonth(ui->comboBoxDmonth);
    settingsController->setDateEditD(ui->dateEditD);
    settingsController->setDateEditV(ui->dateEditV);
    settingsController->setDateEditS(ui->dateEditS);
    settingsController->setDPH(ui->doubleSpinBoxDPH);
    settingsController->setLabelPart1(ui->labelPart1);
    settingsController->setLabelPart2(ui->labelPart2);
    settingsController->setComboBoxStyle(ui->comboBoxStyle);
    if (settingsController->Build() == false)
        qDebug() << "error";

    auto keys = QStyleFactory::keys();
    int index = 0;
    for (int i = 0; i < keys.size(); i++)
    {
        ui->comboBoxStyle->addItem(keys[i]);
        if (keys[i] == "Fusion")
            index = i;
    }
    ui->comboBoxStyle->setCurrentIndex(index);
    settingsController->SetFromDB();
}

SettingsPage::~SettingsPage()
{
    delete ui;
}

void SettingsPage::on_buttonSave_clicked()
{
    GetSettingsQuerry q;
    auto e = q.Get();
    if (e == nullptr)
    {
        auto entity = settingsController->CreateEnity();
        auto q = AddSettingsQuerry();
        q.Add(entity);
        qDebug() << q.GetLastError();
        auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
        w->Start();
        stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
    }
    else
    {
        UpdateSettingsQuerry q;
        auto entity = settingsController->CreateEnity();
        q.Update(entity);
        qDebug() << q.GetLastError();
        delete entity;
        delete e;
        auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
        w->Start();
        stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
    }
}

void SettingsPage::on_buttonBack_clicked()
{
    on_comboBoxV_currentIndexChanged(0);
    on_comboBoxDday_currentIndexChanged(0);
    settingsController->SetFromDB();
    auto w = (MainPage*)stackedWidget->widget((int)PageNumber::MAIN_MENU);
    w->Start();
    stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
}

void SettingsPage::on_comboBoxDday_currentIndexChanged(int index)
{
    settingsController->comboBoxDdayUpate(index);
}

void SettingsPage::on_comboBoxDmonth_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    settingsController->Update();
}

void SettingsPage::on_dateEditV_dateChanged(const QDate &date)
{
    Q_UNUSED(date);
    settingsController->Update();
}

void SettingsPage::on_comboBoxS_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    settingsController->Update();
}

void SettingsPage::on_comboBoxV_currentIndexChanged(int index)
{
    settingsController->comboBoxVUpdate(index);
}


void SettingsPage::on_comboBoxStyle_currentTextChanged(const QString &arg1)
{
    QApplication::setStyle(arg1);
}

void SettingsPage::on_buttonDeleteAll_clicked()
{
    stackedWidget->setCurrentIndex((int)PageNumber::QUESTION_DELETE_ALL);
}
