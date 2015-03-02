#include<iostream>
#include<stdio.h>
#include<string>
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
		freopen("in.txt","r",stdin);		//redirect the input stream
		//freopen("out.txt","w",stdout);		//redirect the output stream
    #endif										
	
	
	
	int num,i,count=1,key;
	int op;
	char x[50],y[50];
	string nameX,nameY;

	InitFather();
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	{
		scanf("%d %s %s",&op,x,y);
		nameX=x;
		nameY=y;
		//printf("op=%d,nameX=%s,nameY=%s\n",op,nameX.c_str(),nameY.c_str());
		if(!mapName[nameX])
			mapName[nameX]=count++;
		if(!mapName[nameY])
			mapName[nameY]=count++;
		if(op==0)//插入map,合并并查集
		{
			//printf("nameX=%s,keyX=%d\n",nameX.c_str(),mapName[nameX]);
			//printf("nameY=%s,keyY=%d\n\n",nameY.c_str(),mapName[nameY]);
			Union(mapName[nameX],mapName[nameY]);
		}
		else//调出key,查找并查集
		{
			//printf("nameX=%s,keyX=%d\n",nameX.c_str(),mapName[nameX]);
			//printf("nameY=%s,keyY=%d\n\n",nameY.c_str(),mapName[nameY]);
			if(Find(mapName[nameX])==Find(mapName[nameY]))
				printf("yes\n");
			else
				printf("no\n");
		}
		
	}
		
		
		
		
	return 0;
}
