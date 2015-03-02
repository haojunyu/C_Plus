#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	//freopen("out.txt","w",stdout);										//redirect the output stream
	
	int counts,i,j;
	int words,digital,extra;
	char tmp[10000];
	scanf("%d\n",&counts);
	
	for(i=0; i<counts; i++)
	{
		words=0;
		digital=0;
		extra=0;
		cin.getline(tmp,10000,'\n');
		for(j=0; j < (int)strlen(tmp); j++)
		{
			if((tmp[j] >= 'a' && tmp[j] <='z') || (tmp[j] >='A' && tmp[j] <= 'Z'))
				words++;
			else if(tmp[j] >='0' && tmp[j] <= '9')
				digital++;
			else
				extra++;
		}
		printf("character:%d\n",words);
		printf("number:%d\n",digital);
		printf("others:%d\n",extra);
	}
}
