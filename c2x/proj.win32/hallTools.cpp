//hallTools.cpp
//Author:Hanyuu
//Commit:
//	���ߺ���

#include"hallTools.h"
#define DEBUG

std::string int2String(int i)
{
	//intתstring
	std::stringstream ssConv;
	std::string strNo = "";
	ssConv << i;
	ssConv >> strNo;
	return strNo;
}

void hanyuuLog(std::string logInf)
{
#ifdef DEBUG
	std::fstream debugLog("hanyuu.log", std::fstream::app);
	debugLog << logInf << "\n";
	debugLog.close();
#endif // DEBUG
}
