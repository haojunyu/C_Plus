///@file    exer6_2.c
///@brief   大象喝水
///@author  hjy

#include<stdio.h>
#include<math.h>

int main(){
    int h,r;

    while(scanf("%d %d",&h,&r)!=EOF){
        double v=M_PI*r*r*h;
        printf("%d\n",1+(int)(20000.0/v));
    }
    
    return 0;
}


