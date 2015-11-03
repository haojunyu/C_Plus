///@file    exer10_4.c
///@brief   矩阵交换行
///@author  hjy

#include<stdio.h>


int main(){
    int mat[5][5];
    int n,m,i,j,tmp;
    while(scanf("%d %d %d %d %d",&mat[0][0],&mat[0][1],&mat[0][2],&mat[0][3],&mat[0][4])!=EOF){
        for(i=1;i<5;i++)
            scanf("%d %d %d %d %d",&mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3],&mat[i][4]);
        scanf("%d %d",&n,&m);
        if(n>4||n<0||m>4||m<0)
            printf("error\n");
        else{
            for(i=0;i<5;i++){
                tmp=mat[n][i];
                mat[n][i]=mat[m][i];
                mat[m][i]=tmp;
            }
            for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    printf("%4d",mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}



