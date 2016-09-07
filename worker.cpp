#include <QDebug>

#include "worker.h"

Worker::Worker(QObject *parent) :
    QObject(parent)
{
    m_workerA = new WorkerA(this);

    qDebug() << "Create Worker thread: " << QThread::currentThread();
}

void Worker::doWork()
{  
    qDebug() << "doWork thread: " << QThread::currentThread();

    m_workerA->doWorkA();
}

Worker::~Worker()
{
    //delete m_workerTimer;
}
