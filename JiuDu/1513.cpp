/*
 * 　本题的关键是(num-1)&num 可以去掉num中最右边的１.该方法直接锁定最右边的１,
 * 	而不是一位一位的排除，避免了正负数带来的最高位移位差异.而且效率高．
 */

#include<iostream>
#include<stdio.h>
using namespace std;

int Count1(int num){
	int counts=0;

	while(num){
		num = (num-1) & num;
		counts++;
	}

	return counts;
}
int main(){
    freopen("in.txt","r",stdin);                  
     
    int num,i,data;
	scanf("%d",&num);
	
	for(i=0;i<num;i++){
		scanf("%d",&data);
    	printf("%d\n",Count1(data));    
	}
}

