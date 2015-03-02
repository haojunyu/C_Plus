#include<iostream>
#include<stdio.h>
using namespace std;

int ChangeBottle(int own, int take, int change);
 
int main(){
	freopen("in.txt","r",stdin);										//redirect the input stream
	//freopen("out.txt","w",stdout);										//redirect the output stream
	
	int own,take,change;
	while(scanf("%d%d%d",&own,&take,&change)!=EOF){
		printf("%d\n",ChangeBottle(own,take,change));
	}
}


/*
 * desc:	通过递归求可以换多少酒瓶
 * pars:	int own		--拥有的酒瓶
 * 			int take	--捡的酒瓶
 * 			int change	--需要多少酒瓶交换酒
 * ret:		int 		--可以换多少酒
 */
 int ChangeBottle(int own, int take, int change)
 {
	 int sum;
	 
	 sum = own + take;
	 if(sum < change)
		return 0;
	else
		return sum/change+ChangeBottle(sum/change, sum%change, change);
 }
 
