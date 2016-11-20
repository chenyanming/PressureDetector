#ifndef DATA_H
#define DATA_H
#include <QString>

class Data {
public:
	static Data& getInstance();
	//void Data::setILS();
	struct Data1
	{
		double serialRev0;
		double serialRev1;
		double serialRev2;
		double serialRev3;
		double ev;
		QString logFile;
	};
	Data1 PressData;

private:
	Data();
	Data(const Data &);
	Data &operator=(const Data &);

	virtual ~Data();

	//class ILSData;
	//ILSData *m_data;

	
};

#endif // CURVEDATA_H
