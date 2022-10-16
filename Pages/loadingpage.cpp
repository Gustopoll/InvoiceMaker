#include "loadingpage.h"
#include "ui_loadingpage.h"

LoadingPage::LoadingPage(QWidget *parent, QStackedWidget *stackedWidget) :
    QWidget(parent),
    ui(new Ui::LoadingPage)
{
    ui->setupUi(this);
    this->stackedWidget = stackedWidget;

    QMovie *movie = new QMovie(":/icon/Data/loading.gif");
    QSize size;
    size.setWidth(500);
    size.setHeight(500);
    movie->setScaledSize(size);
    ui->labelLoading->setMovie(movie);
    movie->start();
}

LoadingPage::~LoadingPage()
{
    delete ui;
}
