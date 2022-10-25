#ifndef TEMPORARYMESSAGECONTROLLER_H
#define TEMPORARYMESSAGECONTROLLER_H

#include <QLabel>
#include <QTimer>
#include <QObject>
#include <QWidget>

class TemporaryMessageController : public QWidget
{
public:
    TemporaryMessageController(QWidget *parent = nullptr, int maxRound = 0);

    void StartVisibleLabel(QLabel* l);
private:
    QTimer* timer;
    QLabel* labelTemporary;

    int round;
    int maxRound;
    void UpdateTimer();
};

#endif // TEMPORARYMESSAGECONTROLLER_H
