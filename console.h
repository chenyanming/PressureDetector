#ifndef CONSOLE_H
#define CONSOLE_H
#include "log.h"

#include <QTextEdit>

class Log;
class Console : public QTextEdit
{
    Q_OBJECT
public:
    Console();
    void serialReceived(const QByteArray &data);
private:
	Log *consoleLog;
};

#endif // CONSOLE_H
