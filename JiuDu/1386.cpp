/*
 * 本题的点在于要用logn的时间复杂度（二分查找法），而在使用二分查找法时，要
 × 注意样本的特例1。完全有序  2.只有一个元素 3.有多个重复的元素
 */
		
#include<iostream>
#include<stdio.h>
using namespace std;

int arr[1000001];

int FindMin(int start, int end){
	// left two numbers
	if(start == end-1)
		return arr[end];

	int mid = (start + end)/2;
	if(arr[start]==arr[mid] && arr[mid]==arr[end]){
		//special case -- traversal
		int i;
		for(i=start; i<end; i++){
			if(arr[i]>arr[i+1])
				return arr[i+1];
		}
	}else if(arr[mid] > arr[start])
		return FindMin(mid, end);
	else
		return FindMin(start, mid);
}

int main(){
    freopen("in.txt","r",stdin);                  
     
    int num,i,res;

    while(scanf("%d",&num) != EOF){
        for(i=0; i<num; i++)
            scanf("%d",&arr[i]);
        
		// deal with data
		if(num==1 || arr[0] < arr[num-1])
			res = arr[0];
		else
			res = FindMin(0, num-1);
		printf("%d\n",res);
		// output
		for(i=0; i<num; i++)
			printf("%d ",arr[i]);
		printf("\n");
    }
}

