#include<stdio.h>
#include<stdlib.h>


int arr[1000];

int Comp(const void *a,const void *b);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	//freopen("out.txt","w",stdout);										//redirect the output stream
	
	int numb,counts;
	int i;
	
	
	scanf("%d",&numb);
	while(scanf("%d",&counts)!=EOF){
		for(i=0; i<counts; i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,counts,sizeof(int),Comp);
		for(i=0; i<counts; i++)
		{
			if(i == 0)
				printf("%d",arr[i]);
			else
				printf(" %d",arr[i]);
		}
		printf("\n");
	}
	return 0;
}


/*
 * desc:	qsort的比较函数
 * pars:	const void a,b -- 比较对象
 * ret:	 	int 比较结果
 */
 int Comp(const void *a,const void *b)
 {
	 return *(int *)a-*(int *)b;
 }

