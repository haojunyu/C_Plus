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
	freopen("in.txt","r",stdin);		//redirect the input stream
	//freopen("out.txt","w",stdout);		//redirect the output stream
	
	
	
	int num,i,count=1,key;
	char x[50],y[50];
	string nameX,nameY;

	int counts;
	scanf("%d\n",&counts);
	for(int j=0; j<counts; j++){
	InitFather();
	scanf("%d\n",&num);
	
	for(i=0;i<num;i++)
	{
		scanf("%s %s\n",x,y);
		nameX=x;
		nameY=y;
		//printf("op=%d,nameX=%s,nameY=%s\n",op,nameX.c_str(),nameY.c_str());
		//将没有出现过的名称插入map
		if(!mapName[nameX])
			mapName[nameX]=count++;
		if(!mapName[nameY])
			mapName[nameY]=count++;
		Union(mapName[nameX],mapName[nameY]);
	}
	int classnum=0;
	for(int k=0; k<num; k++){
		if(father[i]==i)
			classnum++;
	}
	if(classnum==2)
		printf("Case #%d: Yes\n",j+1);
	else
		printf("Case #%d: No\n",j+1);
	mapName.clear();
	}
		
		
		
	return 0;
}
