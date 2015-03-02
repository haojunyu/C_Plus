//wrong answer
#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

int primes[100000];
int primeLen;

void ProducePrime();
bool IsPrime(int n);
int LowCount(int begin,int end,int n);

int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	
	int a,b;
	int count;
	int aposition;
	
	ProducePrime();
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		aposition=LowCount(0,primeLen,a);
		count=LowCount(aposition,primeLen,b)-aposition;
		printf("%d,%d\n",aposition,count+aposition);
		if(IsPrime(b))
			count++;
		
		printf("%d\n",count);
	}
	return 0;
}



/*
 * desc:	产生1-1000000以内的所有素数
 * pars:	none
 * ret:		void
 */
void ProducePrime()
{
	int i;
	primeLen=0;
	primes[primeLen++]=2;
	for(i=3;i<1000000;i=i+2)
	{		
			if(IsPrime(i))
				primes[primeLen++]=i;
	}
	//printf("%d",primeLen);
}


/*
 * desc:	判断整数是否是素数
 * pars:	int n--整数
 * ret:		bool
 */
 bool IsPrime(int n)
 {
	 if(n==1)
		return false;
		
	 int j;
	 int flag=true;
	 
	 for(j=0;j<primeLen && primes[j]<=(int)sqrt(n) ;j++)
	 {
		 if(n%primes[j]==0)
		 {
		 	flag=false;
		 	break;
		 }
	 }
	 return flag;
 }
 
 
/*
 * desc:	通过二分法确定数组中小于n的值的个数
 * pars:	begin	--起始位置
 * 			end		--结束位置
 * 			n		--值
 * ret:		int --小于n的值的个数
 */
int LowCount(int begin,int end,int n)
{
	int mid;
	int position=0;
	

	while(begin<=end)
	{
		mid=(begin+end)/2;
		if(primes[mid]==n)
		{
			position=mid;
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
	
	if(position==0)
		return begin;
	else
		return position;
}
