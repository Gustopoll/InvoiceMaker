#ifndef LOADINGPAGE_H
#define LOADINGPAGE_H

#include <QWidget>
#include <QStackedWidget>
#include <QMovie>

namespace Ui {
class LoadingPage;
}

class LoadingPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingPage(QWidget *parent = nullptr, QStackedWidget *stackedWidget = nullptr);
    ~LoadingPage();

private:
    Ui::LoadingPage *ui;
    QStackedWidget *stackedWidget;
};

#endif // LOADINGPAGE_H
