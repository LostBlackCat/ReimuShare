#pragma once
//hallPlayer.h
//Author:hanyuu
//Commit:
//	玩家信息结构体

#include <string>
struct HallPlayer
{
	//玩家头像地址
	char * playerHeadProtraitURL;
	//玩家姓名
	char * playerName;
};

struct MessageRecord
{
	//发送者姓名
	std::string name;
	//消息内容
	std::string message;
};