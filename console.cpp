#include "console.h"
#include <QScrollBar>
#include <QDebug>

double serialRev0 = 0;
double serialRev1 = 0;
double serialRev2 = 0;
double serialRev3 = 0;

Console::Console()
{
	// Create a log file
	consoleLog = new Log(this);
}

void Console::serialReceived(const QByteArray &data)
{
	// Output the received data from serial port directly
   insertPlainText(QString(data));
   // Make the Scrollbar always in the bottom
   QScrollBar *bar = verticalScrollBar();
   bar->setValue(bar->maximum());

   // Split the Qstring - data with space
   QStringList list = (QString(data)).split(' ');
   serialRev0 = list.at(0).toDouble();
   serialRev1 = list.at(1).toDouble();
   serialRev2 = list.at(2).toDouble();
   serialRev3 = list.at(3).toDouble();

   qDebug() << serialRev0;
   qDebug() << serialRev1;
   qDebug() << serialRev2;
   qDebug() << serialRev3;

   // Save four sensors' data to the log file
   consoleLog->data[0] = serialRev0;
   consoleLog->data[1] = serialRev1;
   consoleLog->data[2] = serialRev2;
   consoleLog->data[3] = serialRev3;
   consoleLog->save();
   




}
