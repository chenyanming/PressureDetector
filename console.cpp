#include "console.h"
#include <QScrollBar>

Console::Console()
{

}

void Console::serialReceived(const QByteArray &data)
{
   insertPlainText(QString(data));
   // Make the Scrollbar always in the bottom
   QScrollBar *bar = verticalScrollBar();
   bar->setValue(bar->maximum());
}
