///@file    exer10_3.c
///@brief   最长单词2
///@author  hjy

#include<stdio.h>
#include<string.h>


int main(){
    char buffer[500],ans[500];
    int maxlen=0;
    while(scanf("%s",buffer)!=EOF){
        int len=strlen(buffer);
        if(buffer[len-1]=='.'){
            if(len-1>maxlen){
                strncpy(ans,buffer,len-1);
                ans[len-1]='\0';
            }
            printf("%s\n",ans);
            maxlen=0;
        }else{
            if(len>maxlen){
                strcpy(ans,buffer);
                maxlen=len;
            }
        }
    }
    return 0;
}



