/*
 × 两种思路实现Partition，不过第二种更容易理解点 
 */
		
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int arr[1000001];

void Swap(int a, int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

/*
int Partition(int start, int end){
	int i,small;
	// random position
	int base = (rand()%(end-start+1))+start;

	Swap(base, end);
	small = start-1;
	for(i=start; i<end; i++){
		if(arr[i]<arr[end]){
			++small;
			if(small != i)
				Swap(small, i);
		}
	}
	++small;
	Swap(small, end);
	
	return small;

}
*/

int Partition(int start, int end){
	int first,last,key;
	// random position
	int base = (rand()%(end-start+1))+start;
	Swap(base, start);

	first = start;
	last = end;
	key = arr[first];

	while(first < last){
		//find the number smaller than key from end to begin 
		while(first<last && arr[last]>=key)
			last--;
		arr[first] = arr[last];
		//find the number bigger than key from begin to end
		while(first<last && arr[first]<=key)
			first++;
		arr[last] = arr[first];
	}
	arr[first] = key;
	
	return last;
}
void Quicksort(int start, int end){
	if(start<0 || end<0 || end<=start)
		return;
//	else if(end == start+1){
//		if(arr[start]>arr[end]){
			// increase order
//			Swap(start, end);
//		}
//	}
	else{
		int mid = Partition(start, end);
		Quicksort(start,mid-1);
		Quicksort(mid+1,end);
	}

}


int main(){
    freopen("in.txt","r",stdin);                  
     
    int num,i,res;

    while(scanf("%d",&num) != EOF){
        for(i=0; i<num; i++)
            scanf("%d",&arr[i]);
       
	    // show original data
		printf("input data:\n");
		for(i=0; i<num; i++)
			printf("%d ",arr[i]);
		printf("\n");
		// deal with data
		Quicksort(0,num-1);	
		//printf("%d",rand());

		// output
		for(i=0; i<num; i++)
			printf("%d ",arr[i]);
		printf("\n\n");
    }
}

