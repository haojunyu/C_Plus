///@file    exer12_4.c
///@brief   简单计算器
///@author  hjy

#include<stdio.h>
#include<string.h>

int main(){
    int op1,op2,ans;
    char ops[10],op;
    int flag=0;

    while(scanf("%d %d %s",&op1,&op2,ops)!=EOF){
        /* printf("%d %d %s\n",op1,op2,ops); */
        if(strlen(ops)!=1){
            printf("Invalid operator!\n");
            continue;
        }
        op=ops[0];
        switch(op){
            case '+':
                ans=op1+op2;
                break;
            case '-':
                ans=op1-op2;
                break;
            case '*':
                ans=op1*op2;
                break;
            case '/':
                if(op2==0){
                    printf("Divided by zero!\n");
                    flag=1;
                }else
                    ans=op1/op2;
                break;
            default:
                printf("Invalid operator!\n");
                flag=1;
        }

        if(!flag)
            printf("%d\n",ans);
    }

    
    return 0;
}



