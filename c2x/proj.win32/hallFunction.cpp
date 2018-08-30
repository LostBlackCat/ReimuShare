//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������
#define IP "127.0.0.1"

#include "hallFunction.h"

#include"chatroom_client.h"

extern Hall hall;

bool  playerIsHost;


////�������Ĭ��Ϊ4����Ҫ�Ķ����Ӧ����UI
//unsigned Hall::playerNumber = 4;

//������
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
	//�������շ�
	if (isHost())
	{
		ptr = server_start(boost::bind(&Hall::messageListener,this,_1));
	}
	else
	{
		cptr = client_start(IP, boost::bind(&Hall::messageListener, this,_1));
	}

	//��ȡ���ӳߴ�
	m_size = Director::getInstance()->getVisibleSize();

	//���볡��
	if (scene != nullptr)
	{
		m_scene = scene;
		//��ʼ�����Ͱ�ť
		m_sendButton = (ui::Button*) m_scene->getChildByName("hallCanvas")->getChildByName("shadowVertcial")->getChildByName("hallChatMessageSendButton");
		m_sendButton->setTitleText("Send");
		m_sendButton->setTitleFontName("΢���ź�");
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
		//��ʼ�������¼��
		m_record = cocos2d::ui::Text::create("Let's talk!", "..\\font\\gameFont.ttf", 32);
		m_record->setFontSize(30.0f);
		m_record->setAnchorPoint(Vec2(0, 0));
		m_record->setPosition(Vec2(m_size.width - 780.0f, 50.0f));
		m_scene->addChild(m_record);

		//��ʼ����Ϣ���봰��
		m_editBox = cocos2d::ui::TextField::create("Click here and input message", "..\\font\\gameFont.ttf", 32);
		m_editBox->setFontSize(30.0f);
		m_editBox->setPlaceHolder("Click here and input message");
		m_editBox->setAnchorPoint(Vec2(0, 0));
		m_editBox->setPosition(Vec2(m_size.width - 780.0f, 10.0f));
		m_editBox->setMaxLength(20);
		std::string a = m_editBox->getStringValue();
		m_scene->addChild(m_editBox);

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
	m_chatRecord += "[" + m_playerName[m_myPlayerNumber] + "]" + str + "\n";
	m_record->setString(m_chatRecord);
	hanyuuLog("[Chat record]\n" + m_chatRecord + "\n");
}

void Hall::addMessageRecord(std::string str, std::string userName)
{
	m_chatRecord = m_chatRecord + "[" + userName + "]\n    " + str + "\n";
	m_record->setString(m_chatRecord);
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
	hall.addMessageRecord(mp->message, mp->playerName);
	hanyuuLog("[Receive message from:" + mp->playerName + "\n    " + mp->message);
}

void  Hall::clientPostMessage(std::string strMessage, std::string userName)
{
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
	hanyuuLog("[Post message]\n    " + strMessage);
}