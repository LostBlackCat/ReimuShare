#pragma once
//hallTools.h
//Author:Hanyuu
//Commit:
//	工具函数

#include<string>
#include<sstream>
#include<fstream>

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