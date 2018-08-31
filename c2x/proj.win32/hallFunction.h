#pragma once
//#ifndef HALL_FUNCTION
//#define HALL_FUNCTION
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include <string>
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
	//玩家数量
	const static unsigned playerNumber = 4;
	Hall();
	virtual ~Hall();
	/*
	Function name:initializationHall
	Description:以数组形式注册玩家信息
	Created:18/08/24
	Parameter：
		Scene:传入导出的场景指针
		HallPlayer：玩家信息数组指针，用于传入玩家信息
	Return Code:VOID
	Authro:Hanyuu
	*/
	void initializationHall(Scene * scene, HallPlayer* hallplayer);

	/*
	Function name : clientPostMessage
	Description : 发送信息
	Created : 18/08/29
	Parameter:
		string:待发送信息
		string:发送者用户名
	Return : VOID
	Author : Hanyuu
	*/
	void clientPostMessage(std::string, std::string);

	/*
	Function name:getEditMessage
	Description:获取信息编辑框中文本
	Created:180828
	Parameter:VOID
	Return:String:返回的文本
	Author:Hanyuu
	*/
	std::string getEditMessage() const;

	/*
	Function name:clearEditBox
	Description:清除信息编辑框中的文本
	Created:20180829
	Parameter:VOID
	Return:VOID
	Author:Hanyuu
	*/
	void clearEditBox();

	/*
	Function name:addMessageRecord
	Description:添加新聊天记录
	Created:20180829
	Parameter:
		string:要上传的信息
		string:要上传的信息，string:用户名
	Return:VOID
	Author:Hanyuu
	*/
	void addMessageRecord(std::string);
	void addMessageRecord(std::string, std::string);

	/*
	Function name:isHost
	Description:判断是否是Host
	Created:20180829
	Parameter:VOID
	Return:bool:返回是否是Host
	Author:Hanyuu
	*/
	bool isHost() const;

	/*
	Function name:getUserName
	Description:返回当前用户名
	Created:20180829
	Parameter:VOID
	Return:string:用户名字符串
	Author:Hanyuu
	*/
	std::string getUserName() const;

	///*
	//Function name:connectMessage
	//Description:通讯线程
	//Created:20180829
	//Parameter:VOID
	//Return:VOID
	//Author:Hanyuu 
	//*/
	//void connectMessage();

	/*
	Function name:	messageListener
	Description:监听信息
	Created:20180830
	Parameter:shared_ptr:传入的指针
	Return:string:VOID
	Author:Hanyuu
	*/
	void messageListener(boost::shared_ptr<ChatMessage>);

	/*
	Function name:	setHostStatus
	Description:设置是否为Host
	Created:20180831
	Parameter:bool:目标Host状态
	Return:string:VOID
	Author:Hanyuu
	*/
	void setHostStatus(bool);
	/*
	Function name:sendMessage
	Description:发送聊天信息
	Created:180826
	Parameter:String:待发送的信息变量
	Return Code:bool:发送成功判断
	Author:Hanyuu
	*/
	//bool sendChatMessage(std::string) const;
protected:
private:
	std::string	m_playerName[playerNumber];
	std::string m_chatRecord;
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
};

//#endif