// 设计模式测试的主函数
//#include<iostream>
#include "Singleton.h"

// 单例模式测试
void TestSingleton();

int main(){
	TestSingleton();

	return 0;
}

void TestSingleton(){
	Singleton *st = Singleton::GetInstance();
	st->Show();
}
