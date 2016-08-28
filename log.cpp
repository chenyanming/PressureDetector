#include "log.h"
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

Log::Log(QObject * parent) : QObject(parent) {

	// make path and set cu
	logDir = new QDir();
	logDir->mkpath("C:/log/");
	logDir->setCurrent("C:/log/");

	// Get Current datetime
	time = QDateTime::currentDateTime();
	strBuffer = time.toString("yyyy-MM-dd_hhmmss");
	//qDebug() << strBuffer;

	// open a file
	logFile = new QFile(logDir->filePath(strBuffer + ".txt"));
	if (!logFile->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox msgBox;
		msgBox.setText("Open C:/log/out.txt failed, please check your permission.");
	}

}

Log::~Log() {
	logFile->close();
}

void Log::save()
{
	// Format and write to a file
	QTextStream out(logFile);
    time = QDateTime::currentDateTime();
    out << time.toString("yyyy/MM/dd hh:mm:ss:zzz") << " " << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << "\n";
}
