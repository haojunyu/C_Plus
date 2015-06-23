#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	try{
		printf("begin:\n");
		printf("sizeof(int)=%ld\n",sizeof(double *));
		throw 1;
		printf("end:\n");
	}catch(...){
		printf("bug.\n");
	}

	return 0;
}
