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
		//初始化发送按钮
		//m_sendButton = (ui::Button*) m_scene->getChildByName("button");
		m_sendButton = (ui::Button*) m_scene->getChildByName("hallCanvas")->getChildByName("shadowVertcial")->getChildByName("hallChatMessageSendButton");
		m_sendButton->setTitleText("Send");
		m_sendButton->setTitleFontName("微软雅黑");
		m_sendButton->setTitleFontSize(30);
		m_sendButton->addTouchEventListener([&](Ref* sneder, ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				hanyuuLog("Send button touch began.");
				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:
				hanyuuLog("Send button touch moved.");
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				hanyuuLog("Send button touch ended.");
				break;
			case cocos2d::ui::Widget::TouchEventType::CANCELED:
				hanyuuLog("Send button touch canceled.");
				break;
			default:
				hanyuuLog("Send button touch defalult.");
				break;
			}
		});
		//初始化聊天记录框
		m_record = cocos2d::ui::Text::create("Text examples【用户示例】", "..\\font\\gameFont.ttf", 32);
		m_record->setFontSize(30.0f);
		m_record->setAnchorPoint(Vec2(0, 0));
		m_record->setPosition(Vec2(20.0f, 50.0f));
		m_scene->addChild(m_record);
		

		//初始化信息输入窗口
		//m_editBox = ui::Text::create("Input your message here", "Arial", 30);
		//m_editBox->setAnchorPoint(Vec2(0, 0));
		//m_editBox->setPosition(Vec2(50.0f, 100.0f));
		//m_editBox->setVisible(false);
		////m_editBox->setMaxLength(20);
		//m_editBox->setColor(Color3B(100, 46, 240));
		//m_editBox->setZOrder(999);
		//m_scene->addChild(m_editBox);

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
