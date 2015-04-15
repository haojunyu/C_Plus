/*
 * 　最坏的情况是不知怎么求解，可以列举前几项，最终会发现规律的．不过这个和
 * 　之前的斐波那契数的思路是一样的，不过因为第一步由ｎ中走法，所以对于ｎ个
 * 　台阶的问题，走法是前ｎ个项相加，化简后就是２＾（ｎ－１）
 */

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int main(){
    freopen("in.txt","r",stdin);                  
     
    int num;

    while(scanf("%d",&num) != EOF){
    	printf("%ld\n",(long)pow(2,num-1));    
    }
}

