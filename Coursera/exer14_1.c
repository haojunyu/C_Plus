///@file    exer10_1.c
///@brief   Coursera上C语言课程第十周第一题
///@author  hjy

#include<stdio.h>
#include<string.h>


int main(){
    char buffer[81];
    int aeiou[5],i;
    fgets(buffer,81,stdin);
    memset(aeiou,0,sizeof(aeiou));
    for(i=0; i<strlen(buffer); i++){
        switch(buffer[i]){
            case 'a':
                aeiou[0]++;
                break;
            case 'e':
                aeiou[1]++;
                break;
            case 'i':
                aeiou[2]++;
                break;
            case 'o':
                aeiou[3]++;
                break;
            case 'u':
                aeiou[4]++;
                break;
        }
    }
    printf("%d %d %d %d %d\n",aeiou[0],aeiou[1],aeiou[2],aeiou[3],aeiou[4]);
    return 0;
}


///@brief   函数简要介绍
///@param   a   参数a的描述
///@return  函数返回变量
///@see     参考其他相关函数
///note     注意问题

