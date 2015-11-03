///@file    exer7_2.c
///@brief   Coursera上C语言课程第二题
///@author  hjy

#include<stdio.h>

int main(){
    int n;

    scanf("%d",&n);

    if(n<60)
        printf("7\n");
    else if(n<70)
        printf("6\n");
    else if(n<80)
        printf("5\n");
    else if(n<85)
        printf("4\n");
    else if(n<90)
        printf("3\n");
    else if(n<95)
        printf("2\n");
    else
        printf("1\n");
    
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

