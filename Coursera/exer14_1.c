///@file    exer14_1.c
///@brief   Coursera上C语言进阶课程第二周第一题
///@author  hjy

#include<stdio.h>

int arr[100];

int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]==i){
            printf("%d\n",i);
            break;
        }
    }
    if(i==n)
        printf("N\n");
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

