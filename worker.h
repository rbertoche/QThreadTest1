#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QNetworkAccessManager>

class WorkerA: public QObject
{
    Q_OBJECT
public:
    inline explicit WorkerA(QObject *parent = 0)
    {
        m_net1 = new QNetworkAccessManager(this);

        qDebug() << "Create WorkerA thread: " << QThread::currentThread();
    }

    inline void doWorkA()
    {
        m_net2 = new QNetworkAccessManager(this);

        qDebug() << "DoWorkA thread: " << QThread::currentThread();

        qDebug() << "Net1 Parent: " << m_net1->parent();
        qDebug() << "Net2 Parent: " << m_net2->parent();;
    }

    inline ~WorkerA()
    {
        delete m_net1;
        delete m_net2;
    }


private:
    QNetworkAccessManager *m_net1;
    QNetworkAccessManager *m_net2;
};

class WorkerB : public QObject
{
    Q_OBJECT
public:
    explicit WorkerB(QObject *parent = 0);
    ~WorkerB();

signals:

public slots:
    void doWork();

private:
    WorkerA *m_workerA;

};

#endif // WORKER_H
