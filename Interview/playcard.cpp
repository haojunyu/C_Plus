#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int main(){
    // freopen("in.txt","r",stdin);
    int nums,num,i,tmp;
    while(scanf("%d",&nums)!=EOF){
        queue<int> a,b;
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%d",&tmp);
            a.push(tmp);
        }
        scanf("%d",&num);
        for(i=0;i<num;i++){
            scanf("%d",&tmp);
            // printf("%d ",tmp);
            b.push(tmp);
        }    
        int counts=0;
        while(!a.empty() && !b.empty()){
            // printf("%d %d\n",a.front(),b.front());
            if(a.front()>b.front()){
                a.push(b.front());
                b.pop();
                a.push(a.front());
                a.pop();
            }else{
                b.push(a.front());
                a.pop();
                b.push(b.front());
                b.pop();
            }
            counts++;
            if(counts>10*nums)
                break;
        }

        if(a.empty())
            printf("%d 2\n",counts);
        else if(b.empty())
            printf("%d 1\n",counts);
        else
            printf("-1\n");
    }



    return 0;
}
