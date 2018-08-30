#pragma once
//hallTools.h
//Author:Hanyuu
//Commit:
//	工具函数

#include<string>
#include<sstream>
#include<fstream>
//#include<boost/shared_ptr.hpp>
#include "chatroom_server.h"
#include"chatroom_client.h"
#include <boost/thread.hpp>

/*
Function name:int2String
Description:将int类型的变量转换为string类型
Created:18/08/24
Paremeter:int:待转换的int变量
Return code:string 返回string结果
Author:Hanyuu
*/
std::string int2String(int i);
/*
Function name:log
Description:输出log到日志
Created:18/0826
Paremeter:String:要打印的log信息
Return code:VOID
Author:Hanyuu
*/
void hanyuuLog(std::string);

/*
Function:connectMessage
Description:信息收发
Created:18/08/29
Parameter:VOID
Return:VOID
Author:Hanyuu
*/
void connectMessage();

/*
Function name:clientGetMessage
Description:监听信息
Created:18/08/29
Parameter:shared_ptr:调用对象的智能指针
Return:VOID
Author:Hanyuu
*/
void clientGetMessage(boost::shared_ptr<ChatMessage> mp);


