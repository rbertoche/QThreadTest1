#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>

#include "worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void doWorkSignal();

private:
    Ui::MainWindow *ui;

    QThread m_thread;

    WorkerB m_worker;
};

#endif // MAINWINDOW_H
