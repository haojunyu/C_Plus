#include<stdio.h>
#include<stdlib.h>

int* GrayCode(int n, int* returnSize) {
    int i;
    *returnSize = 1<<n;
    int* gray=malloc((*returnSize)*sizeof(int));
    for(i=0; i<*returnSize; i++){
		gray[i]=i^(i>>1);
	}
	return gray;
}

int main(){
	int i;
	int *returnSize, *gray;
	while(scanf("%d",&i)!=EOF){
		gray=GrayCode(i, returnSize);
		for(i=0; i< *returnSize; i++){
			printf("%d ",gray[i]);
		}
		free(gray);
	}
	return 0;
}
