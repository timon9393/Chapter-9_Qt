#include "stopwatch.h"

stopwatch::stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    time = m = s = ms = 0;
    prev_time = prev_m = prev_s = prev_ms = 0;
    lap_count = 0;
    connect(timer, &QTimer::timeout, this, &stopwatch::slot_timer);
}

QString stopwatch::get_time()
{
    if (ms > 9)
    {
        ms = 0;
        s++;
    }
    if (s > 59)
    {
        s = 0;
        m++;
    }

    if (s < 10)
        return QString::number(m) + " : 0" + QString::number(s) + "," + QString::number(ms);
    else
        return QString::number(m) + " : " + QString::number(s) + "," + QString::number(ms);
}

QString stopwatch::lap_time()
{
    prev_time = time - prev_time;
    prev_m = prev_time / 600;
    if ((prev_time - prev_m * 600) <= 0)
        prev_s = 0;
    else
        prev_s = (prev_time - prev_m * 600) / 10;
    prev_ms = (prev_time - prev_m * 600) % 10;
    prev_time = time;
    lap_count++;
    if (prev_s < 10)
        return "Круг " + QString::number(lap_count) + "  |  " + QString::number(prev_m) + " : 0" + QString::number(prev_s) + "," + QString::number(prev_ms);
    else
        return "Круг " + QString::number(lap_count) + "  |  " + QString::number(prev_m) + " : " + QString::number(prev_s) + "," + QString::number(prev_ms);
}

void stopwatch::reset_all()
{
    time = m = s = ms = 0;
    prev_time = prev_m = prev_s = prev_ms = 0;
    lap_count = 0;
}

void stopwatch::start()
{
    timer->start(100);
}

void stopwatch::stop()
{
    timer->stop();
}

void stopwatch::slot_timer()
{
    time++;
    ms++;
    emit timeChanged();
}

