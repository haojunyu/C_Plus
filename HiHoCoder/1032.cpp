/**
 * 关于本题，刚刚读完题目感觉题目考察的点蛮多的，首先是K的
 * 取值范围是超过整型的表示范围的，所以要涉及到大数。其次
 * 三种操作--按下/左移/友移的组合情况太多，如何判断某个数
 * 是能按出来的，最后还要高效找到小于等于K的能按出来的数。
 * 本文提供了两种解法，第一种简单易懂，但效率太低，超时TL。
 * 第二种思路有点复杂，但效率高达O（大数位数），能AC。
 */

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char arr[1000000];

int main(){
	freopen("in.txt","r",stdin);	
//	freopen("out.txt","w",stdout);
	int num,i,j,k,t;

	scanf("%d\n",&num);
	for(t=0; t<num; t++){

		// input & print
		gets(arr);

		// deal with data
	
		printf("%s\n",arr);

	}
}

