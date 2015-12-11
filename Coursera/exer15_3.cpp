///@file    exer15_3.cpp
///@brief   Coursera上C语言进阶课程第三周第三题：排队游戏
///@author  hjy

#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

int main(){
    stack<char> arr;
    stack<int> num;
    char ch,boy;
    int i=0;
    scanf("%c",&boy);
    ch=boy;

    while(ch!='\n'){
        if(ch==boy){
            arr.push(ch);
            num.push(i);
        }else{
            if(arr.empty()){
                printf("error!\n");
                break;
            }else{
                printf("%d %d\n",num.top(),i);
                num.pop();
                arr.pop();
            }
        }
        scanf("%c",&ch);
        i++;
            
    }
    return 0;
}
