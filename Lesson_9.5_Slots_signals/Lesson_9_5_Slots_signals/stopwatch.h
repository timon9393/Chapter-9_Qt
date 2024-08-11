#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>


class stopwatch : public QObject
{
    Q_OBJECT
    QTimer* timer;
    int time, m, s, ms;
    int prev_time, prev_m, prev_s, prev_ms;
    int lap_count;
public:
    explicit stopwatch(QObject *parent = nullptr);
    QString get_time();
    QString lap_time();
    void reset_all();
    void start();
    void stop();

public slots:
    void slot_timer();

signals:
    void timeChanged();

};

#endif // STOPWATCH_H
