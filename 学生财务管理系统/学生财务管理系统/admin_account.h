#ifndef ADMIN_ACCOUNT_H
#define ADMIN_ACCOUNT_H
#pragma warning(disable:4996)//屏蔽VS2017根据新的标准，对fopen等函数的不安全考虑，造成的警告

#include<stdio.h>

/***********************************
[结构体名] Account
[成员1] str_acc[7]  //六位数账户
[成员2] str_password[17]  //账户密码
[成员3] next  //Account指针
***********************************/
typedef struct Account
{
	char str_acc[7];//六位数的账户，按照字符串格式存储
	char str_password[17];//账户密码，字符串格式存储
	struct Account *next;//指向下一个账户的地址
}Account;//定义账户类型的结构体，按照链表方式存储所有账户


/***************************************************************************************
[函数名] add_account
[传入参数] 无
[返回值] 无
[函数功能] 添加新账户
[调用非库函数] fread_account;judge_acclegal;loc_account;fwrite_account;free_accountlist
[头文件的使用] <stdio.h>;<string.h>;"safe.h"
******************************************************************************************/
void add_account();//添加账户

/********************************************************
[函数名] judge_acclegal
[传入参数] 需要判断的字符串
[返回值] 长度非法返回0,账户不为纯数字时，返回1,//账户合法，返回2
[函数功能] 判断用户名是否符合标准
[调用非库函数] 无
[头文件的使用] <stdio.h>;<string.h>
*********************************************************/
int judge_acclegal(char acc[]);//判断账户是否合法,长度非法返回0；账户不为纯数字时，返回1；账户合法，返回2

/**********************************************************
[函数名] fwrite_account
[传入参数1] 相应的账户的指针
[传入参数2] 相应的文件指针
[返回值] 长度非法返回0,账户不为纯数字时，返回1,//账户合法，返回2
[函数功能] 将一个账户的信息写入文件中保存
[调用非库函数] encryption
[头文件的使用] <stdio.h>;<string.h>;"safe.h"
***********************************************************/
void fwrite_account(Account* account, FILE* fp);//写入新的账户，账户和密码共占用一行

/****************************************************
[函数名] fread_account
[传入参数] 无
[返回值] 账户类型指针
[函数功能] 将账户信息读取为链表结构，加载所有账户
[调用非库函数] decrption
[头文件的使用] <stdio.h>;<string.h>;"safe.h"
*****************************************************/
Account* fread_account();//将文件中的账户加载到内存，以链表方式存储,返回链表头指针

/**************************************************************************
[函数名] delete_account
[传入参数] 无
[返回值] 无
[函数功能] 删除已有账户
[调用非库函数] fread_account;loc_account;fwrite_account;free_accountlist
[头文件的使用] <stdio.h>;<string.h>
**************************************************************************/
void delete_account();//删除账户

/*********************************
[函数名] free_accountlist
[传入参数] 账户类型指针
[返回值] 无
[函数功能] 释放账户链表
[调用非库函数] 无
[头文件的使用] <stdio.h>;<string.h>
**********************************/
void free_accountlist(Account*);//释放账户链表

/*************************************
[函数名] loc_account
[传入参数1] 用户名
[传入参数2] 加载到的账户链表首指针
[返回值] 账户类型指针
[函数功能] 根据用户名搜索到加载的账户指针
[调用非库函数] 无
[头文件的使用] <stdio.h>;<string.h>
**************************************/
Account* loc_account(char a[], Account*);//定位账户

/***********************************
[函数名] show_account
[传入参数] 账户类型指针
[返回值] 无
[函数功能] 显示所有账户
[调用非库函数] 无
[头文件的使用] <stdio.h>;<string.h>
*************************************/
void show_account();//输出所有已有账户

#endif
