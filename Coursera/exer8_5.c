///@file    exer8_5.c
///@brief   Coursera上C语言课程第八周第五题
///@author  hjy

#include<stdio.h>
#include<string.h>

int data[100];

int main(){
    int N;
    int i,sum=10;
    memset(data,0,sizeof(data));
    scanf("%d",&N);
    for(i=10; i<99; i++){
        if(i%10==0)
            sum=sum-9;
        if(i%sum==0)
            data[i]=1;
        else
            data[i]=0;
        sum++;
    }
    for(i=10; i<N; i++){
        if(data[i]==1)
            printf("%d\n",i);
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

