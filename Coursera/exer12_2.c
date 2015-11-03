///@file    exer12_2.c
///@brief   能被3,5,7整除的数
///@author  hjy

#include<stdio.h>

int main(){
    int num,ans=1;
    while(scanf("%d",&num)!=EOF){
        int flag=0;
        if(num%3==0){
            printf("3");
            flag=1;
        }
        if(num%5==0){
            if(flag)
                printf(" ");
            printf("5");
            flag=1;
        }
        if(num%7==0){
            if(flag)
                printf(" ");
            printf("7");
            flag=1;
        }
        if(flag)
            printf("\n");
        else
            printf("n\n");
    }
    
    return 0;
}



