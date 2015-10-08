#include<stdio.h>

char ori[1000000];
char pat[10000];

int KMP();

int main(){
    freopen("in.txt","r",stdin);
    int num,i;
    scanf("%d\n",&num);
    
    for(i=0; i<num; i++){
        scanf("%s\n",pat);
        scanf("%s\n",ori);

        printf("%d",KMP());
        puts(pat);
        puts(ori);
    }
    return 0;
}

// KMP算法
// 输入是全局变量原串ori，模式串pat
int KMP(){
    // 计算next数组
    int i,j,patlen=strlen(pat);
    int *next = malloc(sizeof(int)*(patlen+1));
    j=next[0]=-1;

    for(i=1; i<patlen; i++){
        while(pat[j+1]!=pat[i] && j>0){
            j=next[j];
        }
        if(p == -1)
    }








    free(next);
}
