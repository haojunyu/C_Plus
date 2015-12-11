///@file    exer14_6.c
///@brief   Coursera上C语言进阶课程第二周第六题
///@author  hjy

#include<stdio.h>

char mat[100][100];

int main(){
    int i,j,n;
    scanf("%d",&n);
    getchar();

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%c",&mat[i][j]);
        }
        getchar();
    }
    int k=1,m;
    scanf("%d",&m);
    while(k<m){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(mat[i][j]=='@'){
                    if(i-1>=0&&mat[i-1][j]=='.')
                        mat[i-1][j]='@'+10;
                    if(i+1<n&&mat[i+1][j]=='.')
                        mat[i+1][j]='@'+10;
                    if(j-1>=0&&mat[i][j-1]=='.')
                        mat[i][j-1]='@'+10;
                    if(j+1<n&&mat[i][j+1]=='.')
                        mat[i][j+1]='@'+10;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(mat[i][j]=='@'+10)
                    mat[i][j]-=10;
            }
        }
        k++;
    }
    int ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]=='@')
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

