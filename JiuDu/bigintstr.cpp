/*
 *
 */

 #include<iostream>
 #include<stdio.h>
 #include<string.h>

 using namespace std;

 // 字符串存储
 const int MAXLEN = 100;

 void Add(char *sum, char *a, char *b);
 void Minus(char *diff, char *a, char *b);
 void Mul(char *prod, char *a, char *b);
 void Div(char *quot, char *a, char *b);





 int main(){
 	freopen("in.txt","r",stdin);
	char res[MAXLEN], a[MAXLEN], b[MAXLEN];
	while(scanf("%s %s", a, b) == 2){
		//memset(res,'0',sizeof(res));
		// Add
		Add(res, a, b);
		printf("%s + %s = %s\n",a, b, res);

		// Minus
		Minus(res, a, b);
		printf("%s - %s = %s\n",a, b, res);

		// Mul
		Mul(res, a, b);
		printf("%s * %s = %s\n",a, b, res);
		
		// Div
		Div(res, a, b);
		printf("%s / %s = %s\n",a, b, res);
		printf("\n\n");
	}
	//printf("%d\n",strcmp("aa","ab"));
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


 // diff = a - b(a>=0&&b>=0)
 void Minus(char *diff, char *a, char *b){
	if(strcmp(a,b)==0){
		strcpy(diff,"0");
		return;
	}
	int flag = 0,i,c = 0;
	char *big, *sma;
	int alen=strlen(a),blen=strlen(b);
	if(alen<blen || (alen==blen && strcmp(a,b)<0)){
		flag = 1;
		big = b;
		sma = a;
	}else{
		big = a;
		sma = b;
	}
	
	int biglen=strlen(big),smalen=strlen(sma);
	for(i=0; i<biglen||c>0; i++){
		char ch;
		if(i<smalen)
			ch = sma[smalen-i-1];
		else
			ch = '0';
		int tmp = big[biglen-i-1] - ch - c;
		if(tmp < 0){
			tmp += 10;
			c = 1;
		}else
			c = 0;
		diff[i] = tmp + '0';
	}
	// escape 10-5
	if(diff[i-1]=='0')
		i--;
	if(flag)
		diff[i++] = '-';
	diff[i] = '\0';
	// reverse the string of sum
	int reslen = i;
	for(i=0; i<reslen/2; i++){
		char tmp = diff[i];
		diff[i] = diff[reslen-i-1];
		diff[reslen-i-1] = tmp;
	}
 }


 // prod = a * b(a>=0&&b>=0)
 void Mul(char *prod, char *a, char *b){
	int i,j,k,c=0;
	memset(prod,'0',sizeof(prod));
	// product two number from back to front
	int alen = strlen(a), blen=strlen(b);
	for(i=0; i<alen; i++){
		k=i;
		for(j=0; j<blen||c>0; j++){
			if(j<blen) c += (a[alen-i-1]-'0')*(b[blen-j-1]-'0');
			c += prod[k]-'0' ;
			prod[k++] = c % 10 + '0';
			c = c /10 ;
		}
	}
	prod[k] = '\0';
	// reverse the string of sum
	int reslen = k;
	for(i=0; i<reslen/2; i++){
		char tmp = prod[i];
		prod[i] = prod[reslen-i-1];
		prod[reslen-i-1] = tmp;
	}
	 
 }

 //quot = a / b(a>=0&&b>=0)
 void Div(char *quot, char *a, char *b){
	int i=0,c;
	char token[MAXLEN],ans[MAXLEN];
	int alen=strlen(a),blen=strlen(b);
	int times;
	if(strcmp(b,"0")==0){
		strcpy(quot,"inf");
		return;
	}
		
	if(alen<blen || (alen==blen && strcmp(a,b)<0)){
		quot[i++]='0';
	}else{
		memset(token,'\0',sizeof(token));
		if(strcmp(a,b)>0){
			times = alen - blen + 1;
			strncpy(token,a,blen);
		}else{
			times = alen - blen ;
			strncpy(token,a,blen+1);
		}
		for(;i<times;i++){
			quot[i] = '0';
			while(1){
				memset(ans,'\0',sizeof(ans));
				Minus(ans,token,b);
				if(ans[0]=='-'){
					break;	
				}else{
					strcpy(token, ans);
					quot[i]++;
				}
			}
			if(strcmp(token,"0")==0){
				token[0]=a[blen+i];
				token[1]='\0';
			}else{
				token[strlen(token)]=a[blen+i];
				token[strlen(token)+1]='\0';
			}
		}
		quot[i]='\0';
	}
 }

 

