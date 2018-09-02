//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类
#define IP "127.0.0.1"

#include "hall.h"

#include"chatroom_client.h"

extern Hall hall;

//bool  playerIsHost;

////玩家数量默认为4，若要改动请对应更改UI
//unsigned Hall::playerNumber = 4;

//互斥锁
boost::mutex lock;

Hall::Hall()
{
	hanyuuLog("-**Start log**-\nObject Hall generated.");
}

Hall::~Hall()
{
	hanyuuLog("Object Hall destroyed.\n-**End log**-\n");
}

void Hall::initializationHall(Scene * scene, HallPlayer* hallplayer)
{
	//聊天室收发
	if (isHost())
	{
		ptr = server_start(boost::bind(&Hall::messageListener, this, _1));
	}
	else
	{
		cptr = client_start(IP, boost::bind(&Hall::messageListener, this, _1));
	}

	//获取可视尺寸
	m_size = Director::getInstance()->getVisibleSize();

	//导入场景
	if (scene != nullptr)
	{
		m_scene = scene;
		//初始化发送按钮
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
				//hanyuuLog("Send button touch began.");
				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:
				//hanyuuLog("Send button touch moved.");
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				//sendChatMessage(getEditMessage());
				//addMessageRecord(getEditMessage());
				clientPostMessage(getEditMessage(), getUserName());
				clearEditBox();
				//hanyuuLog("Send button touch ended.");
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
		m_record = cocos2d::Label::create("Let's talk!","Arial",30);
		//m_record = cocos2d::Label::create("Let's talk!","Arial",30);
		//m_record = cocos2d::ui::Text::create("Let's talk!","Arial",30);
		//m_record->setFontSize(30);
		m_record->setAnchorPoint(Vec2(0, 0));
		m_record->setPosition(Vec2(m_size.width - 780.0f, 50.0f));
		m_record->setZOrder(2000);
		m_scene->addChild(m_record);

		//初始化信息输入窗口
		m_editBox = cocos2d::ui::TextField::create("Click here and input message", "Arial", 30);
		m_editBox->setFontSize(30);
		m_editBox->setPlaceHolder("Click here and input message");
		m_editBox->setAnchorPoint(Vec2(0, 0));
		m_editBox->setPosition(Vec2(m_size.width - 780.0f, 10.0f));
		m_editBox->setMaxLength(20);
		m_editBox->setZOrder(2001);
		//std::string a = m_editBox->getStringValue();
		m_scene->addChild(m_editBox);

		//ClientIP输入框
		m_IPConfig = cocos2d::ui::TextField::create("127.0.0.1", "Arial", 30);
		m_IPConfig->setFontSize(30);
		m_IPConfig->setPlaceHolder("Input service's IP here");
		m_IPConfig->setAnchorPoint(Vec2(0, 1));
		m_IPConfig->setPosition(Vec2(50, m_size.height - 150));
		m_IPConfig->setMaxLength(20);
		m_IPConfig->setZOrder(100);
		m_IPConfig->setVisible(true);
		m_scene->addChild(m_IPConfig);




		//选择是否是Host
		m_changeisHost = cocos2d::ui::Button::create("button0.png", "button1.png", "button2.png");
		
		m_changeisHost->setTitleText("  Host");
		m_changeisHost->setScale(3);
		m_changeisHost->setTitleFontName("微软雅黑");
		m_changeisHost->setTitleFontSize(15);
		m_changeisHost->setAnchorPoint(Vec2(0, 1));
		m_changeisHost->setPosition(Vec2(30.0f, m_size.height-30.0f));
		m_changeisHost->addTouchEventListener([&](Ref * sender, ui::Widget::TouchEventType type)
		{
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				hanyuuLog("HOST TOUCHED");
				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				if (hall.isHost())
				{
					hall.setHostStatus(false);
					hanyuuLog("Turn to host now");
				}
				else
				{
					hall.setHostStatus(true);
					hanyuuLog("Turn to client now");
				}
				break;
			case cocos2d::ui::Widget::TouchEventType::CANCELED:
				break;
			default:
				break;
			}
		}
		);
		m_scene->addChild(m_changeisHost);

		hanyuuLog("Class hall get scene sucess.");
	}
	else
	{
		hanyuuLog("Class Hall can't touch scene");
		throw std::exception("Empty scene");
	}

	std::string strHead = "bleb";

	hanyuuLog("[Player information]:");

	for (unsigned i = 0; i < Hall::playerNumber; i++)
	{

		std::string strName = strHead + int2String(i);
		cocos2d::Label * player = (cocos2d::Label *) m_scene->getChildByName("hallCanvas")->getChildByName(strName);
		player->setZOrder(100);
		m_playerName[i] = hallplayer[i].playerName;
		player->setString(hallplayer[i].playerName);
		hanyuuLog(hallplayer[i].playerName);
		if (i == m_myPlayerNumber)
		{
			player->setTextColor(cocos2d::Color4B(105, 176, 172, 255));
		}
	}
}

//bool Hall::sendChatMessage(std::string strMessage) const
//{
//	hanyuuLog(strMessage);
//	return true;
//}

std::string Hall::getEditMessage() const
{
	if (m_editBox)
	{
		return m_editBox->getString();
	}
	else
	{
		return std::string("No message");
	}
}

void Hall::clearEditBox()
{
	if (m_editBox)
	{
		m_editBox->setString("");
	}
}

void Hall::addMessageRecord(std::string str)
{
	m_chatRecord += "\n[" + m_playerName[m_myPlayerNumber] + "]" + str + "";
	m_record->setString(m_chatRecord);
	hanyuuLog("[Chat record]\n" + m_chatRecord + "\n");
}

void Hall::addMessageRecord(std::string str, std::string userName)
{
	m_chatRecord += "\n[" + userName + "]" + str + "";
	m_record->setString(m_chatRecord);
	hanyuuLog("[Chat record]\n" + m_chatRecord + "\n");
}

bool Hall::isHost() const
{
	return m_isHost[m_myPlayerNumber];
}

std::string Hall::getUserName() const
{
	return m_playerName[m_myPlayerNumber];
}

//void connectMessage()
//{
//	hanyuuLog("Connect message thread lunched.");
//	client_start("127.0.0.1", clientGetMessage, cptr);
//}

void Hall::messageListener(boost::shared_ptr<ChatMessage> mp)
{
	hanyuuLog("[Receive message from:" + mp->playerName + "]\n    " + mp->message);
	hall.addMessageRecord(mp->message, mp->playerName);
}

void  Hall::clientPostMessage(std::string strMessage, std::string userName)
{
	hanyuuLog("[" + m_playerName[m_myPlayerNumber] + " Post message]\n    " + strMessage);
	ChatMessage  CMMessageFrame;
	CMMessageFrame.playerName = userName;
	CMMessageFrame.message = strMessage;
	if (isHost())
	{
		ptr->post(CMMessageFrame);
	}
	else
	{
		cptr->post(CMMessageFrame);
	}
}

void Hall::setHostStatus(bool target)
{
	m_isHost[m_myPlayerNumber] = target;
	if (target)
	{
		m_changeisHost->setTitleText("  Host");
	}
	else
	{
		m_changeisHost->setTitleText("  Client");
	}
}

std::string getIPAdress()
{
	std::string tempIPAdress;
	return tempIPAdress;
}