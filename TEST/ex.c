///@file    exer14_4.c
///@brief   Coursera上C语言进阶课程第二周第四题
///@author  hjy

#include<stdio.h>

int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    int y,m,d;
    scanf("%d-%d-%d",&y,&m,&d);
    int flag=0,add;
    scanf("%d",&add);
    if((y%4==0&&y%100!=0) || (y%400==0))
        flag=1;
    if(d+add>days[m]-flag){
        d=d+add-days[m]+flag;
        m++;
        if(m>12){
            m=1;
            y++;
        }
    }else
        d=d+add;
    printf("%d-%02d-%02d\n",y,m,d);
    
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

