#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	//freopen("out.txt","w",stdout);										//redirect the output stream
	
	int num;
	int a,b,sum;
	int i,j;
	
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&a,&b);
		sum=a+b;
		j=0;
		while(sum!=0)
		{
			sum=sum/10;
			j++;
		}
		printf("%d\n",j);
	}
}
