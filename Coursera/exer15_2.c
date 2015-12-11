///@file    exer15_2.c
///@brief   Coursera上C语言进阶课程第三周第二题：角骨猜想
///@author  hjy

#include<stdio.h>


void JiaoGu(int n);

int main(){
    int n;
    scanf("%d",&n);
    
    JiaoGu(n);

    return 0;
}


///@brief   角骨猜想
///@param   n   输入数据
///@return  空值
///@see     none
///note     1也是奇数
void JiaoGu(int n){
    if(n==1)
        printf("End\n");
    else if(n%2==1&&n!=1){
        printf("%d*3+1=%d\n",n,3*n+1);
        JiaoGu(3*n+1);
    }else{
        printf("%d/2=%d\n",n,n/2);
        JiaoGu(n/2);
    }
}
