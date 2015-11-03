///@file    selfinc.c
///@brief   自增的例子
///@author  hjy

#include<stdio.h>

int main(){
    int i=1;
    printf("i = %d\n",i);
    printf("i++ = %d\n",i++);
    printf("i = %d\n",i);
    printf("++i = %d\n",++i);
    printf("i = %d\n",i);
    
    // error: lvalue required as increment operand
    //printf("(-i)++ = %d\n",(-i)++);
    //printf("++i++ = %d\n",++i++);

    // 输出多个自增
    printf("i = %d, i++ =%d\n",i,i++);
    printf("i = %d\n",i);
    printf("i++ = %d, ++i =%d\n",i,++i);
    printf("i = %d\n",i);

    // 可以运行
    printf("%d\n",256>>1);
    
    // 混合计算
    short s=2;
    int j=3;
    float f=4.5;
    double d=6.7;
    unsigned u=8;
    printf("%f\n",123%s+(j+'a')+j*u-f/d);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

