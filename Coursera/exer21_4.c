///@file    exer21_4.c
///@brief   Coursera上C语言进阶课程第九周第四题：寻找平面上的极大点
///@author  hjy

#include<stdio.h>
#include<stdlib.h>

typedef struct point{
    int x;
    int y;
}spoint;

int comp(const void *a, const void *b);

int main(){
    int n,i;
    scanf("%d",&n);
    
    spoint *points=(spoint *)malloc(sizeof(spoint)*n);

    for(i=0; i<n; i++){
        scanf("%d %d",&points[i].x,&points[i].y);
    }
    
    qsort(points,n,sizeof(spoint),comp);
    
    printf("(%d,%d)",points[0].x,points[0].y);
    int tmp=points[0].x;
    for(i=1; i<n; i++){
        if(points[i].x>tmp){
            printf(",(%d,%d)",points[i].x,points[i].y);
            tmp=points[i].x;
        }
    }
    printf("\n");
    free(points);
    
    return 0;
}


///@brief   求整数中包含多少个3
///@param   整数
///@return  返回整数中3的个数
int comp(const void *a, const void *b){
    int tmp = (*(spoint *)a).y - (*(spoint *)b).y;
    if(tmp!=0)
        return -tmp;
    else
        return (*(spoint *)a).x - (*(spoint *)b).x;
}
