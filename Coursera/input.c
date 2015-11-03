#include<stdio.h>

#define LEN 10

int main(){
    int a,b;
    char str[LEN];

    printf("%d\n",scanf("%d %d",&a,&b));
    /* fflush(stdin); */
    getchar();
    printf("%s\n",fgets(str,LEN,stdin));

    
    

    return 0;
}


