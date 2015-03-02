#include<iostream>
#include<stdio.h>
using namespace std;

int arr[1001][1001];

int FindTarget(int row, int col, int target){
	int i=row-1,j=0;

	while(i>=0 && j<col){
		if(arr[i][j]==target)
			break;
		if(arr[i][j]<target)
			j++;
		else
			i--;
	}
	
	if(arr[i][j]==target)
		return 1;
	else 
		return 0;
};

int main(){
	//freopen("in.txt","r",stdin);						
	
	int m,n,target;
	int i,j;
	while(scanf("%d %d",&m,&n)!=EOF){
		scanf("%d",&target);
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				scanf("%d",&arr[i][j]);
			}
		}
	
		/*
		// show input data
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		*/

		int status = FindTarget(m,n,target);

		if(status == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
