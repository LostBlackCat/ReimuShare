#pragma once
//hallFunction.h

//hallFunction.cpp
//Author:hanyuu
//Commit:
//	�ṩ���ƴ�������

#include"hallPlayer.h"

class Hall
{
public:
	Hall();
	virtual ~Hall();
	//��������ʽע�������Ϣ
	void feedPlayerInformation(HallPlayer *);
	//�������
	static unsigned playerNumber;
private:

};