///@file    exer18_3.c
///@brief   Coursera上C语言进阶课程第六周第三题：寻找山顶
///@author  hjy

#include<stdio.h>
#include<string.h>

int arr[25][25];

int main(){
    int i,j;
    int m,n;
    scanf("%d %d",&m,&n);
    
    memset(arr,0,sizeof(int)*m*n);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j]>=arr[i-1][j]&&arr[i][j]>=arr[i+1][j]&&arr[i][j]>=arr[i][j+1]&&arr[i][j]>=arr[i][j-1])
                printf("%d %d\n",i-1,j-1);
        }
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

