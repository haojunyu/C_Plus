///@file    1000.c
///@brief   A+B
///@author  hjy
#include <stdio.h>
	
int main(void) {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
    	printf("%d\n", a + b);
    }
    return 0;
}

