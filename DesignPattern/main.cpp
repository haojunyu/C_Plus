// 设计模式测试的主函数
#include<iostream>
#include "Singleton.h"
#include "Decorate.h"

using namespace std;

// 单例模式测试
void TestSingleton();
// 装饰模式
void TestDecorator();

int main(){
	TestSingleton();

	TestDecorator();

	return 0;
}

void TestSingleton(){
	Singleton *st1 = Singleton::GetInstance();
	st1->Show();

	Singleton *st2 = Singleton::GetInstance();
	st2->Show();
}

void TestDecorator(){
	Phone *iphone = new NokiaPhone("6300");
	Phone *dpa = new DecoratorPhoneA(iphone);
	Phone *dpb = new DecoratorPhoneB(dpa);
	dpb->ShowDecorate();

	delete dpa;
	delete dpb;
	delete iphone;
}
