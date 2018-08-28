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
	m_size = Director::getInstance()->getVisibleSize();
	//m_scene->addChild((cocos2d::Node*)m_CCTFDChattingRecord);
	if (scene != nullptr)
	{
		m_scene = scene;
		//m_sendButton = (ui::Button*) m_scene->getChildByName("button");
		m_sendButton = (ui::Button*) m_scene->getChildByName("hallCanvas")->getChildByName("shadowVertcial")->getChildByName("hallChatMessageSendButton");
		//初始化聊天记录框
		m_record = cocos2d::ui::Text::create("Text examples【用户示例】", "..\\font\\gameFont.ttf", 32);
		m_record->setFontSize(30.0f);
		m_record->setAnchorPoint(Vec2(0, 0));
		m_record->setPosition(Vec2(20.0f, 50.0f));
		m_scene->addChild(m_record);

		hanyuuLog("Object Hall generated.");
	}
	else
	{
		hanyuuLog("Class Hall can't touch scene");
		throw std::exception("Empty scene");
	}
}

Hall::~Hall()
{
	hanyuuLog("Object Hall destroyed.");
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
	Label* result = (Label*)m_scene->getChildByName("");
	return true;
}
