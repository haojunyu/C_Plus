#include<stdio.h>
#include<math.h>


#define PI 3.1415926

int main(){
    freopen("in.txt","r",stdin);

    int ro,rounds;
    int n;
    double a,r;
    int i,j,k;


    scanf("%d",&rounds);
    for(ro=0; ro<rounds; ro++){
	printf("Case #%d:\n",ro+1);
	if(scanf("%d %lf %lf",&n,&a,&r)==3){
	    double real = a/(2*tan(PI/n));
	    //printf("%lf\n",real);
	    if(real>=r)
	        printf("Give me a kiss!\n");
	    else
	        printf("I want to kiss you!\n");
	      
	}
    }

    return 0;
}
