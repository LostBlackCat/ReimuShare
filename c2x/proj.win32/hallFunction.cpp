//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include "hallFunction.h"

//#include "reader/CreatorReader.h"
//#include <string>
//#include "AppDelegate.h"
//#include "hallTools.h"
//#include "reader/CreatorReader.h"
//#include "proj.win32/hallFunction.h"


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

void Hall::feedPlayerInformation(HallPlayer* hallplayer)
{
	creator::CreatorReader * reader = creator::CreatorReader::createWithFilename("creator/Scene/Hall.ccreator");
	cocos2d::Scene * scene = reader->getSceneGraph();
	std::string strHead = "bleb";


	for (unsigned i = 0; i < Hall::playerNumber; i++)
	{

		std::string strName = strHead + int2String(i);
		cocos2d::Label * player = (cocos2d::Label *) scene->getChildByName(strName);
		player->setZOrder(100);
		player->setSystemFontSize(500);
		player->setString("I am player " + int2String(i));
		player->setColor(cocos2d::Color3B(45,34,165));
	
	}
}

