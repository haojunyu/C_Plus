/*
 * 该问题主要的难点在于考虑问题的全面，要对base和exp进行正数/负数/0分类考虑
 * 再将相同处理方式的合并。而对于base!=0,exp>0的情况进行算法优化，核心思想
 * 是通过自乘自己来加快乘积，加快算法速度（前提是运算无溢出）
 */

 #include<iostream>
 #include<stdio.h>
 #include<math.h>
 #include<stdlib.h>

 using namespace std;

 double UnsignPower(double base, int unsignexp){
 	// traversal unsignexp times
	/*
 	int i;
	double res=1.0;
	for(i=0; i<unsignexp; i++){
		res = res*base;
	}
	
	return res;
	*/

	// recure log(unsignexp) times
	if(unsignexp == 0){
		return 1.0;
	}else if(unsignexp == 1){
		return base;
	}else{
		double res = UnsignPower(base, unsignexp>>1);
		double result = res*res;
		if(unsignexp & 1)
			result = result * base;

		return result;
	}
	

 }

 double MyPower(double base, int exp){
 	//special
 	if(fabs(base)<0.00000000001){
		if(exp<0)
			return 1.0/0.0;
		else
			return 0.0;
	}
	if(exp == 0)
		return 1.0;

	double res = UnsignPower(base, abs(exp));

	if(exp<0)
		res = 1.0/res;

	return res;
 }



 int main(){
 	freopen("in.txt","r",stdin);

	int num,exp,i;
	double base;
	scanf("%d",&num);

	for(i=0; i<num; i++){
		scanf("%lf %d",&base,&exp);
		
		// deal with data
		double res = MyPower(base,exp);
		
		if(isinf(res)){
			printf("INF\n");
		}else{
			printf("%.2ef\n",res);
		}
	}
 
 	return 0;
 }
