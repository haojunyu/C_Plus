#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int primes[1000];
int primeLen;

void ProducePrime();
bool IsInArray(int n);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int num;															//the number of the cases
	int i,j,n;
	int count;
	
	ProducePrime();
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		count=0;
		scanf("%d",&n);
		if(n==1 || n==2)
		{
				printf("%d\n",count);
				continue;
		}
		if(n%2==1)														//n is odd
		{
			for(j=3;j<=n/2;j=j+2)
			{
				if(IsInArray(j) && IsInArray(n+1-j))
					count++;
			}	
		}
		else 	 														//n is even
		{
			for(j=2;j<=n/2;j++)
			{
				if(IsInArray(j) && IsInArray(n+1-j))
					count++;
			}		
		}
		printf("%d\n",count*2);
	}
}



/*
 * desc:	产生1-10000以内的所有素数
 * pars:	none
 * ret:		void
 */
void ProducePrime()
{
	int i,j;
	bool flag;
	primeLen=0;
	for(i=2;i<10000;i++)
	{
			flag=true;
			for(j=2;j<=(int)sqrt(i);j++)
			{
				if(i%j==0)
				{
					flag=false;
					break;
				}
			}
			if(flag)
				primes[primeLen++]=i;
	}
}


/*
 * desc:	通过二分查找法查找n是否在表中
 * pars:	int n--要查找的值
 * ret:		bool --n是否在表中
 */
bool IsInArray(int n)
{
	int begin,end,mid;
	bool flag=false;
	
	begin=0;
	end=primeLen;
	while(begin<=end)
	{
		mid=(begin+end)/2;
		if(primes[mid]==n)
		{
			flag=true;
			break;
		}	
		else if(primes[mid]>n)
		{
			end=mid-1;
		}
		else
		{
			begin=mid+1;
		}
	}
	
	return flag;
}
