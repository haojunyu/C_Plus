#include<stdio.h>
#include<string.h>

#define MAX 2000050
char buf[MAX];
char newbuf[MAX];
int radius[MAX];


int main(){
	freopen("in.txt","r",stdin);	
//	freopen("out.txt","w",stdout);
	int num,t;
	

	scanf("%d\n",&num);
	for(t=0; t<num; t++){

		// input & print
        scanf("%s\n",buf);


		// deal with data
		int i,k;
    int id=0,mx=0,j;
    int len,maxlen=1;

    // 给字符串插入#
    for(i=0; i<strlen(buf)*2+1; i++){
        if(i%2==0)
            newbuf[i]='#';
        else
            newbuf[i]=buf[(i-1)/2];
    }
    newbuf[i]='\0';
    //printf("%s\n",newbuf);

    // 对newbuf用Mancher法计算最长回文子串
    len=i;
    
    radius[0]=0;
    for(i=1; i<len; i++){
        if(mx>i){
            j=id*2-i;
            if(mx-i<radius[j]){
                k=mx-i+1;
                // 以i为中心，回文子串的半径从mx-i+1开始验证
                while(newbuf[i-k]==newbuf[i+k]&&i-k>=0&&i+k<len)
                    k++;
                radius[i]=k-1;
            }else{
                radius[i]=radius[j];
            }
        }else{
            k=1;
            // 以i为中心，回文子串的半径
            while(newbuf[i-k]==newbuf[i+k]&&i-k>=0&&i+k<len)
                k++;
            radius[i]=k-1;
        }
        // 更新id，mx
        if(radius[i]+i>mx){
            id=i;
            mx=radius[i]+i;
        }
    }

    // 从radius中查找最长回文子串的长度
    for(i=0; i<len; i++){
        if(radius[i]>maxlen)
            maxlen=radius[i];
    }
		
		printf("%d\n",maxlen);

	}
	return 0;
}


