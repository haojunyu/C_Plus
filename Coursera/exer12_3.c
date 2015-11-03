///@file    exer12_3.c
///@brief   最远距离
///@author  hjy

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point{
    double x;
    double y;
}spoint;

int main(){
    int i,j,num;
    double x,y;
    scanf("%d",&num);
    spoint *points=(spoint *)malloc(sizeof(spoint)*num);

    for(i=0;i<num;i++){
        scanf("%lf %lf",&(points[i].x),&(points[i].y));
        /* printf("%lf %lf\n",points[i].x,points[i].y); */
    }
    
    double dis=0;
    for(i=0; i<num-1; i++){
        for(j=i+1; j<num; j++){
            double tmp=pow(points[i].x-points[j].x,2)+pow(points[i].y-points[j].y,2);
            if(tmp>dis)
                dis=tmp;
        }
    }
    printf("%.4lf\n",sqrt(dis));
    return 0;
}



