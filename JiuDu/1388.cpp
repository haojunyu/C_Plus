/*
 * 跳台阶这个和斐波那契的思想时类似的，特别当只有１和２两种跳法时，走法
 * 就是斐波那契数列．方法和1387.cpp基本一样．唯一的不同时在０时，值为１．
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

long arr[71];

long Fibonacci(int num){
	if(arr[num]==0){
		if(num == 0)
			arr[num] = 1;
		else if(num == 1)
			arr[num]=1;
		else
			arr[num] = Fibonacci(num-1)+Fibonacci(num-2);
	}
	return arr[num];
}

int main(){
    freopen("in.txt","r",stdin);                  
     
    int num;
	memset(arr,0,sizeof(long));

    while(scanf("%d",&num) != EOF){
        
		// deal with data
		long res = Fibonacci(num);
		// output
		printf("%ld\n",res);
    }
}

