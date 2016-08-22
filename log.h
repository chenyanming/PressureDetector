#pragma once
#ifndef LOG_H
#define LOG_H
#include <QObject>
#include <QFile>
#include <QDir>
#include <QDateTime>

class Log : public QObject {
	Q_OBJECT

public:
	Log(QObject * parent = Q_NULLPTR);
	~Log();
	void save();
	double data[4]; // exchange data with outside world

private:
	QDir *logDir;
	QFile *logFile;
	QString strBuffer;
	QDateTime time;
	
};
#endif // LOG_H