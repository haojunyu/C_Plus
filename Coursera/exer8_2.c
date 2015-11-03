///@file    exer8_2.c
///@brief   Coursera上C语言课程第八周第二题
///@author  hjy

#include<stdio.h>

int main(){
    int n;
    int tmp,i;
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        scanf("%d",&tmp);
        if(tmp>100)
            printf("Bike\n");
        else if(tmp<100)
            printf("Walk\n");
        else
            printf("All\n");
    }

    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

