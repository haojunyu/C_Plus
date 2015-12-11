///@file    exer21_2.c
///@brief   Coursera上C语言进阶课程第九周第二题：字符串中次数第2多的字母
///@author  hjy

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct alph{
    char ch;
    int id;
    int num;
}salph;

salph alphs[26];
char str[500];

int comp(const void *a, const void *b);

int main(){
    int i,len;
    char al;
    scanf("%s",str);

    memset(alphs,0,sizeof(salph)*26);
    len=strlen(str);
    for(i=0; i<len; i++){
        al=tolower(str[i]);
        if(isalpha(al)){
            if(alphs[al-'a'].num==0){
                alphs[al-'a'].ch=al;
                alphs[al-'a'].id=i;
            }
            alphs[al-'a'].num++;
        }
        /* printf("%c",al); */
    }

    qsort(alphs,26,sizeof(salph),comp);

    for(i=1;i<26;i++){
        if(alphs[i].num!=alphs[0].num){
            printf("%c+%c:%d\n",toupper(alphs[i].ch),alphs[i].ch,alphs[i].num);
            break;
        }
            
    }
    return 0;
}


///@brief   比较函数 
///@param   a   对象a
///@param   b   对象b
///@return  返回比较的数值
///note     最终的顺序是由num，id两个共同控制
int comp(const void *a, const void *b){
    int tmp = (*(salph *)a).num - (*(salph *)b).num;
    if(tmp!=0)
        return -tmp;
    else
        return (*(salph *)a).id - (*(salph *)b).id;
}
