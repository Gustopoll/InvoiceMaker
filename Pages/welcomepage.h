#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = nullptr);
    ~WelcomePage();

private slots:


    void on_actionQuit_triggered();

    void on_actiondSettings_triggered();

    void on_actionSuppliers_triggered();

    void on_actionOdberatelia_triggered();

private:
    Ui::WelcomePage *ui;
    void LoadAllPages();

    bool isLoaded = false;
    QTimer *timer;
};

#endif // WELCOMEPAGE_H
