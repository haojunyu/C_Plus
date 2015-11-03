///@file    exer6_1.c
///@brief   苹果和虫子
///@author  hjy

#include<stdio.h>

int main(){
    int n,x,y,tmp;

    while(scanf("%d %d %d",&n,&x,&y)!=EOF){
        if(y%x==0)
            tmp=y/x;
        else
            tmp=y/x+1;
        if(n>=tmp)
            printf("%d\n",n-tmp);
        else
            printf("0\n");
    }
    
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

