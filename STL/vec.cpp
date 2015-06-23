#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;


bool Comp(const int &a,const int &b){
	return a>b;
}

int main(){
	vector<int> vec;
	//input 
	printf("please input six int number:\n");
	for(int i=0; i<6; i++){
		int data;
		scanf("%d",&data);
		vec.push_back(data);
	}


	// travel
	printf("the original datas:\n");
	vector<int>::iterator it;
	for(it=vec.begin(); it<vec.end();it++)
		printf("%d ",*it);
	printf("\n");


	// insert into middle
	printf("insert into 9 in position 1\n");
	vec.insert(vec.begin()+1,9);
	for(it=vec.begin(); it<vec.end();it++)
		printf("%d ",*it);
	printf("\n");


	// erase elements from position 3 to position 4
	printf("erase elements from position 3 to position 4\n");
	vec.erase(vec.begin()+3,vec.begin()+4);
	for(it=vec.begin(); it<vec.end();it++)
		printf("%d ",*it);
	printf("\n");
	
	
	//reverse the vector
	printf("reverse the vector\n");
	reverse(vec.begin(),vec.end());
	for(it=vec.begin(); it<vec.end();it++)
		printf("%d ",*it);
	printf("\n");
	

	// sort the vector
	printf("sort the vector\n");
	sort(vec.begin(),vec.end(),Comp);
	for(it=vec.begin(); it<vec.end();it++)
		printf("%d ",*it);
	printf("\n");
	

	// clear the vector
	printf("clear the vector\n");
	vec.clear();
	printf("the size of the vector is %ld.\n",vec.size());

	return 0;
}
