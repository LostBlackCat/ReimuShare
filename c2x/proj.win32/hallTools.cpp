//hallTools.cpp
//Author:Hanyuu
//Commit:
//	���ߺ���

#include"hallTools.h"

std::string int2String(int i)
{
	//intתstring
	std::stringstream ssConv;
	std::string strNo = "";
	ssConv << i;
	ssConv >> strNo;
	return strNo;
}