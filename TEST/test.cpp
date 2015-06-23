#include<iostream>
using namespace std;

class Number{
	public:
		string type;
		Number():type("void"){}
		Number(short):type("short"){}
	//	Number(int):type("int"){}
};
void Show(const Number& n){
	cout<< n.type<<endl;
}
int main(){
	
	//unsigned short s=43;
	int s = 43;
	Show(s);
}
