#include "temporarymessagecontroller.h"
#include <QDebug>

TemporaryMessageController::TemporaryMessageController(QWidget *parent, int maxRound)
{
    this->maxRound = maxRound;
    labelTemporary = nullptr;
    round = 0;
    QTimer *timer = new QTimer(this);
    this->timer = timer;
    connect(timer, &QTimer::timeout, this, &TemporaryMessageController::UpdateTimer);
}

void TemporaryMessageController::StartVisibleLabel(QLabel *l)
{
    labelTemporary = l;
    labelTemporary->setVisible(true);
    timer->start(100);
}

void TemporaryMessageController::UpdateTimer()
{
    round++;
    qDebug() << round;
    if (round >= maxRound)
    {
        if (labelTemporary != nullptr)
            labelTemporary->setVisible(false);
        timer->stop();
    }
}
