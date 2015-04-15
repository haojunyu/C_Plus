/*
 * 直接用递归，代码很简单。但是复杂度上就比较难了，而且其中出现了多次重复
 * 的计算，提出的改进方法就是用空间换时间--用数组记录下之前记录的，每次
 * 只有没有计算的时候才会用递归计算，否则直接从数组中提取。
 */

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

long arr[71];

long Fibonacci(int num){
	if(arr[num]==0){
		if(num == 0)
			arr[num] = 0;
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

