#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	提供控制大厅的类

#include"hallPlayer.h"

class Hall
{
public:
	Hall();
	virtual ~Hall();
	//以数组形式注册玩家信息
	void feedPlayerInformation(HallPlayer *);
	//玩家数量
	static unsigned playerNumber;
private:

};