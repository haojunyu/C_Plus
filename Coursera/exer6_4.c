///@file    exer6_4.c
///@brief   最大奇数与最小偶数之差的绝对值
///@author  hjy

#include<stdio.h>


int main(){
    int tmp,ans=0;
    int min=100,max=0;
    int i=0;
    while(scanf("%d",&tmp)!=EOF){
        if(tmp%2==0 && min>tmp)
            min=tmp;
        if(tmp%2==1 && max<tmp)
            max=tmp;
        i++;
        if(i==6){
            if(min>max)
                printf("%d\n",min-max);
            else
                printf("%d\n",max-min);
            i=0;
            min=100;
            max=0;
        }
    }
    
    return 0;
}


