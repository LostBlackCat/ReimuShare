//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#define HALL_DEBUG
#include "hallFunction.h"
#include "hallPlayer.h"
#ifdef HALL_DEBUG
#include <fstream>
#endif // HALL_DEBUG

//玩家数量默认为4，若要改动请对应更改UI
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