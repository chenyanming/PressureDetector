#include "data.h"

Data& Data::getInstance()
{
	static Data a;
	return a;
}

//class Data::ILSData
//{
//public:
//	ILSData()
//	{
//		serialRev0 = 0;
//		serialRev1 = 0;
//		serialRev2 = 0;
//		serialRev3 = 0;
//	}
//private:
//	double serialRev0;
//	double serialRev1;
//	double serialRev2;
//	double serialRev3;
//
//
//};

Data::Data()
{
	//m_data = new ILSData();
}

Data::~Data()
{
	//delete m_data;
}

//void Data::setILS()
//{
//
//}