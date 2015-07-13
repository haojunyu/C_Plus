#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
bool prime(long long x)
{
	long long  y;
	for(y=2;y<=sqrt(x);y++)
	if (x%y==0)
	      return false;
	return true;
}
int main ()
{
	freopen("out.txt","w",stdout);    
	long long i,n=10000000000000000;
	//long long i,n=1000;

	int count=1;
		
		for(i=2;i<=n;i++){
		      if (prime(i)){
		           cout<<i<<",";
				   count++;
			  }
			  if(count%11 == 0){
				cout<<endl;
				count=1;
			  }
		}


		return 0;
}
