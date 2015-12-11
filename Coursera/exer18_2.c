///@file    exer18_2.c
///@brief   Coursera上C语言进阶课程第六周第二题：配对碱基链
///@author  hjy

#include<stdio.h>

char str[256];

int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",str);
        int j;
        for(j=0;str[j]!='\0';j++){
            switch(str[j]){
                case 'A':
                    printf("T");
                    break;
                case 'T':
                    printf("A");
                    break;
                case 'G':
                    printf("C");
                    break;
                case 'C':
                    printf("G");
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

