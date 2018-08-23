//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#define HALL_DEBUG
#include "hallFunction.h"
#include "hallPlayer.h"
#ifdef HALL_DEBUG
#include <fstream>
#endif // HALL_DEBUG

//�������Ĭ��Ϊ4����Ҫ�Ķ����Ӧ����UI
unsigned Hall::playerNumber = 4;

Hall::Hall()
{
#ifdef HALL_DEBUG
	std::fstream debugLog("..\\log\\hall.log",std::fstream::app);
	debugLog << "\nClass Hall generated.";
	debugLog.close();	
#endif // HALL_DEBUG

}
Hall::~Hall()
{
#ifdef HALL_DEBUG
	std::fstream debugLog("..\\log\\hall.log", std::fstream::app);
	debugLog << "\nClass Hall destoried.";
	debugLog.close();
#endif // HALL_DEBUG
}