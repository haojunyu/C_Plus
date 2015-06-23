#include<stdio.h>
#include<vector>

using namespace std;

// 用kahn算法判断有向图中是否有环
int have_circle_kahn(vector<int> *edges, vector<int> nodes){
    int i,j,m,sum=0;
    vector<int> delnodes;
    while(sum<nodes.size()){
	// 找入度为0的节点，并放入delnodes中，如果没有，则跳出
	for(i=0; i<nodes.size(); i++){
	    if(nodes[i]==0){
		delnodes.push_back(i);
		nodes[i]=-1;
	    }else
	      continue;
	}
	if(delnodes.size()==0)
	    break;
	sum+=delnodes.size();
	// 将delnodes中节点指向的目标节点中删除对应的边
	for(i=0; i<nodes.size(); i++){
	    if(nodes[i]>0){
		for(m=0; m<delnodes.size(); m++){
		    for(j=0; j<edges[i].size(); j++){
			if(delnodes[m]==edges[i][j]){
			    //printf("delete %d\n",edges[i][j]);
			    nodes[i]--;
			    edges[i].erase(edges[i].begin()+j);
			    j--;
			}
		    }
		}
	    }
	}
	// 清空delnodes节点
	delnodes.clear();
    }
    if(sum==nodes.size())
	return 1;
    else
	return 0;
    /*
    for(i=0; i<nodes.size(); i++){
        for(j=0; j<edges[i].size(); j++){
	    printf("%d: %d ",i,edges[i][j]);
	}
	printf("\n");
    }
    */
}


int main(){
    freopen("in.txt","r",stdin);

    int i,j,front,back;
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
	vector<int> *edges=new vector<int>[n];
	vector<int> nodes;
	for(i=0; i<m; i++){
	    scanf("%d %d",&front,&back);
	    edges[front-1].push_back(back-1);
	}
	for(i=0; i<n; i++){
	    nodes.push_back(edges[i].size());	    
	}

	if(have_circle_kahn(edges,nodes)){
	    printf("YES\n");
	}else{
	    printf("NO\n");
	}
    }

    return 0;
}
