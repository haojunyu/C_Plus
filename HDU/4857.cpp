#include<stdio.h>
#include<vector>

using namespace std;



int main(){
    freopen("in.txt","r",stdin);

    int i,j,front,back;
    int n,m;
    int r,rounds;
    scanf("%d",&rounds);
    for(r=0;r<rounds;r++){
	scanf("%d %d",&n,&m);
	vector<int> *edges=new vector<int>[n];
	vector<int> nodes;
	for(i=0; i<m; i++){
	    scanf("%d %d",&front,&back);
	    edges[front-1].push_back(back-1);
	}
	for(i=0; i<n; i++){
	    nodes.push_back(edges[i].size());	    
	}

	for(i=0; i<nodes.size(); i++){
	    printf("%d: ",i);
	    for(j=0; j<edges[i].size(); j++){
		printf("%d ",edges[i][j]);
	    }
	    printf("\n");
	}
    }

    return 0;
}
