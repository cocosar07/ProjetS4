#include "connectionthread.h"

ConnectionThread::ConnectionThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false), test(nullptr)
{
}
ConnectionThread::~ConnectionThread()
{
    mutex.lock();
    quit = true;
    mutex.unlock();
    wait();
}

void ConnectionThread::startSlave(const QString &portName, int waitTimeout, Test *test, bool stepByStep)
{
    if (!isRunning())
    {
        this->portName = portName;
        this->waitTimeout = waitTimeout;
        this->test = test;
        this->stepByStep = stepByStep;
        start();
    }
}

void ConnectionThread::run()
{
    if(stepByStep)
        sendNextCommand = false;
    else
        sendNextCommand = true;

    QSerialPort serial;
    serial.setPortName(portName);
    if (!serial.open(QIODevice::ReadWrite))
    {
        emit error(tr("Can't open %1, error code %2").arg(portName).arg(serial.error()));
        return;
    }

    while (!quit) {
        if(stepByStep)
        {
            while(!sendNextCommand);
            mutex.lock();
            sendNextCommand = false;
            mutex.unlock();
        }
        // Envoi microcommande
        serial.write(test->recupProchaineMicrocommande().c_str());
        if(!serial.waitForBytesWritten(waitTimeout))
        {
            emit timeout(tr("Wait write microcommande timeout %1").arg(QTime::currentTime().toString()));
        }
        //Accusé de reception
        if(serial.waitForReadyRead(waitTimeout))
        {
            QByteArray received = serial.readAll();
            if(received.toStdString().compare(COMMANDE_RECEIVED) != 0)
            {
                emit error("Not wanted response");
            }
        }
        else
        {
            emit timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
        }
        //Pret a recevoir prochaine commande
        if(serial.waitForReadyRead(waitTimeout))
        {
            QByteArray received = serial.readAll();
            if(received.toStdString().compare(READY_FOR_NEXT_COMMAND) != 0)
            {
                emit error("Not wanted response");
            }
        }
        else
        {
            emit timeout(tr("Wait read response timeout %1").arg(QTime::currentTime().toString()));
        }
    }
}

void ConnectionThread::sendCommand()
{
    mutex.lock();
    sendNextCommand = true;
    mutex.unlock();
}
