///@file    exer15_3.c
///@brief   Coursera上C语言进阶课程第三周第三题：排队游戏
///@author  hjy

#include<stdio.h>
#include<string.h>

int flag;
int Paidui(const char *arr,int n);

int main(){
    char arr[100];
    scanf("%s",arr);
    
   if(Paidui(arr,0)==-1&&flag)
        printf("success!\n");
    else
        printf("输入error。\n");
    return 0;
}


///@brief   括号的匹配，并输出匹配的位置索引
///@param   arr    参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题
int Paidui(const char *arr, int n){
    if(strlen(arr)==n){
        flag = 1;
        return -1;
    }else{
        if(arr[n]=='('){
            int pos = Paidui(arr,n+1);
            if(flag){
                if(arr[pos]==')'){
                    printf("%d %d\n",n,pos);
                    flag = 1;
                    return Paidui(arr,pos+1);
                }else{
                    flag = 0;
                    return n;
                }
            }else{
                flag = 0;
                return n;
            }
        }else if(arr[n]==')'){
            flag = 1;
            return n;
        }else{
            flag = 1;
            return Paidui(arr,n+1);
        }
    }
}


