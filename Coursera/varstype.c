#include<stdio.h>

// struct
struct student{
    /* char name[10]; */
    int age;
    double weight;
    float height;
    /* char sex; */
    /* char a; */
    /* char b,c; */
};

// union
union u{
    char ch;
    int num;
    double dou;
    char name[10];
};

// enum
enum days{mon,tue,wed,thu,fri,sat,sun};

int main(){
    // 基本数据类型
	short s,*sp;
    printf("sizeof(short) is %ld byte.\n",sizeof(short));
    printf("sizeof(short*) is %ld byte.\n",sizeof(short*));
    printf("sizeof(short variable) is %ld byte.\n",sizeof(s));
    printf("sizeof(short* variable) is %ld byte.\n",sizeof(sp));
    printf("\n");

    int i,*ip;
    printf("sizeof(int) is %ld byte.\n",sizeof(int));
    printf("sizeof(int*) is %ld byte.\n",sizeof(int*));
    printf("sizeof(int variable) is %ld byte.\n",sizeof(i));
    printf("sizeof(int* variable) is %ld byte.\n",sizeof(ip));
    printf("\n");

    long l,*lp;
    printf("sizeof(long) is %ld byte.\n",sizeof(long));
    printf("sizeof(long*) is %ld byte.\n",sizeof(long*));
    printf("sizeof(long variable) is %ld byte.\n",sizeof(l));
    printf("sizeof(long* variable) is %ld byte.\n",sizeof(lp));
    printf("\n");

    float f,*fp;
    printf("sizeof(float) is %ld byte.\n",sizeof(float));
    printf("sizeof(float*) is %ld byte.\n",sizeof(float*));
    printf("sizeof(float variable) is %ld byte.\n",sizeof(f));
    printf("sizeof(float* variable) is %ld byte.\n",sizeof(fp));
    printf("\n");

    double d,*dp;
    printf("sizeof(double) is %ld byte.\n",sizeof(double));
    printf("sizeof(double*) is %ld byte.\n",sizeof(double*));
    printf("sizeof(double variable) is %ld byte.\n",sizeof(d));
    printf("sizeof(double* variable) is %ld byte.\n",sizeof(dp));
    printf("\n");
    
    char c,*cp;
    printf("sizeof(char) is %ld byte.\n",sizeof(char));
    printf("sizeof(char*) is %ld byte.\n",sizeof(char*));
    printf("sizeof(char variable) is %ld byte.\n",sizeof(c));
    printf("sizeof(char* variable) is %ld byte.\n",sizeof(cp));
    printf("\n");

	void *vp;
    printf("sizeof(void) is %ld byte.\n",sizeof(void));
    printf("sizeof(void*) is %ld byte.\n",sizeof(void*));
    printf("sizeof(void* variable) is %ld byte.\n",sizeof(vp));
    printf("\n");


    printf("----------------\n");
    // 构造数据类型(注意字节对齐)
    struct student st,*stu;
    printf("sizeof(struct student) is %ld byte.\n",sizeof(struct student));
    printf("sizeof(struct student*) is %ld byte.\n",sizeof(struct student*));
    printf("sizeof(struct student variable) is %ld byte.\n",sizeof(st));
    /* printf("sizeof(struct inline variable) is %ld byte.\n",sizeof(st.name)); */
    printf("sizeof(struct student* variable) is %ld byte.\n",sizeof(stu));
    printf("\n");

    // 对齐方式有点变化
    union u uu,*up;
    printf("sizeof(union u) is %ld byte.\n",sizeof(union u));
    printf("sizeof(union u*) is %ld byte.\n",sizeof(union u*));
    printf("sizeof(union u variable) is %ld byte.\n",sizeof(uu));
    printf("sizeof(union u* variable) is %ld byte.\n",sizeof(up));
    printf("\n");

    enum days day,*dayp;
    printf("sizeof(enum days) is %ld byte.\n",sizeof(enum days));
    printf("sizeof(enum days*) is %ld byte.\n",sizeof(enum days*));
    printf("sizeof(enum days variable) is %ld byte.\n",sizeof(day));
    printf("sizeof(enum days* variable) is %ld byte.\n",sizeof(dayp));
    printf("\n");

    return 0;
}



//http://blog.csdn.net/van150/article/details/544454
//http://blog.chinaunix.net/uid-20546930-id-1927570.html
