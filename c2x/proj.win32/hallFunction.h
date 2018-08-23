#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

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
	////Description:��������ʽע�������Ϣ													////
	////Created:18/08/23																			////
	////Parameter��HallPlayer�������Ϣ����ָ�룬���ڴ��������Ϣ			////
	////Return Code:VOID																			////
	////Authro:Hanyuu																				////
	/////////////////////////////////////////////////////////////////////////////////
	void feedPlayerInformation(HallPlayer *);
	//�������
	static unsigned playerNumber;
private:

};