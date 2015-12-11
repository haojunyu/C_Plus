///@file    exer17_2.c
///@brief   Coursera上C语言进阶课程第五周第二题：二维数组右上左下遍历
///@author  hjy

#include<stdio.h>

#define MAX 100
int mat[MAX][MAX];

int main(){
    int r,c;
    scanf("%d %d",&r,&c);

    int i,j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    for(i=0; i<r+c-1; i++){
        for(j=0; j<r+c-1; j++){
            if(j<r && i-j>=0 && i-j<c)
                printf("%d\n",mat[j][i-j]);
        }
    }

    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

