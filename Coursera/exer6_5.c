///@file    exer6_5.c
///@brief   分离整数的各个数位
///@author  hjy

#include<stdio.h>


int main(){
    int tmp,g,s,b;
    while(scanf("%d",&tmp)!=EOF){
        b=tmp/100;
        s=(tmp-100*b)/10;
        g=tmp-100*b-10*s;
        printf("%d\n",b);
        printf("%d\n",s);
        printf("%d\n",g);
    }
    
    return 0;
}


