#pragma once
//#ifndef HALL_FUNCTION
//#define HALL_FUNCTION
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#include <string>
#include <list>
#include <exception>
#include "reader/CreatorReader.h"
#include "hallPlayer.h"
#include "hallTools.h"
#include <boost/thread/thread.hpp>
#include"ui/CocosGUI.h"
#include"ui/UIWidget.h"
#include "chatroom_server.h"
#include"chatroom_client.h"
//#include"chatroom_server.hpp"


using namespace cocos2d;

//#include "proj.win32/hallFunction.h"
class Hall
{
public:
	//�������
	const static unsigned playerNumber = 4;
	Hall();
	virtual ~Hall();
	/*
	Function name:initializationHall
	Description:��������ʽע�������Ϣ
	Created:18/08/24
	Parameter��
		Scene:���뵼���ĳ���ָ��
		HallPlayer�������Ϣ����ָ�룬���ڴ��������Ϣ
	Return Code:VOID
	Authro:Hanyuu
	*/
	void initializationHall(Scene * scene, HallPlayer* hallplayer);

	/*
	Function name : clientPostMessage
	Description : ������Ϣ
	Created : 18/08/29
	Parameter:
		string:��������Ϣ
		string:�������û���
	Return : VOID
	Author : Hanyuu
	*/
	void clientPostMessage(std::string, std::string);

	/*
	Function name:getEditMessage
	Description:��ȡ��Ϣ�༭�����ı�
	Created:180828
	Parameter:VOID
	Return:String:���ص��ı�
	Author:Hanyuu
	*/
	std::string getEditMessage() const;

	/*
	Function name:clearEditBox
	Description:�����Ϣ�༭���е��ı�
	Created:20180829
	Parameter:VOID
	Return:VOID
	Author:Hanyuu
	*/
	void clearEditBox();

	/*
	Function name:addMessageRecord
	Description:�����������¼
	Created:20180829
	Parameter:
		string:Ҫ�ϴ�����Ϣ
		string:Ҫ�ϴ�����Ϣ��string:�û���
	Return:VOID
	Author:Hanyuu
	*/
	void addMessageRecord(std::string);
	void addMessageRecord(std::string, std::string);

	/*
	Function name:isHost
	Description:�ж��Ƿ���Host
	Created:20180829
	Parameter:VOID
	Return:bool:�����Ƿ���Host
	Author:Hanyuu
	*/
	bool isHost() const;

	/*
	Function name:getUserName
	Description:���ص�ǰ�û���
	Created:20180829
	Parameter:VOID
	Return:string:�û����ַ���
	Author:Hanyuu
	*/
	std::string getUserName() const;

	///*
	//Function name:connectMessage
	//Description:ͨѶ�߳�
	//Created:20180829
	//Parameter:VOID
	//Return:VOID
	//Author:Hanyuu 
	//*/
	//void connectMessage();

	/*
	Function name:	messageListener
	Description:������Ϣ
	Created:20180830
	Parameter:shared_ptr:�����ָ��
	Return:string:VOID
	Author:Hanyuu
	*/
	void messageListener(boost::shared_ptr<ChatMessage>);

	/*
	Function name:	setHostStatus
	Description:�����Ƿ�ΪHost
	Created:20180831
	Parameter:bool:Ŀ��Host״̬
	Return:VOID
	Author:Hanyuu
	*/
	void setHostStatus(bool);
	/*
	Function name:getIPaddress
	Description:��EditBox��ȡIP��ַ
	Created:20180901
	Parameter:VOID
	Return:string:IP��ַ
	Author:Hanyuu
	*/
	std::string getIPAdress();
	/*
	Function name:sendMessage
	Description:����������Ϣ
	Created:180826
	Parameter:String:�����͵���Ϣ����
	Return Code:bool:���ͳɹ��ж�
	Author:Hanyuu
	*/
	//bool sendChatMessage(std::string) const;
protected:
private:
	std::string	m_playerName[playerNumber];
	bool m_isHost[playerNumber] = { true,false,false,false };
	unsigned m_myPlayerNumber = 0;
	Scene * m_scene;
	Size m_size;
	cocos2d::Label * m_record;
	//cocos2d::ui::Text * m_record;
	cocos2d::ui::Button * m_sendButton;
	cocos2d::ui::Button * m_changeisHost;
	cocos2d::ui::TextField * m_editBox;
	cocos2d::ui::TextField * m_IPConfig;
	ChatroomServer * ptr = nullptr;
	ChatroomClient * cptr = nullptr;

	//ʵ���Թ���
	std::list<MessageRecord> * m_messageRecord;
	//��������
	std::string m_chatRecord;

};

//#endif