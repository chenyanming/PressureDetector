#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Pressure Detector");
    w.setWindowIcon(QIcon("windowsicon.png"));
    w.show();

    return a.exec();
}
