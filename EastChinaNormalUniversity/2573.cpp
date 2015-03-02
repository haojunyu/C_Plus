//WRONG ANSWER
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


//define the struct
struct edge
{
	int u;																//the begin vertex of the edge
	int v;																//the end vertex of the edge
	int w;																//the weight of the edge
};

int CompPrice(const void *a,const void *b);
int Kruskal(edge e[], int n);
	
int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream

	int hubCount,connection;
	int i;

	scanf("%d%d",&hubCount,&connection);
	edge *hubPrice=new edge[connection];
	for(i=0;i<connection;i++)
	{
		scanf("%d%d%d",&hubPrice[i].u,&hubPrice[i].v,&hubPrice[i].w);
	}

    qsort(hubPrice,connection,sizeof(edge),CompPrice);

	printf("%d",Kruskal(hubPrice,hubCount));
		
	delete hubPrice;
}



/*
 * desc:	qsort的比较函数,以结构体中的price为比较对象,递增
 * pars:	void a,b --要比较的两个值
 * ret:		int --比较的结果
 */
 int CompPrice(const void *a,const void *b)
 {
		return ((edge*)a)->w-((edge*)b)->w;
 }
 
 
 
/*
 * desc:	用kruskal求最小生成树的最小权值和
 * pars:	edge e[] 	-- 所有边的信息
 * 			int n		-- 图的节点数
 * ret:		int --最小生成树的最小权值和
 */
 int Kruskal(edge e[], int n)										
 {
	 int i,j,k;
	 int u,v,setu,setv;
	 int *sets=new int[n]; 												//define the set
	 int weightSum=0;
	 
	 for(i=0; i<n; i++)													//initialize the set--every vertex present a set 
	 {
		 sets[i]=i;
	 }
	 
	 j=0;																//j -- the index of the edges
	 i=1;																//i -- the index of the vertex
	 while(i<n)
	 {
		 u=e[j].u;
		 v=e[j].v;
		 setu=sets[u];
		 setv=sets[v];
		 
		 if(setu != setv)												//the two vertex of the edge are in different sets
		 {
			 //printf("\n边(%d,%d)的权为:%d",u,v,e[j].w);
			 weightSum=weightSum+e[j].w;
			 i++;
			 for(k=0; k<n; k++)											//merge the different sets
			 {
				 if(sets[k] == setu)
					sets[k]=setv;
			 }							
		 }
		 j++;
	 }
	 
	 delete sets;
	 return weightSum;
 }
 
