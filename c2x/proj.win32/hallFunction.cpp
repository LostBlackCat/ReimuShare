//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include "hallFunction.h"

//玩家数量默认为4，若要改动请对应更改UI
unsigned Hall::playerNumber = 4;

Hall::Hall(Scene * scene)
{
#ifdef HALL_DEBUG
	std::fstream debugLog("..\\log\\hall.log", std::fstream::app);
	debugLog << "\nClass Hall generated.";
	debugLog.close();
#endif // HALL_DEBUG
	if (scene!=nullptr)
	{
		m_scene = scene;
	}
	else
	{
		throw std::exception("Empty scene");
	}
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
	std::string strHead = "bleb";

	for (unsigned i = 0; i < Hall::playerNumber; i++)
	{

		std::string strName = strHead + int2String(i);
		cocos2d::Label * player = (cocos2d::Label *) m_scene->getChildByName(strName);
		player->setZOrder(100);
		//player->setSystemFontSize(50);
		player->setString(hallplayer[i].playerName);
		//player->setColor(cocos2d::Color3B(45,34,165));
	
	}
}

