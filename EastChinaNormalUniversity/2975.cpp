//WRONG ANSWER
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct number
{
	int shu;
	int gw;
};

number arr[1001];

int CompShu(const void *a,const void *b);
int CompGw(const void *a,const void *b);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int num,counts;
	int i,j,front;
	scanf("%d",&num);
	
	for(i=0; i<num; i++)
	{
		scanf("%d",&counts);
		for(j=0; j<counts; j++)
		{
			scanf("%d",&arr[j].shu);
			arr[j].gw=arr[j].shu%10;
		}
		
		qsort(arr,counts,sizeof(number),CompShu);
		qsort(arr,counts,sizeof(number),CompGw);
		
		
		printf("case #%d:\n",i);
		for(j=0; j<counts; j++)
		{
			if(j == 0)
			{
				front=arr[j].shu;
				printf("%d",arr[j].shu);
			}
			else
			{
				if(front != arr[j].shu)
				{
					front=arr[j].shu;
					printf(" %d",arr[j].shu);
				}
			}	
		}
		printf("\n");
	}
}



/*
 * desc:	qsort的比较函数,以shu为比较值
 * pars:	void a,b --要比较的两个值
 * ret:		int --比较的结果
 */
int CompShu(const void *a,const void *b)
{
	return ((number *)a)->shu-((number *)b)->shu;
}


/*
 * desc:	qsort的比较函数,以gw为比较值
 * pars:	void a,b --要比较的两个值
 * ret:		int --比较的结果
 */
int CompGw(const void *a,const void *b)
{
	return ((number *)a)->gw-((number *)b)->gw;
}
