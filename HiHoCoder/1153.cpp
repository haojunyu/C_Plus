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


char arr[501],res[501];
char dict[10][12] = {"0","9876543210","9865320","963","9876540","98650","96","9870","980","9"};



int isNum(const char* arr){
	int i;
	int flag = 0;

	if(strlen(arr)<=1)
		return -1;
	for(i=0; i<strlen(arr)-1; i++){
		char *p = &dict[arr[i]-'0'][0];
		if(strchr(p,arr[i+1]) == NULL){
			flag =1;
			break;
		}
	}

	if(flag)
		return i;
	else
		return -1;
}


int main(){
	freopen("input.txt","r",stdin);	
	freopen("out.txt","w",stdout);
	int num,i,j,k,t;
	char one[10]="1";

	scanf("%d",&num);
	for(t=0; t<num; t++){

		// input & print
		scanf("%s",arr);

		// deal with data
	
		int pos;
		while((pos=isNum(arr))!=-1){
			i=pos;
			char *p = &dict[arr[i]-'0'][0];
			for(j=0; j<strlen(p); j++){
				if(p[j]<arr[i+1])
					break;
			}
			if(j == strlen(p)){
				if(arr[i] == '1'){
					for(k=i;k<strlen(arr);k++)
						arr[k]='0';
				}else{
					arr[i]--;
					for(k=i+1;k<strlen(arr);k++)
						arr[k]='9';
				}
			}else{
				arr[i+1]=p[j];
				if(p[j]=='0'){
					for(k=i+2;k<strlen(arr);k++)
						arr[k]='0';
				}else{
					for(k=i+2;k<strlen(arr);k++)
						arr[k]='9';
				}
			}
			
		}
		printf("%s\n",arr);

	}
}



// ==========================================================
/*
//通过大数减法，依次判断该大数是否能够由数字键盘按出。
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char arr[501],res[501];
char dict[10][12] = {"0","9876543210","9865320","963","9876540","98650","96","9870","980","9"};

// diff = a - b(a>=0&&b>=0)
void Minus(char *diff, char *a, char *b){
	if(strcmp(a,b)==0){
		strcpy(diff,"0");
		return;
	}
	int flag = 0,i,c = 0;
	char *big, *sma;
	int alen=strlen(a),blen=strlen(b);
	if(alen<blen || (alen==blen && strcmp(a,b)<0)){
		flag = 1;
		big = b;
		sma = a;
	}else{
		big = a;
		sma = b;
	}

	int biglen=strlen(big),smalen=strlen(sma);
	for(i=0; i<biglen||c>0; i++){
		char ch;
		if(i<smalen)
			ch = sma[smalen-i-1];
		else
			ch = '0';
		int tmp = big[biglen-i-1] - ch - c;
		if(tmp < 0){
			tmp += 10;
			c = 1;
		}else
			c = 0;
		diff[i] = tmp + '0';
	}	
	// escape 10-5
	if(diff[i-1]=='0')
		i--;
	if(flag)
		diff[i++] = '-';
	diff[i] = '\0';
	// reverse the string of sum
	int reslen = i;
	for(i=0; i<reslen/2; i++){
		char tmp = diff[i];
		diff[i] = diff[reslen-i-1];
		diff[reslen-i-1] = tmp;
	}
}

int isNum(const char* arr){
	int i;
	int flag=1;
	for(i=0; i<strlen(arr)-1; i++){
		char *p = &dict[arr[i]-'0'][0];
		if(strchr(p,arr[i+1]) == NULL){
			flag=0;
			break;
		}
	}
	return flag;

}

int main(){
	freopen("in.txt","r",stdin);	
	freopen("out_2.txt","w",stdout);

	int num,i;
	char one[10]="1";
	scanf("%d",&num);

	for(i=0; i<num; i++){
		// input & print
		scanf("%s",arr);
		// deal with data
		while(1){
			if(isNum(arr)){
				printf("%s\n",arr);
				break;
			}else{
				Minus(res,arr,one);
				memcpy(arr,res,sizeof(char)*strlen(res));
			}

		}

		// output

	}
}
*/
