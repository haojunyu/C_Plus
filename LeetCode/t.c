#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void GrayCode(int bin[], int ind, int sum, int num){
	int i;
	if(ind==num){
		for(i=0; i<num; i++)
			printf("%d ",bin[i]);
		printf("\n");
		return;
	}else {
		if(sum%2==0){
			bin[ind]=0;
			GrayCode(bin,ind+1,sum,num);
			bin[ind]=1;
			GrayCode(bin,ind+1,sum+1,num);
		}else{
			bin[ind]=1;
			GrayCode(bin,ind+1,sum+1,num);
			bin[ind]=0;
			GrayCode(bin,ind+1,sum,num);
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int n;
	while(scanf("%d",&n)!=EOF){
		// 初始化
		int *bin=(int *)malloc(n*sizeof(int));
		memset(bin,0, n*sizeof(int));
		if(n>0)
			GrayCode(bin,0,0,n);
		else
			printf("n must be larger than 0!!\n");

		free(bin);
	}
}

