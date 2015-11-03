///@file    exer8_3.c
///@brief   Coursera上C语言课程第八周第三题
///@author  hjy

#include<stdio.h>
#include<math.h>

int main(){
    int N,K;

    while(scanf("%d %d",&N,&K)!=EOF){
        /* printf("%d %d\n",N,K); */
        double fang,gz;
        int flag=0;
        
        int i;
        for(i=0; i<20; i++){
            fang=200*pow(1+K/100.0,i);
            gz=N*(i+1);
            if(fang<gz){
                flag=1;
                break;
            }
        }
        if(flag)
            printf("%d\n",i+1);
        else
            printf("Impossible\n");
    }
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

