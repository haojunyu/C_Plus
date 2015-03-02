#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	char c;
	while(scanf("%c",&c)!=EOF){
		if(c<='z' && c>='a')
			c=c+'Z'-'z';
		printf("%c",c);
	}
}
