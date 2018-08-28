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
			std::string editMessage = getEditMessage();
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				hanyuuLog("Send button touch began.");
				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:
				hanyuuLog("Send button touch moved.");
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				sendChatMessage(getEditMessage());
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
		m_editBox = cocos2d::ui::TextField::create("Click here and input message", "..\\font\\gameFont.ttf", 32);
		m_editBox->setFontSize(30.0f);
		m_editBox->setPlaceHolder("Click here and input message");
		m_editBox->setAnchorPoint(Vec2(0, 0));
		m_editBox->setPosition(Vec2(20.0f, 10.0f));
		m_editBox->setMaxLength(20);
		std::string a = m_editBox->getStringValue();
		m_scene->addChild(m_editBox);

		hanyuuLog("-**Start log**-\nObject Hall generated.");
	}
	else
	{
		hanyuuLog("Class Hall can't touch scene");
		throw std::exception("Empty scene");
	}
}

Hall::~Hall()
{	
	hanyuuLog("Object Hall destroyed.\n-**End log**-\n");
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

bool Hall::sendChatMessage(std::string strMessage) const
{
	//strMessage = m_editBox->getInsertText();
	hanyuuLog(strMessage);
	return true;
}

std::string Hall::getEditMessage() const
{
	//hanyuuLog("getRditBoxMessage：" + m_editBox->getStringValue());
	if (m_editBox)
	{
		return m_editBox->getString();
	}
	else
	{
		return std::string("No message");
	}
}