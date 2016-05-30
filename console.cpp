#include "console.h"
#include <QScrollBar>
#include <QDebug>

double serialRev0 = 0;
double serialRev1 = 0;
double serialRev2 = 0;
double serialRev3 = 0;

Console::Console()
{

}

void Console::serialReceived(const QByteArray &data)
{
   insertPlainText(QString(data));
   // Make the Scrollbar always in the bottom
   QScrollBar *bar = verticalScrollBar();
   bar->setValue(bar->maximum());

   //QString str = "a,,b,c";
   //QStringList list1 = str.split(',');
   //// list1: [ "a", "", "b", "c" ]
   //QStringList list2 = str.split(',', QString::SkipEmptyParts);
   //// list2: [ "a", "b", "c" ]
   //qDebug() << list2;

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




}
