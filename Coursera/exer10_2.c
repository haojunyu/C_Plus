///@file    exer10_2.c
///@brief   Coursera上C语言课程第十周第二题,wa(fgets问题)
///@author  hjy

#include<stdio.h>
#include<string.h>


int main(){
    char str1[81],str2[81];
    while(fgets(str1,81,stdin)!=NULL){
        fgets(str2,81,stdin);
        int i;
        for(i=0;i<strlen(str1);i++){
            if(str1[i]>='A' && str1[i]<='Z')
                str1[i]=str1[i]-'A'+'a';
        }
        for(i=0;i<strlen(str2);i++){
            if(str2[i]>='A' && str2[i]<='Z')
                str2[i]=str2[i]-'A'+'a';
        }
        int res=strcmp(str1,str2);
        if(res<0)
            printf("<\n");
        else if(res>0)
            printf(">\n");
        else
            printf("=\n");
    }
    return 0;
}



