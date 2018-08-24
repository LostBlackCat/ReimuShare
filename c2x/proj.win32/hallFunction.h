#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#define HALL_DEBUG
#include <string>
#include "reader/CreatorReader.h"
#include "hallPlayer.h"
#include "hallTools.h"
#ifdef HALL_DEBUG
#include<fstream>
#endif // HALL_DEBUG

//#include "proj.win32/hallFunction.h"
class Hall
{
public:
	Hall();
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

};