#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#define HALL_DEBUG
#include "hallPlayer.h"
#include "cocos2d.h"
#ifdef HALL_DEBUG
#include <fstream>
#endif // HALL_DEBUG

class Hall
{
public:
	Hall();
	virtual ~Hall();
	/////////////////////////////////////////////////////////////////////////////////
	////Function Name:feedPlayerInformation											////
	////Description:以数组形式注册玩家信息													////
	////Created:18/08/23																			////
	////Parameter：HallPlayer：玩家信息数组指针，用于传入玩家信息			////
	////Return Code:VOID																			////
	////Authro:Hanyuu																				////
	/////////////////////////////////////////////////////////////////////////////////
	void feedPlayerInformation(HallPlayer *);
	//玩家数量
	static unsigned playerNumber;
private:

};