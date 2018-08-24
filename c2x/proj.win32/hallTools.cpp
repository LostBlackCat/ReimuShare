//hallTools.cpp
//Author:Hanyuu
//Commit:
//	工具函数

#include"hallTools.h"

std::string int2String(int i)
{
	//int转string
	std::stringstream ssConv;
	std::string strNo = "";
	ssConv << i;
	ssConv >> strNo;
	return strNo;
}