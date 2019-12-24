/**
 * @file      : 1039.c
 * @brief     : 字符消除https://hihocoder.com/problemset/problem/1039
 *
 * @author    : haojunyu <haojunyu2012@gmail.com>
 * @date      : 2019-04-16 23:45
 * @copyright : hjy, license MIT
 */

#include<stdio.h>
#include<string.h>

void str_insert(char* src,char* desc,char* copy, int idx){
  if(idx<0){idx = 0;}
  int src_len = strlen(src);
  int copy_len = strlen(copy);
  if(idx>src_len){ idx = src_len;}
  memcpy(src,desc,idx-0);
  memcpy(copy,desc+idx,copy_len);
  memcpy(src+idx,desc,src_len-idx);
}

int main(){
  freopen("in.txt","r",stdin);	
  int group,i;
  char buf[102];
  scanf("%d\n",&group);
  for(i=0;i<group;i++){
    scanf("%s\n",buf);
    char tmp[102];
    int idx = 1;
    /* str_insert(buf,tmp,"A",idx); */
    printf("%s\t%d\t%s\n",buf,idx,tmp);
    /*
    for(idx=0;idx<=strlen(buf);idx++){
      str_insert(buf,tmp,"A",idx);
      printf("%s\t%d\t%s\n",buf,idx,tmp);
    }
    */
  }
    
  return 0;
}


