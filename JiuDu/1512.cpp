/*
 * stack--先进后出（反序）， queue--先进先出（正序）
 * 两个stack构建queue： 有句话叫负负得正。一个stack经过另一个stack的反转后顺序将会变正。所以时间复杂度是O(n)
 * 两个queue构建stack： 正和正的组合无法得到负的。所以在取数时，总是将另一个空的queue作为中转站，存的时候，总是要找那个非空的queue去存。时间复杂度是O(n^2)
 */
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
 
int main(){
    freopen("in.txt","r",stdin);                  
     
    int num,i;
	char operate[5];
	int operand;
    stack<int> sIn,sOut;
    scanf("%d",&num);
    for(i=0; i<num; i++){
		scanf("%s", operate);
		
		// deal data
		if(strcmp("PUSH",operate)==0){
			// push operate
			scanf("%d", &operand);
			sIn.push(operand);
		}else if(strcmp("POP",operate)==0){
			// pop operate
			if(sOut.empty()&&sIn.empty()){
				printf("-1\n");
				continue;
			}
			if(sOut.empty()&&!sIn.empty()){
				while(!sIn.empty()){
					int tmp = sIn.top();
					sIn.pop();
					sOut.push(tmp);
				}
			}
			int tmp = sOut.top();
			sOut.pop();
			printf("%d\n",tmp);

		}else{
			printf("operate error!!!\n");
			exit(1);
		}
	} 

}

