#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int GCD(int a,int b);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int num;															//the number of the cases
	int a,b;
	int i;
	int gcd,lcm;
	
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d%d",&a,&b);
		
		gcd=GCD(a,b);
		lcm=a/gcd*b;
		printf("%d %d\n",gcd,lcm);
	}
}



/*
 * desc:	用辗转相除法求两个整数的最大公约数
 * pars:	int a,b--两个整数
 * ret:		最大公约数
 */
int GCD(int a,int b)
{
	while(1)
	{
		if(a>b)
		{
			a=a%b;
		}
		else
		{
			b=b%a;
		}
		if( a==0 || b==0 )
			break;
	}
	if( a==0 )
		return b;
	else
		return a;
}

