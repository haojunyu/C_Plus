/*
 *可以通过负的根节点来记录集合包含的元素个数,以此来优化合并(小集合并到大集合)
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;



//并查集的数据存储
#define LENMAX 1000005
int father[LENMAX];


//并查集的查找操作
int Find(int x)
{
	if(x==father[x])
		return x;
	else
	{
		father[x]=Find(father[x]);		//压缩路径compress path
		return father[x];
	}	
}

//并查集的合并操作
void Union(int x,int y)
{
	int tmpX=Find(x);
	int tmpY=Find(y);

	if(tmpX!=tmpY)
		father[tmpX]=tmpY;
}


//初始化并查集
void InitFather()
{
	int i;
	for(i=0;i<LENMAX;i++)
		father[i]=i;
}



int main(){
	
	#ifdef LOCAL
		freopen("poj_1611_in.txt","r",stdin);		//redirect the input stream
		//freopen("out.txt","w",stdout);		//redirect the output stream
    #endif										
	
	int i,j;
	int n,m,num,count;
	int represent,individual;
	
	while(scanf("%d %d",&n,&m))
	{
		if(m==0&&n==0)
			break;
		
		InitFather();
		count=1;
		for(i=0;i<m;i++)
		{
			scanf("%d",&num);
			scanf("%d",&represent);
			for(j=1;j<num;j++)	//j从1开始,忽略一组只有一个人的情况,因为这种情况无意义
			{
				scanf("%d",&individual);
				Union(represent,individual);
			}	
		}
		
		for(i=1;i<n;i++)
		{
			if(Find(father[0])==Find(father[i]))
				count++;
		}
		printf("%d\n",count);
	}
	
	
		
		
		
		
	return 0;
}
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;



//并查集的数据存储
#define LENMAX 30001
int father[LENMAX];


//并查集的查找操作
int Find(int x)
{
	if(father[x]<0)
		return x;
	else
	{
		father[x]=Find(father[x]);		//压缩路径compress path
		return father[x];
	}	
}

//并查集的合并操作
void Union(int x,int y)
{
	int rootX=Find(x);
	int rootY=Find(y);

	if(father[rootX]<father[rootY])	
	{
		//y并到x
		father[rootX]+=father[rootY];
		father[rootY]=rootX;
	}
	else
	{
		//x并到y
		father[rootY]+=father[rootX];
		father[rootX]=rootY;
	}

}


//初始化并查集
void MakeSet(int size)
{
	int i;
	for(i=0;i<size;i++)
		father[i]=-1;		//根节点
}



int main(){
	
	#ifdef LOCAL
		freopen("poj_1611_in.txt","r",stdin);		//redirect the input stream
		//freopen("out.txt","w",stdout);		//redirect the output stream
    #endif										
	
	int i,j;
	int n,m,num,count;
	int represent,individual;
	
	while(scanf("%d %d",&n,&m))
	{
		if(m==0&&n==0)
			break;
		
		MakeSet(n);

		for(i=0;i<m;i++)
		{
			scanf("%d",&num);
			scanf("%d",&represent);
			for(j=1;j<num;j++)	//j从1开始,忽略一组只有一个人的情况,因为这种情况无意义
			{
				scanf("%d",&individual);
				Union(represent,individual);
			}	
		}
		/* 
		count=1;
		for(i=1;i<n;i++)
		{
			if(Find(father[0])==Find(father[i]))
				count++;
		}
		printf("%d\n",count);
		

		* */	
		printf("%d\n",-father[Find(0)]);
	}
	
		
	return 0;
}
