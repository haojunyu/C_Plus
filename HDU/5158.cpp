#include<stdio.h>

int main(){
    freopen("in.txt","r",stdin);
    int n,m;
	
	// 求模问题
    while(scanf("%d %d",&n,&m)==2){
		printf("%d\n",(m-1)%n);
	}
    return 0;
}
