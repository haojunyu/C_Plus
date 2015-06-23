/*
 * 这题是跟二叉树相关的,所以逻辑上要很强.涉及到前序,中序,后序遍历.
 * 外加递归的思想.
 * Tips: 使用递归
 */
#include<iostream>
#include<stdio.h>
using namespace std;




// 二叉树结构定义
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	// constructors
	BinaryTreeNode(){
		left = NULL;
		right = NULL;
	}

	BinaryTreeNode(int val){
		value = val;
		left = NULL;
		right = NULL;
	}
};




// 用递归构建二叉树
void  Construct(int len, BinaryTreeNode** root, int arr[]){
	if(len <= 0)
		return ;
	
	int num,left,right;
	BinaryTreeNode* child = NULL;
	scanf("%d",&num);
	if(num == 0){
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if(num == 1){
		scanf("%d",&left);
		(*root)->left = new BinaryTreeNode(arr[left-1]);
		Construct(len-1,&((*root)->left),arr);
	}else{
		scanf("%d %d", &left,&right);
		(*root)->left = new BinaryTreeNode(arr[left-1]);
		(*root)->right = new BinaryTreeNode(arr[right-1]);
		Construct(len-1,&((*root)->left),arr);
		Construct(len-1,&((*root)->right),arr);
	}
		
} 


int main(){
	freopen("in.txt","r",stdin);					
	
	int* nodea = new int[1001];
	int* nodeb = new int[1001];
	int i,numa,numb;
	while(scanf("%d %d",&numa,&numb) != EOF){
		for(i=0; i<numa; i++){
			scanf("%d", &nodea[i]);
		}
		BinaryTreeNode* treea = new BinaryTreeNode(nodea[0]);
		BinaryTreeNode* treeb = new BinaryTreeNode(nodeb[0]);
		Construct(numa,&treea, nodea);

		for(i=0; i<numb; i++){
			scanf("%d", &nodeb[i]);
		}
		Construct(numb,&treeb, nodeb);

		// deal with data
		/*
		try{
			BinaryTreeNode* tree = Construct(num);
			// backOrder
			BackOrder(&tree);
			printf("\n");

		}catch(...){
			// throw exception -- can't construct binary tree
			printf("No\n");
		}*/
	}
	delete []nodea;
	delete []nodeb;
}

