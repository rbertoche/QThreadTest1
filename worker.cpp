#include <QDebug>

#include "worker.h"

WorkerB::WorkerB(QObject *parent) :
    QObject(parent)
{
    m_workerA = new WorkerA(this);

    qDebug() << "Create WorkerB thread: " << QThread::currentThread();
}

void WorkerB::doWork()
{  
    qDebug() << "DoWorkB thread: " << QThread::currentThread();

    m_workerA->doWorkA();
}

WorkerB::~WorkerB()
{
    //delete m_workerTimer;
}
