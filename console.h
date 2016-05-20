#ifndef CONSOLE_H
#define CONSOLE_H

#include <QTextEdit>


class Console : public QTextEdit
{
    Q_OBJECT
public:
    Console();
    void serialReceived(const QByteArray &data);
};

#endif // CONSOLE_H
