#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#include <string>
#include <exception>
#include "reader/CreatorReader.h"
#include "hallPlayer.h"
#include "hallTools.h"
#include <boost/thread/thread.hpp>

using namespace cocos2d;

//#include "proj.win32/hallFunction.h"
class Hall
{
public:
	Hall(Scene *);
	virtual ~Hall();
	/*
	Function name:feedPlayerInformation
	Description:��������ʽע�������Ϣ
	Created:180824
	Parameter��HallPlayer�������Ϣ����ָ�룬���ڴ��������Ϣ
	Return Code:VOID
	Authro:Hanyuu
	*/
	void feedPlayerInformation(HallPlayer *);

	/*
Function name:sendMessage
Description:����������Ϣ
Created:180826
Parameter:String:�����͵���Ϣ����
Return Code:bool:���ͳɹ��ж�
Author:Hanyuu
*/
	bool sendMessage(std::string) const;
	//�������
	static unsigned playerNumber;
protected:
private:
	Scene * m_scene;
	Size m_size;
	cocos2d::ui::Text * m_record;
	cocos2d::ui::Button * m_sendButton;
};