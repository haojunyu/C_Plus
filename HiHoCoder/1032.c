#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 暴力求解
int MaxPalByForce(char* buf);
// 动态规划
int MaxPalByDP(char* buf);
// 中心扩展
int MaxPalByCenter(char* buf);
// Manacher法
int MaxPalByMancher(char* buf);
// Manacher法-精简代码
int MaxPalByMancher2(char* buf);

int main(){
	freopen("in.txt","r",stdin);	
//	freopen("out.txt","w",stdout);
	int num,i,ans;
	char buf[1000000];

	scanf("%d\n",&num);
	for(i=0; i<num; i++){

		// input & print
		fgets(buf,1000000,stdin);
        buf[strlen(buf)-1]='\0';
		printf("%s\n",buf);

		// deal with data
		//ans = MaxPalByForce(buf);
		//ans = MaxPalByDP(buf);
		//ans = MaxPalByCenter(buf);
		//ans = MaxPalByMancher(buf);
		ans = MaxPalByMancher2(buf);
		
		printf("%d\n",ans);

	}
	return 0;
}

// 暴力求解
int MaxPalByForce(char* buf){
	int i,j,k;
	int len=strlen(buf),maxlen=1;

	for(i=0; i<len-1; i++){
		for(j=i+1; j<len; j++){
			// 判断buf[i-j]是否是回文
			for(k=i; ; k++){
				if(buf[k]!=buf[j-k+i]||k>j-k+i)
					break;
			}
			// 是回文且长度比maxlen大
			if(k>j-k+i && j-i+1>maxlen)
				maxlen=j-i+1;
		}
	}
	
	return maxlen;
}

// 动态规划
int MaxPalByDP(char* buf){
	int i,j,count,index;
	int len=strlen(buf),maxlen=1;

	// 动态申请二位数组并初始化
	int **dp = (int **)malloc(sizeof(int *) * len);
	dp[0] = (int *)malloc(sizeof(int) * len * len);
	for(i=1; i<len; i++)
		dp[i] = dp[i-1] + len;
	
	// 初始化dp--对角线为1，其余为0
	memset(dp[0],0,len*len*sizeof(int));	//注意最后一个参数要*sizeof(int)
	for(i=0; i<len; i++)
		dp[i][i] = 1;
	/*
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			if(i==j)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}*/

	// count代表斜对角线上有count个元素，index是元素的索引
	for(count=len-1; count>0; count--){
		for(index=0; index<count; index++){
			i = index;
			j = index+len-count;
			if(buf[i]==buf[j]&&(i+1>j-1 || dp[i+1][j-1]==1)){
				// buf[i - j]是回文子串
				dp[i][j] = 1;
				if(j-i+1 > maxlen)
					maxlen = j-i+1;
			}
		}
	}

	// 释放申请的二位数组
	free(dp[0]);
	free(dp);

	return maxlen;
}



// 中心扩展
int MaxPalByCenter(char* buf){
	int i,r;
	int len=strlen(buf),maxlen=1;

	// 回文子串的长度为奇数，即有中心
	for(i=0; i<len; i++){
		r=1;
		while(i-r>-1 && i+r<len && buf[i-r]==buf[i+r])
			r++;
		if(r*2-1 > maxlen)
			maxlen = r*2-1;
	}

	// 回文子串的长度为偶数，即无中心
	for(i=1; i<len; i++){
		r=0;
		while(i-1-r>0 && i+r<len && buf[i-1-r]==buf[i+r])
			r++;
		if(r*2 > maxlen)
			maxlen = r*2;
	}

	return maxlen;
}



// Manacher法
int MaxPalByMancher(char* buf){
    int i,k;
    int id=0,mx=0,j;
    int len,maxlen=1;

    // 给字符串插入#
    char *newbuf=malloc(sizeof(char)*(strlen(buf)*2+1));
    for(i=0; i<strlen(buf)*2+1; i++){
        if(i%2==0)
            newbuf[i]='#';
        else
            newbuf[i]=buf[(i-1)/2];
    }
    printf("%s\n",newbuf);

    // 对newbuf用Mancher法计算最长回文子串
    len=strlen(newbuf);
    int *radius=malloc(sizeof(int)*len);
    
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
    free(newbuf);
    free(radius);
    return maxlen;
}


// Manacher法-精简代码
int MaxPalByMancher2(char* buf){
    int i,k;
    int id=0,mx=0,j;
    int len,maxlen=1;

    // 给字符串插入#
    char *newbuf=malloc(sizeof(char)*(strlen(buf)*2+1));
    for(i=0; i<strlen(buf)*2+1; i++){
        if(i%2==0)
            newbuf[i]='#';
        else
            newbuf[i]=buf[(i-1)/2];
    }
    printf("%s\n",newbuf);

    // 对newbuf用Mancher法计算最长回文子串
    len=strlen(newbuf);
    int *radius=malloc(sizeof(int)*len);
    
    radius[0]=0;
    for(i=1; i<len; i++){
        if(mx>i){
            if(radius[j]<mx-i)
                radius[i]=radius[j];
            else
                radius[i]=mx-i;
        }else{
            radius[i]=1;
        }
        for(;newbuf[i+radius[i]]==newbuf[i-radius[i]]&&i+radius[i]<len&&i-radius[i]>=0;radius[i]++);
        // 更新id，mx
        if(radius[i]+i>mx){
            id=i;
            mx=radius[i]+i;
        }
    }

    // 从radius中查找最长回文子串的长度
    for(i=0; i<len; i++){
        if(radius[i]>maxlen)
            maxlen=radius[i]-1;
    }
    free(newbuf);
    free(radius);
    return maxlen;
}
