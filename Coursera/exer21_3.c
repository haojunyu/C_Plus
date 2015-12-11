///@file    exer21_3.c
///@brief   Coursera上C语言进阶课程第九周第三题：运算符判定
///@author  hjy

#include<stdio.h>


int main(){
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);
    
    if(a+b==c)
        printf("+\n");
    else if(a-b==c)
        printf("-\n");
    else if(a*b==c)
        printf("*\n");
    else if(a/b==c)
        printf("/\n");
    else if(a%b==c)
        printf("%%\n");
    else
        printf("error\n");
 
    return 0;
}


///@brief   求整数中包含多少个3
///@param   整数
///@return  返回整数中3的个数
