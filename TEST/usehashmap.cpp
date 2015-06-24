#include<ext/hash_map>
#include<string>
#include<iostream>

using namespace std;
/*
// define class
class ClassA{
	private:
		int c_a;
	public:
		ClassA(int a):c_a(a){}
		int GetVal(){
			return c_a;
		}
		void SetVal(int a){
			c_a = a;
		}
};

// define hash function
struct hash_A{
	size_t operator()(const class ClassA &A)const{
		return A.GetVal();
	}
};

//define equal function
struct equal_A{
	bool operator()(const class ClassA &a1,const class ClassA &a2)const{
		return a1.GetVal()==a2.GetVal();
	}
};
*/

int main(){
	hash_map<int,string> hamap;
	hamap[1]="a";
	hamap[2]="b";
	hamap[3]="c";
	/*
	hmap["a"]=1;
	hmap["b"]=2;
	hmap["c"]=3;
	*/
	cout<<hamap[2]<<endl;

	return 0;

}
