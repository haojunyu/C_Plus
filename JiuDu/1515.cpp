/*
 * 本题换个说法就是实现大数加法。因为当n超出int/long范围时，就无法打印了。
 */

 #include<iostream>
 #include<stdio.h>
 #include<string.h>

 using namespace std;
 
 // 字符串存储
 const int MAXLEN = 100;

 void Add(char *sum, char *a, char *b);


 int main(){
 	freopen("in.txt","r",stdin);

	int digit;
	char res[MAXLEN],a[MAXLEN]="0";
	while(scanf("%d",&digit)!=EOF){
		while(1){
			Add(res,a,"1");
			if(strlen(res) > digit)
				break;
			else{
				printf("%s\n",res);
				strcpy(a,res);
			}
		}
	}
 
 	return 0;
 }
 
 
 // res = a + b(a>=0&&b>=0)
 void Add(char *res, char *a, char *b){
	int i,c=0;
	// add two number from back to front
	int alen = strlen(a), blen=strlen(b);
	for(i=0; i<alen||i<blen||c>0; i++){
		if(i<alen) c += a[alen-1-i] - '0';
		if(i<blen) c += b[blen-1-i] - '0';
		res[i] = c % 10 + '0';
		c = c / 10;
	}
	res[i] = '\0';
	// reverse the string of sum
	int reslen = i;
	for(i=0; i<reslen/2; i++){
		char tmp = res[i];
		res[i] = res[reslen-i-1];
		res[reslen-i-1] = tmp;
	}
 }
