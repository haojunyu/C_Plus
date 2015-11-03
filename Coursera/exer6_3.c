///@file    exer6_3.c
///@brief   最高的分数
///@author  hjy

#include<stdio.h>


int main(){
    int num,i,tmp,ans=0;

    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&tmp);
        if(ans<tmp)
            ans=tmp;
    }
    printf("%d\n",ans);
    
    return 0;
}


