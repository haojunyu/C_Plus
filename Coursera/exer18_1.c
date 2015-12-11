///@file    exer18_1.c
///@brief   Coursera上C语言进阶课程第六周第一题：分配病房
///@author  hjy

#include<stdio.h>
#include<stdlib.h>

typedef struct patient{
    int id;
    double serice;
}spa;

spa patients[50];

int comp(const void *a, const void *b);

int main(){
    int i,m,n=0;
    double ser;
    scanf("%d %lf",&m,&ser);

    for(i=0;i<m;i++){
        int id;
        double s;
        scanf("%d %lf",&id,&s);
        if(s>ser){
            patients[n].id=id;
            patients[n++].serice=s;
        }
    }
    if(n==0)
        printf("None.\n");
    else{
        qsort(patients,n,sizeof(spa),comp);
        for(i=n-1;i>=0;i--)
            printf("%03d %.1f\n",patients[i].id,patients[i].serice);
    }
    return 0;
}


///@brief   比较函数
///@param   a   对象a
///@param   b   对象b
///@return  返回比较的数值
///note     这里要比较的是double型的，不可直接返回。
int comp(const void *a, const void *b){
    double tmp = (*(spa *)a).serice - (*(spa *)b).serice;
    if(tmp==0)
        return 0;
    else if(tmp>0)
        return 1;
    else
        return -1;
}
