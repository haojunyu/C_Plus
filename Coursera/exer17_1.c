///@file    exer17_1.c
///@brief   Coursera上C语言进阶课程第五周第一题：计算矩阵边缘元素
///@author  hjy

#include<stdio.h>

#define MAX 100
int mat[MAX][MAX];

int main(){
    int k,K;
    scanf("%d",&K);
    
    for(k=0;k<K;k++){
        int row,col;
        scanf("%d %d",&row,&col);

        int i,j;
        for(i=0; i<row; i++){
            for(j=0; j<col; j++){
                scanf("%d",&mat[i][j]);
            }
        }
        
        // calculation
        int sum=0;
        for(i=0;i<col;i++)
            sum+=mat[0][i]+mat[row-1][i];
        for(j=0;j<row;j++)
            sum+=mat[j][0]+mat[j][col-1];
        sum-=(mat[0][0]+mat[0][col-1]+mat[row-1][0]+mat[row-1][col-1]);
        
        // output
        printf("%d\n",sum);
    

    }

    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

