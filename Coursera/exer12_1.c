///@file    exer12_1.c
///@brief   判断闰年(能被4整除的大多数是闰年，但能被100整除但不能被400整除的不是闰年，能被3200整除的也不是闰年)
///@author  hjy

#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);

    if((a%4 == 0 && a%100 != 0)||(a%400==0 && a%3200 != 0))
        printf("Y\n");
    else
        printf("N\n");
    
    return 0;
}



