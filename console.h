#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextEdit>


class Console : public QTextEdit
{
public:
    Console();
    void serialReceived(const QByteArray &data);
};

#endif // CONSOLE_H
