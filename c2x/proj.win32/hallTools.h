#pragma once
//hallTools.h
//Author:Hanyuu
//Commit:
//	���ߺ���

#include<string>
#include<sstream>
#include<fstream>
//#include<boost/shared_ptr.hpp>
#include "chatroom_server.h"
#include"chatroom_client.h"
#include <boost/thread.hpp>

/*
Function name:int2String
Description:��int���͵ı���ת��Ϊstring����
Created:18/08/24
Paremeter:int:��ת����int����
Return code:string ����string���
Author:Hanyuu
*/
std::string int2String(int i);
/*
Function name:log
Description:���log����־
Created:18/0826
Paremeter:String:Ҫ��ӡ��log��Ϣ
Return code:VOID
Author:Hanyuu
*/
void hanyuuLog(std::string);

/*
Function:connectMessage
Description:��Ϣ�շ�
Created:18/08/29
Parameter:VOID
Return:VOID
Author:Hanyuu
*/
void connectMessage();

/*
Function name:clientGetMessage
Description:������Ϣ
Created:18/08/29
Parameter:shared_ptr:���ö��������ָ��
Return:VOID
Author:Hanyuu
*/
void clientGetMessage(boost::shared_ptr<ChatMessage> mp);


