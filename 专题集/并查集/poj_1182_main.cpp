//可以通过负的根节点来记录集合包含的元素个数,以此来优化合并(小集合并到大集合)
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
using namespace std;



//并查集的数据存储
#define LENMAX 100001
int father[LENMAX];


//并查集的查找操作
int Find(int x)
{
	if(father[x]>=0)
		return father[x];
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

	//合并的时候取小的数值
	if(tmpX<tmpY)
		father[tmpY]=tmpX;
	if(tmpX>tmpY)
		father[tmpX]=tmpY;
}


//初始化并查集
void InitFather()
{
	int i;
	for(i=0;i<LENMAX;i++)
		father[i]=0;
}



int main(){
	
	#ifdef LOCAL
		freopen("poj_1182_in.txt","r",stdin);		//redirect the input stream
		//freopen("out.txt","w",stdout);		//redirect the output stream
    #endif										
	
	int i,j;
	int n,m,op,x,y,count=0;
	int rootX,rootY;
	
	scanf("%d %d",&n,&m);
	InitFather();
	
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&op,&x,&y);
		if((x>n||y>n) || (op==2&&x==y))
		{
			count++;
			continue;
		}
		
		rootX=Find(x);
		rootY=Find(y);
		if(op==1)
		{
			if(rootX==0&&rootY==0)
			{
				//x,y都代表一个集合
				father[x]=3;
				father[y]=3;
			}
			else if(rootX>0&&rootY==0)
			{
				//只有y代表一个集合
				father[y]=rootX;
			}
			else if(rootX==0&&rootY>0)
			{
				//只有x代表一个集合
				father[x]=rootY;
			}
			else
			{
				if(rootX!=rootY)
					count++;
			}
		}
		else
		{
			if(rootX==0&&rootY==0)
			{
				//x,y都代表一个集合
				father[x]=2;
				father[y]=3;
			}
			else if(rootX>0&&rootY==0)
			{
				//只有y代表一个集合
				father[y]=rootX+1;
			}
			else if(rootX==0&&rootY>0)
			{
				//只有x代表一个集合
				father[x]=rootY-1;
			}
			else
			{
				if((rootY-rootX+3)%3!=1)
					count++;
				if(rootX==rootY)
					count++;
			}
		
		}

		
	}
	printf("%d\n",count);
	
		
		
		
		
	return 0;
}


/*

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
	
		printf("%d\n",-father[Find(0)]);
	}
	
		
	return 0;
}
*/
