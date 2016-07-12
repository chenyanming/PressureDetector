#include "console.h"
#include <QScrollBar>
#include <QDebug>


Console::Console(QWidget *parent) :
    QTextEdit(parent)
{
}

//void Console::serialReceived(const QByteArray &data)
void Console::serialReceived(const QByteArray &data)
{
	// Output the received data from serial port directly
	insertPlainText(QString(data));
	//qDebug() << toPlainText();
	// Make the Scrollbar always in the bottom
	QScrollBar *bar = verticalScrollBar();
	bar->setValue(bar->maximum());






}
