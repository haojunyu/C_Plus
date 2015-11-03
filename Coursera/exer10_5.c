///@file    exer10_5.c
///@brief   异常细胞检测
///@author  hjy

#include<stdio.h>

int mat[100][100];

int main(){
    int N,i,j;
    // input
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int counts=0;
    for(i=1;i<N-1;i++){
        for(j=1;j<N-1;j++){
            int num=(mat[i-1][j]-mat[i][j])>=50;
            num+=(mat[i+1][j]-mat[i][j])>=50;
            num+=(mat[i][j-1]-mat[i][j])>=50;
            num+=(mat[i][j+1]-mat[i][j])>=50;
            if(num==4)
                counts++;
        }
    }
    printf("%d\n",counts);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

