///@file    exer8_4.c
///@brief   Coursera上C语言课程第八周第四题
///@author  hjy

#include<stdio.h>

int data[1000];

int main(){
    int N,K;
    int i,j,flag=0;
    scanf("%d %d",&N,&K);
    for(i=0; i<N; i++){
        scanf("%d",&data[i]);
    }
   for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            if(data[i]+data[j]==K){
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

