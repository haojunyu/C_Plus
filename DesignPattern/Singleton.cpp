// Singleton.cpp
#include "Singleton.h"

// 成员变量初始化
Singleton* Singleton::singleton = NULL;

// 成员函数声明
Singleton* Singleton::GetInstance(){
	if(singleton == NULL)
		singleton = new Singleton();
	return singleton;
}

void Singleton::Show(){
	printf("singleton's address is %p.\n",singleton);
}
