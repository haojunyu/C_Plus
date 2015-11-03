///@file    exer10_6.c
///@brief   循环移动[前n-k逆序，后k逆序，全部逆序]
///@author  hjy

#include<stdio.h>
#include<stdlib.h>

void Reverse(int *arr, int beg, int end);

int main(){
    int i;
    int n,m;
    scanf("%d %d",&n,&m);

    int *arr=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    Reverse(arr,0,n-m-1);
    Reverse(arr,n-m,n-1);
    Reverse(arr,0,n-1);

    for(i=0;i<n-1;i++)
        printf("%d ",arr[i]);
    printf("%d\n",arr[n-1]);
    return 0;
}


///@brief   将数组中beg-end首尾互换
///@param   arr 数组
///@param   beg 开始位置
///@param   end 结束位置
///@return  空
///note     从arr[beg]开始，到arr[end]结束，包括自身
void Reverse(int *arr, int beg, int end){
    int tmp,i,j;
    i=beg;
    j=end;
    while(i<j){
        tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        i++;
        j--;
    }
}


