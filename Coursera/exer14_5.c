///@file    exer14_5.c
///@brief   Coursera上C语言进阶课程第二周第五题
///@author  hjy

#include<stdio.h>
#include<stdlib.h>

typedef struct cir{
    int id;
    double rate;
}scir;

scir cirs[100];
int comp(const void *a, const void *b){
    return (*(scir *)b).rate-(*(scir *)a).rate;
}

int main(){
    int i,n;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        int a,b;
        scanf("%d %d %d",&cirs[i].id,&a,&b);
        cirs[i].rate=(double)b/a;
    }
    qsort(cirs,n,sizeof(scir),comp);

    double maxrate=0;
    int maxind=0;
    for(i=0;i<n-1;i++){
        double diff=cirs[i].rate-cirs[i+1].rate;
        if(diff>maxrate){
            maxrate=diff;
            maxind=i;
        }
    }
    // cout A
    printf("%d\n",maxind+1);
    for(i=maxind;i>=0;i--)
        printf("%d\n",cirs[i].id);
    // cout B
    printf("%d\n",n-maxind-1);
    for(i=n-1;i>maxind;i--)
        printf("%d\n",cirs[i].id);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

