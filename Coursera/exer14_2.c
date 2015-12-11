///@file    exer14_2.c
///@brief   Coursera上C语言进阶课程第二周第二题
///@author  hjy

#include<stdio.h>

int main(){
    int i,j,k,m;
    for(i=1;i<5;i++){
        for(j=1;j<5;j++){
            if(i==j)
                continue;
            for(k=1;k<5;k++){
                if(i==k || j==k)
                    continue;
                for(m=1;m<5;m++){
                    if(m==i || m==j || m==k)
                        continue;
                    int a=(j==1)+(m==4)+(i==3);
                    int b=(m==1)+(j==4)+(i==2)+(k==3);
                    int c=(m==4)+(j==3);
                    int d=(i==1)+(k==4)+(m==2)+(j==3);
                    if(a==1&&b==1&&c==1&&d==1){
                        printf("%d\n",i);
                        printf("%d\n",j);
                        printf("%d\n",k);
                        printf("%d\n",m);
                    }
                }
            }
        }
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

