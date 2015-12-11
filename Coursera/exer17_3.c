///@file    exer17_3.c
///@brief   Coursera上C语言进阶课程第五周第三题：文字排版
///@author  hjy

#include<stdio.h>
#include<string.h>

char word[40];


int main(){
    int N;
    scanf("%d",&N);

    int i,sum=0;
    for(i=0; i<N; i++){
        scanf("%s",word);
        sum+=strlen(word);
        if(sum<81){
            printf("%s",word);
            if(!(sum==80 || i==N-1)){
                printf(" ");
                sum++;
            }
        }else{
            int j;
            for(j=0;j<80-(sum-strlen(word));j++){
                printf("%c",word[j]);
            }
            printf("\n");
            sum=strlen(word)-j+1;
            for(;j<strlen(word); j++)
                printf("%c",word[j]);
            printf(" ");
        }
    }

    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

