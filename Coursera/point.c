///@file    point.c
///@brief   指针的试验
///@author  hjy

#include<stdio.h>

int main(){
    int a[4]={1,2,3,4};
    printf("%p\n",a);       //x
    printf("%p\n",a+1);     //x+4
    printf("%p\n",&a);      //x
    printf("%p\n",&a+1);    //x+16
    printf("%p\n",*(&a));   //x
    printf("%p\n",*(&a)+1); //x+4
    printf("\n");

    int b[2][3]={{1,2,3},{4,5,6}};
    printf("%p\n",b);       //x
    printf("%p\n",b+1);     //x+12
    printf("%p\n",&b);      //x
    printf("%p\n",&b+1);    //x+24
    printf("%p\n",*(&b));   //x
    printf("%p\n",*(&b)+1); //x+12
    printf("%p\n",b[0]);    //x
    printf("%p\n",b[0]+1);  //x+4
    printf("%p\n",&b[0]);   //x
    printf("%p\n",&b[0]+1); //x+12
    printf("%p\n",*(&b[0]));    //x
    printf("%p\n",*(&b[0])+1);  //x+4
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

