#include<stdio.h>
#include<set>
#include<string.h>

using namespace std;


struct address{
    int a;
    int b;
    int c;
    int d;


    address(int av=0,int bv=0,int cv=0,int dv=0){
	a=av;
	b=bv;
	c=cv;
	d=dv;
    }
    
    bool operator < (const address &adb)const{
		if(a==adb.a){
			if(b==adb.b){
				if(c==adb.c){
					if(d==adb.d)
						return false;
					else
						return d<adb.d;
				}else
					return c<adb.c;
			}else
				return b<adb.b;
			}
		else
			return a<adb.a;
	}
};

// comparable struct
struct compare{
    bool operator()(const address &ada,const address &adb)const{
	if(ada.a==adb.a){
	    if(ada.b==adb.b){
		if(ada.c==adb.c){
		    if(ada.d==adb.d)
			return false;
		    else
			return ada.d<adb.d;
		}else
		    return ada.c<adb.c;
	    }else
		return ada.b<adb.b;
	}
	else
	    return ada.a<adb.a;
    }
};


struct address ip[1001];
struct address net[50];


int main(){
    freopen("in.txt","r",stdin);

    int r,rounds;
    int n,m;
    int i,j,k;
    int a,b,c,d;
    //set<address,compare> setnet;
	set<address> setnet;

    scanf("%d",&rounds);
    for(r=0; r<rounds; r++){
	printf("Case #%d:\n",r+1);
	if(scanf("%d %d",&n,&m)==2){
	    memset(ip,0,sizeof(ip));
	    for(i=0;i<n;i++){
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		ip[i]=address(a,b,c,d);
	    }
	    memset(net,0,sizeof(net));
	    for(i=0;i<m;i++){
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		net[i]=address(a,b,c,d);
	    }
	    for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		    int a=ip[j].a & net[i].a;
		    int b=ip[j].b & net[i].b;
		    int c=ip[j].c & net[i].c;
		    int d=ip[j].d & net[i].d;
		    setnet.insert(address(a,b,c,d));
		}
		printf("%ld\n",setnet.size());
		setnet.clear();
	    }
	    
	}
    }

    return 0;
}
