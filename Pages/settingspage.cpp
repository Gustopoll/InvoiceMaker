#include "settingspage.h"
#include "ui_settingspage.h"

SettingsPage::SettingsPage(QWidget *parent,QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::SettingsPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    CustomStyle cs;
    ui->buttonSave->setStyleSheet(cs.GreenButtonStyle());
    ui->buttonBack->setStyleSheet(cs.RedButtonStyle());


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
    if (settingsController->Build() == false)
        qDebug() << "error";

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
        stackedWidget->setCurrentIndex((int)PageNumber::MAIN_MENU);
    }
    else
    {
        //update entity
        delete e;
    }
}

void SettingsPage::on_buttonBack_clicked()
{
    on_comboBoxV_currentIndexChanged(0);
    on_comboBoxDday_currentIndexChanged(0);
    settingsController->SetFromDB();
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
