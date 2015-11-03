///@file    exer7_4.c
///@brief   Coursera上C语言课程第七周第四题
///@author  hjy

#include<stdio.h>

#define LEN 6

int main(){
    int n,i;

    scanf("%d",&n);
    int arr[LEN]={100,50,20,10,5,1};
    for(i=0; i<LEN; i++){
        printf("%d\n",n/arr[i]);
        n=n-n/arr[i]*arr[i];
    
    }

    return 0;
}


