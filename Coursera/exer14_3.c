///@file    exer14_3.c
///@brief   Coursera上C语言进阶课程第二周第三题
///@author  hjy

#include<stdio.h>
#include<string.h>
float id[4];
float fp[4];

int main(){
    int i,n,j,k;
    memset(id,0,sizeof(id));
    memset(fp,0,sizeof(fp));
    for(k=0;k<3;k++){
        scanf("%d %d",&i,&n);
        for(j=0;j<n;j++){
            char c;
            float money;
            scanf(" %c %f",&c,&money);
            id[i]+=money;
            fp[c-'A'+1]+=money;
        }
    }
    for(k=1;k<4;k++){
        printf("%d %.2f\n",k,id[k]);
    }
    for(k=1;k<4;k++){
        printf("%c %.2f\n",k-1+'A',fp[k]);
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

