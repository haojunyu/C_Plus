///@file    exer8_1.c
///@brief   Coursera上C语言课程第八周第一题
///@author  hjy

#include<stdio.h>

int main(){
    int key,tmp,i;
    int sum=0;
    scanf("%d",&key);
    
    for(i=0; i<5; i++){
        scanf("%d",&tmp);
        if(key>tmp)
            sum+=tmp;
    }

    printf("%d\n",sum);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

