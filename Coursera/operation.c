#include<stdio.h>

int main(){
    // 反汇编
    printf("hello world!\n");
    
    // 自增
    /* int i=3,a=2; */
    // ++不能作用于表达式
    /* printf("%d\n",(-i)++); */
    /* printf("%d\n",++i++); */
    // 同一个输出中，编译器从右往左计算
    /* printf("%d\t%d\n",a,a++); */

    // 混合运算
    int a=0,b=1;
    a=8>4-(b=!'c')&&5>3+'a'%6=='b';
    printf("%d\t%d\n",a,b);
    return 0;
}
