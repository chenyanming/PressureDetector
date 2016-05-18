#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QLabel>
#include "console.h"

namespace Ui {
class MainWindow;
}

class console;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QLabel *status;
    Console *console;

private slots:
    void readData();

};

#endif // MAINWINDOW_H
