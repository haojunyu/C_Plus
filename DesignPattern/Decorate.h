// Decorate.h
# pragma once

#include<iostream>
#include<string>

using namespace std;

// 公共抽象类
class Phone{
	public:
		Phone(){}
		virtual ~Phone(){}
		virtual void ShowDecorate(){}
};

// iPhone手机
class iPhone : public Phone{
	private:
		string m_name;	//手机名称
	public:
		iPhone(string name): m_name(name){}
		~iPhone(){}
		void ShowDecorate(){
		cout<<m_name<<"的装饰"<<endl;
		}
};
// nokia手机
class NokiaPhone : public Phone{
	private:
		string m_name;	//手机名称
	public:
		NokiaPhone(string name): m_name(name){}
		~NokiaPhone(){}
		void ShowDecorate(){
			cout<<m_name<<"的装饰"<<endl;
		}
};
// 装饰类
class DecoratorPhone : public Phone{
	private:
		Phone *m_phone;		//要装饰的手机
	public:
		DecoratorPhone(Phone *phone):m_phone(phone){}
		virtual void ShowDecorate(){
			m_phone->ShowDecorate();
		}
};
//具体的装饰类
class DecoratorPhoneA : public DecoratorPhone{
	private:
		void AddDecorate(){
			cout<<"屏幕贴膜"<<endl;
		}
	public:
		DecoratorPhoneA(Phone *phone):DecoratorPhone(phone){}
		void ShowDecorate(){
			DecoratorPhone::ShowDecorate();
			AddDecorate();
		}
};
//具体的装饰类
class DecoratorPhoneB : public DecoratorPhone{
	private:
		void AddDecorate(){
			cout<<"增加挂件"<<endl;
		}
	public:
		DecoratorPhoneB(Phone *phone):DecoratorPhone(phone){}
		void ShowDecorate(){
			DecoratorPhone::ShowDecorate();
			AddDecorate();
		}
};
