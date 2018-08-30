//hallTools.cpp
//Author:Hanyuu
//Commit:
//	工具函数

#include"hallTools.h"
#define DEBUG

std::string int2String(int i)
{
	//int转string
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
