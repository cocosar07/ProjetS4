#ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QThread>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QTime>
#include <QMutex>
#include "Test.hpp"

#define COMMANDE_RECEIVED "r"
#define READY_FOR_NEXT_COMMAND "n"

class ConnectionThread : public QThread
{
    Q_OBJECT

public:
    ConnectionThread(QObject *parent = 0);
    ~ConnectionThread();

    void startSlave(const QString &portName, int waitTimeout, Test *test, bool stepByStep);
    void run();

public slots:
    void sendCommand();

signals:
    void result(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);
    void finished();

private:
    QString portName;
    QMutex mutex;
    int waitTimeout;
    bool quit;
    bool stepByStep;
    bool sendNextCommand;
    Test *test;
};

#endif // CONNECTIONTHREAD_H
