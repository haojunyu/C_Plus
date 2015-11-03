///@file    exer10_8.c
///@brief   校门外的树
///@author  hjy

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct section{
    int beg;
    int end;
}ssec;

ssec sections[100];

int cmp(const void *a,const void *b);

int main(){
    int L,M;

    while(scanf("%d %d",&L,&M)!=EOF){
        int i;
        memset(sections,0,sizeof(ssec)*100);
        for(i=0;i<M;i++)
            scanf("%d %d",&sections[i].beg,&sections[i].end);

        qsort(sections,M,sizeof(ssec),cmp);

        ssec s=sections[0];
        int ans=0;
        for(i=1;i<M;i++){
            if(s.end<sections[i].beg){
                ans+=s.end-s.beg+1;
                s.beg=sections[i].beg;
                s.end=sections[i].end;
            }else{
                if(s.end<sections[i].end)
                    s.end=sections[i].end;
            }
        }
        ans+=s.end-s.beg+1;

        printf("%d\n",L+1-ans);
    }
    return 0;
}


///@brief   比较函数
///@param   a   第一个对象
///@param   b   第二个对象
///@return  返回比较对象的结果
///note     对象是指针变量
int cmp(const void *a,const void *b){
    return (*(ssec *)a).beg-(*(ssec *)b).beg;
}
