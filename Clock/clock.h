#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QTimer>

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QWidget *parent = 0);
    ~Clock();
    void paintEvent(QPaintEvent *eventPtr);

private:
    QTimer m_timer;
};

#endif // CLOCK_H
