/*
 * 和1388完全一样．只是问题不一样，本质上时完全一样的．
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

