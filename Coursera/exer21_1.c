///@file    exer21_1.c
///@brief   Coursera上C语言进阶课程第九周第一题：含k个3的数
///@author  hjy

#include<stdio.h>

int numof3(int m);

int main(){
    int m,k;
    scanf("%d %d",&m,&k);
    
    if(m%19==0 && numof3(m)==k)
        printf("YES\n");
    else
        printf("NO\n");
 
    return 0;
}


///@brief   求整数中包含多少个3
///@param   整数
///@return  返回整数中3的个数
int numof3(int m){
    int i=0,tmp;
    
    while(m!=0){
        tmp=m%10;
        if(tmp==3)
            i++;
        m=(m-tmp)/10;
    }
    
    return i;

}
