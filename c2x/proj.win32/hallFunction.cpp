//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include "hallFunction.h"

//玩家数量默认为4，若要改动请对应更改UI
unsigned Hall::playerNumber = 4;

//互斥锁
boost::mutex lock;

Hall::Hall(Scene * scene)
{
#ifdef HALL_DEBUG
	std::fstream debugLog("..\\log\\hall.log", std::fstream::app);
	debugLog << "\nClass Hall generated.";
	debugLog.close();
#endif // HALL_DEBUG
	m_size = Director::getInstance()->getVisibleSize();
	//m_scene->addChild((cocos2d::Node*)m_CCTFDChattingRecord);
	if (scene!=nullptr)
	{
		m_scene = scene;
		m_record = cocos2d::ui::Text::create("Text examples【用户示例】", "..\\font\\gameFont.ttf", 32);
		m_record->setFontSize(30.0f);
		m_record->setAnchorPoint(Vec2(0, 0));
		m_record->setPosition(Vec2(20.0f, 50.0f));
		m_scene->addChild(m_record);
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

bool Hall::sendMessage(std::string) const
{
	//TODO...
	//ERROR:Can't touch Editbox class.
	Label* result =(Label*) m_scene->getChildByName("");
	return true;
}
