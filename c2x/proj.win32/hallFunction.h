#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#define HALL_DEBUG
#include <string>
#include <exception>
#include "reader/CreatorReader.h"
#include "hallPlayer.h"
#include "hallTools.h"
#ifdef HALL_DEBUG
#include<fstream>
#endif // HALL_DEBUG

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
	//�������
	static unsigned playerNumber;
protected:

private:
	Scene * m_scene;
};