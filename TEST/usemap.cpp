#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	multimap<string,int> mymap;

	//add
	mymap.insert(pair<string,int>("a",1));
	mymap.insert(pair<string,int>("b",2));
	mymap.insert(pair<string,int>("c",3));
	mymap.insert(pair<string,int>("b",5));
	//mymap["a"]=1;
	//mymap["b"]=2;
	//mymap["c"]=3;
	//mymap["b"]=5;

	//查找
	if(mymap.find("b")!=mymap.end()){
		//cout<<"find "<<mymap["b"]<<endl;
		cout<<mymap.count("b")<<endl;
	}else
	  cout<<"can not find"<<endl;

	return 0;
}
