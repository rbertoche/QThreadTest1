#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_worker.moveToThread(&m_thread);

    connect(this, SIGNAL(doWorkSignal()),
            &m_worker, SLOT(doWork()));

    m_thread.start();

    emit doWorkSignal();

    qDebug() << "MainWin thread: " << QThread::currentThread();
}

MainWindow::~MainWindow()
{
    delete ui;

    m_thread.exit();
    m_thread.wait();
}
