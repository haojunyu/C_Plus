#include<stdio.h>
#include<string.h>


int main(){
    //freopen("in.txt","r",stdin);
    int i,n,tmp;
    int ageNum[4];

    scanf("%d",&n);
    memset(ageNum,0,sizeof(ageNum));
    for(i=0; i<n; i++){
        scanf("%d",&tmp);
        if(tmp<=18)
            ageNum[0]++;
        else if(tmp<=35)
            ageNum[1]++;
        else if(tmp<=60)
            ageNum[2]++;
        else
            ageNum[3]++;
    }

    printf("1-18: %.2lf\%\n",100.0*ageNum[0]/n);
    printf("19-35: %.2lf\%\n",100.0*ageNum[1]/n);
    printf("36-60: %.2lf\%\n",100.0*ageNum[2]/n);
    printf("60-: %.2lf\%\n",100.0*ageNum[3]/n);

    return 0;
}
