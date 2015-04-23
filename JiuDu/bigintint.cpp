#include<stdio.h>
#include<string.h>


// 整型数组存储
const int base = 100;
const int width = 2;    //width = log(base)
const int N = 1000;
struct bInt{
	int len,dig[N];

	bInt(int r=0){
		for(len=0; r>0; r/=base)
			dig[len++]=r%base;
	}
	
	bInt(const char buf[]){
		int i,w,tmp=0,blen=strlen(buf);
		memset(this,0,sizeof(int)*(N+1));
		if(blen != 0){
			w = 1;
			for(i=blen-1; i>=0; i--){
				tmp += (buf[i]-'0')*w;
				if(w * 10 == base){
					dig[len++] = tmp;
					tmp = 0;
					w = 1;
				}else
					w *= 10;
			}
			if(w != 1)
				dig[len++] = tmp;
		}
	}
	
	bInt& operator = (const bInt& r){
		memcpy(this,&r,sizeof(int)*(r.len+1));
		return *this;
	}
};


bool operator < (const bInt& a, const bInt& b);
bool operator <= (const bInt& a, const bInt& b);
bool operator > (const bInt& a, const bInt& b);
bool operator >= (const bInt& a, const bInt& b);
bInt operator + (const bInt& a, const bInt& b);
bInt operator - (const bInt& a, const bInt& b);
bInt operator * (const bInt& a, const bInt& b);
bInt operator / (const bInt& a, const bInt& b);
int digits(bInt &a);
void write(const bInt& a);

int main(){
	freopen("in.txt","r",stdin);
	
	bInt a(1),b(1000),c(10),t(0);
	bInt tt("1234567");
	printf("%d\n",digits(tt));
	printf("%d\n",b<b);
	printf("%d\n",b<a);
	printf("%d\n",b>c);
	write(a+b);
	//write(b-a);
	//write(a-b);
	write(t);
	write(b-b);
	write(a*b);
	write(a*t);
	//write(a/b);
	write(b/a);


	int num;
	while(scanf("%d",&num)!=EOF){
		printf("%d\n",num);
	}

	return 0;
}


bool operator < (const bInt& a, const bInt& b){
	int i;
	if(a.len!=b.len) return a.len<b.len;
	for(i=a.len-1; i>=0 && a.dig[i]==b.dig[i]; i--);

	if(i<0)
		return 0;
	else
		return a.dig[i]<b.dig[i];
}


bool operator <= (const bInt& a, const bInt& b){
	return !(b<a);
}


bool operator > (const bInt& a, const bInt& b){
	int i;
	if(a.len!=b.len) return a.len>b.len;
	for(i=a.len-1; i>=0 && a.dig[i]==b.dig[i]; i--);

	if(i<0)
		return 0;
	else
	 	return a.dig[i]>b.dig[i];
}


bool operator >= (const bInt& a, const bInt& b){
	return !(b>a);
}


bInt operator + (const bInt& a, const bInt& b){
	bInt sum;
	int i,c=0;
	for(i=0; i<a.len||i<b.len||c>0; i++){
		if(i<a.len)
			c += a.dig[i];
		if(i<b.len)
			c += b.dig[i];
		sum.dig[i] = c % base;
		c = c / base;
	}
	sum.len = i;
	
	return sum;
}


bInt operator - (const bInt& a, const bInt& b){
	bInt diff,big,sma;
	int flag = 0;
	if(a<b){
		big = b;
		sma = a;
		flag = 1;
	}else{
		big = a;
		sma = b;
	}
		
	int i,c=0;
	for(i=0; i<big.len; i++){
		diff.dig[i] = big.dig[i] - c;
		if(i < b.len)
			diff.dig[i] -= sma.dig[i];
		if(diff.dig[i]<0){
			c = 1;
			diff.dig[i] += base;
		}else
			c = 0;
	}
	diff.len = i;
	while(diff.len>0 && diff.dig[diff.len-1]==0)
		diff.len--;
	
	if(flag)
		diff.dig[diff.len-1] = -diff.dig[diff.len-1];
	return diff;
}


bInt operator * (const bInt& a, const bInt& b){
	bInt prod;
	int i,j,k,c=0;
	if(a.len==0||b.len==0){
		prod.dig[0]=prod.len=0;
		return prod;
	}
	memset(&prod,0,sizeof(prod));
	for(i=0; i<a.len; i++){
		k = i;
		for(j=0; j<b.len||c>0; j++){
			if(j<b.len) 
				c += (a.dig[i]*b.dig[j]);
			c += prod.dig[k];
			prod.dig[k++] = c % base;
			c /= base;
		}
	}
	prod.len = k;

	return prod;
}


bInt operator / (const bInt& a, const bInt& b){
	bInt quot,mod,tmp;
	int i,lf,rg,mid;
	mod.dig[0] = mod.len = 0;

	for(i=a.len-1; i>=0; i--){
		mod = mod * base + a.dig[i];
		for(lf=0,rg=base-1; lf<rg;){
			mid = (lf + rg + 1)/2;
			if(b * mid <= mod) 
				lf = mid;
			else
				rg = mid -1;
		}
		quot.dig[i] = lf;
		mod = mod - b * lf;
	}
	quot.len = a.len;
	while(quot.len>0 && quot.dig[quot.len-1]==0)
		quot.len--;
	
	return quot;

}


int digits(bInt &a){
	if(a.len == 0)
		return 0;
	int len = (a.len-1)*width;
	for(int t=a.dig[a.len-1]; t>0; t /=10)
		len++;
	return len;
}


void write(const bInt& a){
	int i;
	if(a.len == 0)
		printf("0");
	else
		printf("%d",a.dig[a.len-1]);
	for(i=a.len-2; i>=0; i--)
		printf("%02d",a.dig[i]);
	printf("\n");
	
}
