#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int arr[100000];

int comp(const void *a,const void *b);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int arrCount,testCount;
	int number;
	int i;
	
	scanf("%d",&arrCount);
	for(i=0;i<arrCount;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	qsort(arr,arrCount,sizeof(int),comp);
	
	scanf("%d",&testCount);
	for(i=0;i<arrCount;i++)
	{
		scanf("%d",&number);
		printf("%d\n",arr[number]);
	}
	
}


/*
 * desc:	qsort的比较函数
 * pars:	void a,b --要比较的两个值
 * ret:		int --比较的结果
 */
int comp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
