#include<iostream>
#include<stdio.h>
using namespace std;

static const int little_prime[] = {
2,3,5,7,11,13,17,19,23,29,
31,37,41,43,47,53,59,61,67,71
};

// 求大数n约数的个数
int NumOfFac(long long n);

// 求不超过数n的约数最多的最小的数
long long minN;
int numOfMinN;
void FindMinN(long long n, long long ans, int counts, int len, int maxTimes);

int main(){
	freopen("in.txt","r",stdin);		//redirect the input stream
	
	long long i,n,min=0;
	int count = 0;
	scanf("%lld",&n);
	/*
	for(i=1; i<=n; i++){
		long long tmp = NumOfFac(i);
		printf("%lld\t\t%lld\n",tmp,i);
		if(tmp>count){
			count = tmp;
			min = i;
		}
	}
	
	printf("%lld\n",min);
	*/

	FindMinN(n, 1, 1, 0, 60);
	printf("%lld\n%d\n", minN,numOfMinN);

		
		
		
	return 0;
}


// 快速计算n的约数个数
int NumOfFac(long long n){
	unsigned int i,k,count=1;
	long long m=n;
	while(m!=1){
		for(i=2; i<=m; i+=2){
			if(m % i == 0){
				k=1;
				while(m % i == 0){
					k++;
					m = m / i;
				}
				count = count*k;
			}
			// 2,3,5,7,11...避开2->3之间差1
			if(i == 2)
				i--;
		}
	}
	return count;
}


void FindMinN(long long n, long long ans, int counts, int len, int maxTimes){
	// update
	if(counts > numOfMinN || (counts == numOfMinN && minN > n)){
		numOfMinN = counts;
		minN = ans;
	}

	// find
	int i;
	for(i=1; i<=maxTimes; i++){
		ans = ans * little_prime[len];
		if(ans > n)
			break;
		FindMinN(n, ans, counts*(i+1), len+1, i);
	}
}
