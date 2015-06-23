#include<stdio.h>


int main(){
	freopen("input.txt","w",stdout);
	int num;
	scanf("%d",&num);
	printf("%d\n",num);

	for(int i=1; i<=num; i++){
		printf("%d\n",i);
	}
	return 0;
}
