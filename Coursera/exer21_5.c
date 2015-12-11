///@file    exer21_5.c
///@brief   Coursera上C语言进阶课程第九周第五题：走出迷宫
///@author  hjy

#include<stdio.h>

char mat[100][100];

int main(){
    int i,j,n,m;
    scanf("%d %d",&n,&m);

    getchar();      // 吸收末尾的\n
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            scanf("%c",&mat[i][j]);
        }
        getchar();
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}


///@brief   求整数中包含多少个3
///@param   整数
///@return  返回整数中3的个数
