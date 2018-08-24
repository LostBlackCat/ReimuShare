#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

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
	Description:以数组形式注册玩家信息
	Created:180824
	Parameter：HallPlayer：玩家信息数组指针，用于传入玩家信息
	Return Code:VOID
	Authro:Hanyuu
	*/
	void feedPlayerInformation(HallPlayer *);
	//玩家数量
	static unsigned playerNumber;
protected:

private:
	Scene * m_scene;
};