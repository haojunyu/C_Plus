#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	//freopen("out.txt","w",stdout);										//redirect the output stream
	
	int i,counts;
	char str[100]	;

	scanf("%d",&counts);
	
	for(i=0; i<counts; i++)
	{
		scanf("%s",str);
		if(strcmp(str,"E") == 0)
		{
			printf("Excellent\n");
			continue;
		}
		if(strcmp(str,"C") == 0)
		{
			printf("Cheer\n");
			continue;
		}
		if(strcmp(str,"N") == 0)
		{
			printf("Nice\n");
			continue;
		}
		if(strcmp(str,"U") == 0)
		{
			printf("Ultimate\n");
			continue;
		}
		if(strcmp(str,"Impossible") == 0)
		{
			printf("I'm possible\n");
			continue;
		}
		if(strcmp(str,"ACM") == 0)
		{
			printf("Accept More\n");
			continue;
		}
	}
	
}



















