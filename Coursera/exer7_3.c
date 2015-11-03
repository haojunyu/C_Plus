///@file    exer7_3.c
///@brief   Coursera上C语言课程第七周第三题:找第k大的数
///@author  hjy

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int Partition(int arr[], int begin, int end);
int FindKth(int arr[],int begin,int end,int k);

int main(){
    /* freopen("in.txt","r",stdin); */
    int n,k,i;
    int *arr;

    scanf("%d",&n);
    scanf("%d",&k);

    arr=(int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    int res=FindKth(arr,0,n-1,k-1);

    printf("%d\n",res);



    free(arr);    
    return 0;
}


///@brief   以第一个元素为轴枢，将其放到最终的位置
///@param   arr[]   存放元素的数组
///@param   begin   重排的开始位置
///@param   end     重排的结束位置
///@return  第一个元素所在的位置
///note     在快排的基础上改进
int Partition(int arr[], int begin, int end){
    int key=arr[begin];
    while(begin<end){
        while(begin<end && arr[end]<=key)
            end--;
        arr[begin]=arr[end];
        while(begin<end && arr[begin]>=key)
            begin++;
        arr[end]=arr[begin];
    }
    arr[begin]=key;

    return begin;
}

///@brief   查找数组中第k大元素
///@param   arr[]   存放元素的数组
///@param   k       第k大元素
///@return  第k大元素数值
///note     在快排的基础上改进
int FindKth(int arr[], int begin, int end, int k){
    if(begin<0 || end<0 || end<begin)
        return -1;
    else{
        int mid=Partition(arr,begin,end);
        if(mid==k)
            return arr[k];
        else if(mid>k)
            return FindKth(arr,begin,mid-1,k);
        else
            return FindKth(arr,mid+1,end,k);
    }
}
