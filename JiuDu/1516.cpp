/**
 * 本题的变换版本比较多，主要分为是否保持原有的相对位置不变。除此之外，会对
 * 时间复杂度和空间复杂度作限制。剑指offer上是不要求保持原有的相对位置不变，
 * 其解法见[arrange]，而九度上编程是要求保持原有的相对位置不变。这里给出了
 * 三种解法，第一种是借用O(n)数组空间[rearrange1],第二种是不借用数组空间，
 * 不过时间复杂度达到了o（n×n）[rearrange2]，第三种是模仿归并排序的思想，
 * 也不借用数组空间，时间复杂度是O（nlogn）[rearrange]，其中，只有第二种
 * 解法是在九度上通不过的,原因是最后一组测试数据超时。
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[100];


// 无需保持原有的相对位置不变
// 时间复杂度为O（n），空间复杂度为o（1）
void arrange(int start, int end){
	int i,j;
	j=start-1;
	for(i=start; i<=end; i++){
		if(arr[i]%2==1){
			j++;
			int tmp;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
}

// 保持原来相对位置不变
// 时间复杂度为o（n），空间复杂度o（n）
void rearrange1(int start, int end){
	int i,j=start;
	int *narr = (int *)malloc(sizeof(int)*(end-start+1));
	memcpy(narr,arr,sizeof(int)*(end-start+1));
	
	for(i=start; i<=end; i++ ){
		if(narr[i]%2 == 1)
			arr[j++] = narr[i];
	}
	for(i=start; i<=end; i++ ){
		if(narr[i]%2 == 0)
			arr[j++] = narr[i];
	}

	free(narr);

}


// 时间复杂度为O(n×n)，空间复杂度O（1），在arrange的基础上修改
void rearrange2(int start, int end){
	int i,j,k;
	j=start-1;
	for(i=start; i<=end; i++){
		if(arr[i]%2==1){
			j++;
			int tmp = arr[i];
			for(k=i; k>j; k--)
				arr[k] = arr[k-1];
			arr[k] = tmp;
		}
	}
	
}


//时间复杂度接近O（nlogn），空间复杂度O（1）
void swap(int start, int end){
	int i,j;
	for(i=start,j=end; i<j; i++,j--){
		int tmp;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

int rearrange(int start, int end){
	int mid,i,len;
	int front,back;
	
	len = 0;
	for(i=start; i<=end; i++){
		if(arr[i]%2==1)
			len++;
	}
	mid = start + len;

	if(len!=0&&len!=end-start+1){
		front = rearrange(start,mid-1);
		back = rearrange(mid,end)-1;

		swap(front,mid-1);
		swap(mid,back);
		swap(front,back);
	}

	return mid;
}

int main(){
	freopen("in.txt","r",stdin);

	int num,i;
	scanf("%d",&num);
	for(i=0; i<num; i++){
		scanf("%d",&arr[i]);
	}
	
	//arrange(0,num-1);
	//rearrange(0,num-1);
	//rearrange1(0,num-1);
	rearrange2(0,num-1);
	
	for(i=0; i<num-1; i++){
		printf("%d ",arr[i]);
	}
	printf("%d\n",arr[i]);

	return 0;
}
