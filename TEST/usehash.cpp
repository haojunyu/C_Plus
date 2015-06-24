#include<iostream>
#include<functional>
#include<string>

using namespace std;

int main(){
	hash<string> h;
	size_t n=h("hello world!");
	cout<<n<<endl;
	return 0;
}

//需要用g++ -std=c++0x usehash.cpp进行编译
