#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;


map<string,int> mapName;	//name--integer

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
	/*
	 * 合并的时候取小的数值
	if(tmpX<tmpY)
		father[tmpY]=tmpX;
	if(tmpX>tmpY)
		father[tmpX]=tmpY;
	*/
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
		freopen("poj_2524_in.txt","r",stdin);		//redirect the input stream
		//freopen("out.txt","w",stdout);		//redirect the output stream
    #endif										
	
	int i,j;
	int n,m,count,num=1;
	int represent,individual;
	
	while(scanf("%d %d",&n,&m))
	{
		if(m==0&&n==0)
			break;
		
		InitFather();
		count=0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&represent,&individual);
			Union(represent,individual);
		}
		
		for(i=0;i<n;i++)
		{
			if(i==father[i])
				count++;
		}
		printf("Case %d: %d\n",num++,count);
	}
	
	
		
		
		
		
	return 0;
}
