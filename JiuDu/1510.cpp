/*
 * 本题很简单,不过加上不准使用其他空间和使用O(n)时间复杂度就有点花点心思了
 * 采用从后往前处理的方式
 */
#include<iostream>
#include<stdio.h>
using namespace std;

char arr[1000000];		// 长度为10000时,提交出现RunTime Error

int main(){
	//freopen("in.txt","r",stdin);						
	
	int src_len,des_len,i,j;
	gets(arr);
	// show data
	//printf("%s\n",arr);
		
	// deal data
	des_len=0;
	for(i=0; arr[i]!='\0'; i++){
		if(arr[i]==' ')
			des_len+=2;
		des_len++;
	}
	src_len = i;
			
	for(i=src_len,j=des_len; i>=0; i--){
		if(arr[i]=='\0')
			arr[j--]='\0';
		else if(arr[i]==' '){
			arr[j--]='0';
			arr[j--]='2';
			arr[j--]='%';
		}
		else
			arr[j--]=arr[i];
			
	} 
	
	// output
	printf("%s\n",arr);
}
