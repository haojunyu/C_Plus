int reverse(int x) {
	int negitive=0;
	long long ans=0;;
    if(x<0){
        negitive=1;
        x=-x;
    }
    if(x==0){
        ans=0;
    }else{
        while(x!=0){
            ans=ans*10+x%10;
            x=x/10;
        }
    }
    if(negitive==1)
		ans=-ans;
	if(ans>INT_MAX || ans < INT_MIN)
	    return 0;
	else
        return ans;
}
