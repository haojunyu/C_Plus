///@file    exer12_5.c
///@brief   字符串插入
///@author  hjy

#include<stdio.h>
#include<string.h>

int main(){

    char str[11],substr[4],ans[15];
    char ch;
    while(scanf("%s %s",str,substr)!=EOF){
        int i,ind=0;
        for(i=1,ch=str[0]; str[i]!='\0'; i++){
            if(ch<str[i]){
                ch=str[i];
                ind=i;
                /* printf("%d\n",ind); */
            }
        }
        strncpy(ans,str,ind+1);
        ans[ind+1]='\0';
        /* printf("%s\n",ans); */
        strcat(ans,substr);
        strcat(ans,str+ind+1);
        printf("%s\n",ans);
        memset(str,0,sizeof(str));
        memset(substr,0,sizeof(substr));
    }
    
    return 0;
}



