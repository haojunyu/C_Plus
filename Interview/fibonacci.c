///@file    c.c
///@brief   c程序的模板文件
///@author  hjy

#include<stdio.h>
#include<string.h>

long f[5000];
long Fab(long n){
    if(n==0)
        return 0;
    else if(n==1){
        f[1]=1;
        return 1;
    }else{
        if(f[n]!=0)
            return f[n];
        else
            return Fab(n-1)+Fab(n-2);
    }
}
int main(){
    long long a=0,b=1;
    int i;
    for(i=2;i<=100;i++){
        long long tmp=a+b;
        a=b;
        b=tmp;
        printf("%d=%lld\n",i,tmp);
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

