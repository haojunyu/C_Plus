#include<stdio.h>
#include<string.h>

char str[100001];

int main(){
    freopen("in.txt","r",stdin);

    int ro,rounds;
    int len,k,s,ys;
    int i,j,num;


    scanf("%d\n",&rounds);
    for(ro=0; ro<rounds; ro++){
	printf("Case #%d:\n",ro+1);
	gets(str);
	len=strlen(str);
        scanf("%d\n",&k);
	s=len/k;
	ys=len%k;

	for(i=0;i<s;i++){
	    j=i;
	    num=ys;
	    while(j<len){
		printf("%c",str[j]);
		if((num--) > 0)
		    j=j+s+1;
		else
		    j=j+s;
	    }
	}
	for(num=0,j=i;num<ys;num++){
	    printf("%c",str[j]);
	    j=j+s+1;
	}
	printf("\n");
    }

    return 0;
}
