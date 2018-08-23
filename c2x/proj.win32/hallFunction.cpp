//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include "cocos2d.h"
#include "hallFunction.h"
#include "reader/CreatorReader.h"
#include <string>

#include "AppDelegate.h"
//#include "HelloWorldScene.h"
#include "reader/CreatorReader.h"
#include "proj.win32/hallFunction.h"


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
void Hall::feedPlayerInformation(HallPlayer*)
{
	creator::CreatorReader * reader = creator::CreatorReader::createWithFilename("creator/Scene/Hall.ccreator");
	cocos2d::Scene * scene = reader->getSceneGraph();
	std::string a = "a";
	std::string b = "b";
	std::string c = a + b;

	for (unsigned i = 0; i < Hall::playerNumber; i++)
	{
		//auto  player = scene->getChildByName("hallCanvas")->getChildByName(std::string("player")+std::string(static_cast<char>(i)));
	//	if (player==nullptr)
	//	{
	//		throw int(1);
	//	}
	//}
	}

}