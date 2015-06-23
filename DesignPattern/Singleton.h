// Singleton.h
#pragma once

#include<iostream>
#include<stdio.h>
using namespace std;

class Singleton{
	public:
		static Singleton* GetInstance();
		void Show();
	private:
		static Singleton* singleton;
		Singleton(){}
};
