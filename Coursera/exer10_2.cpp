///@file    exer10_2.cpp
///@brief   accept，但是不知道为啥cin就ac，用fgets就wa
///@author  hjy

#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main(){
    char str1[81],str2[81];
    cin.getline(str1,81,'\n');
    cin.getline(str2,81,'\n');
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
    
    return 0;
}



