///@file    exer10_7.c
///@brief   中位数,思路对了，但是wa
///@author  hjy

#include<stdio.h>

int arr[15000];

int Partition(int *arr, int beg, int end);
int QuickSort(int *arr, int beg, int end, int k);

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        if(N==0)
            break;
        int i;
        for(i=0;i<N;i++){
            scanf("%d",&arr[i]);
        }
        int ans=0;
        if(N%2==1)
            ans=QuickSort(arr,0,N-1,(N-1)/2);
        else{
            ans+=QuickSort(arr,0,N-1,N/2);
            ans+=QuickSort(arr,0,N-1,N/2-1);
            ans/=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}


///@brief   快排算法中重排数组函数
///@param   arr 存放数据的数组
///@param   beg 数组的起始位置
///@param   end 数组的末尾位置
///@return  返回轴枢元素（第一个）的位置
///@see     QuickSort的Partition
///note     这步与k无关
int Partition(int *arr, int beg, int end){
    int key=arr[beg];
    int i=beg,j=end;

    while(i<j){
        while(i<j&&key<=arr[j])
            j--;
        arr[i]=arr[j];
        while(i<j&&key>=arr[i])
            i++;
        arr[j]=arr[i];
    }
    arr[i]=key;
    return i;
}





///@brief   改动的快排算法
///@param   arr 存放数据的数组
///@param   beg 数组的起始位置
///@param   end 数组的末尾位置
///@param   k   所要找的第k位置
///@return  返回第k位置的数值
///@see     QuickSort
///note     k不需要随着递归进行而变动
int QuickSort(int *arr, int beg, int end, int k){
    if(beg<end&&beg>=0&&end>=0){
        int index=Partition(arr,beg,end);
        if(index==k)
            return arr[k];
        else if(index>k)
            return QuickSort(arr,beg,index-1,k);
        else
            return QuickSort(arr,index+1,end,k);
    }else
        return -1;
}
