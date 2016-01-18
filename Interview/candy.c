///@file    c.c
///@brief   c程序的模板文件
///@author  hjy

#include<stdio.h>

int equal(int arr[]){
    int i;
    for(i=0;i<9;i++){
        if(arr[i]!=arr[0])
            break;
    }
    if(i==9)
        return 1;
    else
        return 0;
}
int main(){
    /* int arr[10]={18,3,8,22,16,4,10,6,15,20}; */
    int arr[10]={20,15,6,10,4,16,22,8,3,18};
    int counts=0;

    while(!equal(arr)){
        int i,tmp=arr[9];
        for(i=0;i<10;i++){
            int t=arr[i];
            arr[i]=arr[i]/2+(tmp+1)/2;
            tmp=t;
        }
        counts++;
    }
    
    printf("%d\n",counts);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

