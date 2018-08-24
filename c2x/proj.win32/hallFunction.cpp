//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include "cocos2d.h"
#include "hallFunction.h"
#include "reader/CreatorReader.h"
#include <string>
#include <sstream>
#include <stdlib.h>

#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "reader/CreatorReader.h"
#include "proj.win32/hallFunction.h"


//玩家数量默认为4，若要改动请对应更改UI
unsigned Hall::playerNumber = 4;

Hall::Hall()
{
#ifdef HALL_DEBUG
	std::fstream debugLog("..\\log\\hall.log", std::fstream::app);
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
void Hall::feedPlayerInformation(HallPlayer*)
{
	creator::CreatorReader * reader = creator::CreatorReader::createWithFilename("creator/Scene/Hall.ccreator");
	cocos2d::Scene * scene = reader->getSceneGraph();
	std::string strHead = "player";


	for (unsigned i = 0; i < Hall::playerNumber; i++)
	{
		std::string strNo = std::string(i);
		std::string strName = strHead + strNo;
		cocos2d::Label * player =  (cocos2d::Label *) scene->getChildByName("hallCanvas")->getChildByName(strName);
		if (player == nullptr)
		{
			throw int(1);
		}
	}


}