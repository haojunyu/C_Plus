/*
 * 这题是跟二叉树相关的,所以逻辑上要很强.涉及到前序,中序,后序遍历.
 * 外加递归的思想.
 * Tips: 使用递归
 */
#include<iostream>
#include<stdio.h>
using namespace std;


// 全局变量定义
int preOrder[1001],inOrder[1001];


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



// 通过前序和中序构建二叉树
BinaryTreeNode* ConstructCore(int preStart, int preEnd, int inStart, int inEnd){
	int i;
	
	// end condition
	if(preEnd < preStart || inEnd < inStart)
		return NULL;

	// construct binary tree node
	BinaryTreeNode* parent = new BinaryTreeNode(preOrder[preStart]);

	// locate parent position in inOrder
	for(i=inStart; i<=inEnd; i++){
		if(inOrder[i] == parent->value)
			break;
	}
	if(i > inEnd)
		throw 1;		//1 -- can't find inOrder
	
	// divide PreOrder and InOrder of left and right node
	int leftPreStart = preStart+1;
	int leftPreEnd = i -inStart + preStart;
	int leftInStart = inStart;
	int leftInEnd = i-1;
	int rightPreStart = leftPreEnd+1;
	int rightPreEnd = preEnd;
	int rightInStart = i+1;
	int rightInEnd = inEnd;

	// construct binary tree with recursion
	if(leftPreEnd - leftPreStart >= 0){
		parent->left = ConstructCore(leftPreStart, leftPreEnd, leftInStart, leftInEnd);
	}

	if(rightPreEnd - rightPreStart >= 0){
		parent->right = ConstructCore(rightPreStart, rightPreEnd, rightInStart, rightInEnd);
	}

	return parent;
}


// 用递归构建二叉树(这里preOrder和inOrder定义为全局)
BinaryTreeNode* Construct(int len){
	if(len <= 0)
		return NULL;

	return ConstructCore(0, len-1, 0, len-1);
} 


// backOrder
void BackOrder(BinaryTreeNode** tree){
	if(*tree != NULL){
		BinaryTreeNode* tmp;
		tmp = (*tree)->left;
		BackOrder(&tmp);
		tmp = (*tree)->right;
		BackOrder(&tmp);
		printf("%d ",(*tree)->value);
	}
}


int main(){
	freopen("in.txt","r",stdin);					
	
	int num,i;
	while(scanf("%d",&num) != EOF){
		for(i=0; i<num; i++){
			scanf("%d", &preOrder[i]);
		}
		for(i=0; i<num; i++){
			scanf("%d", &inOrder[i]);
		}
		
		/*
		// show data
		for(i=0; i<num; i++){
			printf("%d ", inOrder[i]);
		}
		*/

		// deal with data
		try{
			BinaryTreeNode* tree = Construct(num);
			// backOrder
			BackOrder(&tree);
			printf("\n");

		}catch(...){
			// throw exception -- can't construct binary tree
			printf("No\n");
		}	
	}
}

/*
 * 九度wrong answer code
 * 这段代码和下面accept的代码做法完全一样,唯一的区别在于这段代码是用stack
 * 存储后序序列,而下面的代码是用数组存储的.
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;


// 全局变量定义
int preOrder[1001],inOrder[1001];
stack<int> backOrder;


// 以构建二叉树的方法压栈父节点 
void ConstructCore(int preStart, int preEnd, int inStart, int inEnd){
	int i;
	
	// end condition
	if(preEnd < preStart || inEnd < inStart)
		return;


	// locate parent position in inOrder
	for(i=inStart; i<=inEnd; i++){
		if(inOrder[i] == preOrder[preStart])
			break;
	}
	if(i > inEnd)
		throw 1;		//1 -- can't find inOrder
	
	// divide PreOrder and InOrder of left and right node
	int leftPreStart = preStart+1;
	int leftPreEnd = i -inStart + preStart;
	int leftInStart = inStart;
	int leftInEnd = i-1;
	int rightPreStart = leftPreEnd+1;
	int rightPreEnd = preEnd;
	int rightInStart = i+1;
	int rightInEnd = inEnd;

	// push parent node into stack 
	backOrder.push(preOrder[preStart]);

	// construct binary tree with recursion
	if(rightPreEnd - rightPreStart >= 0){
		ConstructCore(rightPreStart, rightPreEnd, rightInStart, rightInEnd);
	}

	if(leftPreEnd - leftPreStart >= 0){
		ConstructCore(leftPreStart, leftPreEnd, leftInStart, leftInEnd);
	}


}


// 用递归构建二叉树的方法压栈父节点(这里preOrder和inOrder定义为全局)
void Construct(int len){
	if(len <= 0)
		return;

	ConstructCore(0, len-1, 0, len-1);
} 



int main(){
	freopen("in.txt","r",stdin);					
	
	int num,i;
	while(scanf("%d",&num) != EOF){
		for(i=0; i<num; i++){
			scanf("%d", &preOrder[i]);
		}
		for(i=0; i<num; i++){
			scanf("%d", &inOrder[i]);
		}
		

		// deal with data
		try{
			Construct(num);
			// backOrder
			while(!backOrder.empty()){
				printf("%d ",backOrder.top());
				backOrder.pop();
			}
			printf("\n");

		}catch(...){
			// throw exception -- can't construct binary tree
			printf("No\n");
		}	
	}
}
*/

/*
 * 九度accepted code
#include<iostream>
#include<stdio.h>
using namespace std;


// 全局变量定义
int preOrder[1001],inOrder[1001];
int back[1001],bacLen;


// 以构建二叉树的方法压栈父节点 
void ConstructCore(int preStart, int preEnd, int inStart, int inEnd){
	int i;
	
	// end condition
	if(preEnd < preStart || inEnd < inStart)
		return;


	// locate parent position in inOrder
	for(i=inStart; i<=inEnd; i++){
		if(inOrder[i] == preOrder[preStart])
			break;
	}
	if(i > inEnd)
		throw 1;		//1 -- can't find inOrder
	
	// divide PreOrder and InOrder of left and right node
	int leftPreStart = preStart+1;
	int leftPreEnd = i -inStart + preStart;
	int leftInStart = inStart;
	int leftInEnd = i-1;
	int rightPreStart = leftPreEnd+1;
	int rightPreEnd = preEnd;
	int rightInStart = i+1;
	int rightInEnd = inEnd;

	// push parent node into stack
	back[bacLen++]=preOrder[preStart];

	// construct binary tree with recursion
	if(rightPreEnd - rightPreStart >= 0){
		ConstructCore(rightPreStart, rightPreEnd, rightInStart, rightInEnd);
	}

	if(leftPreEnd - leftPreStart >= 0){
		ConstructCore(leftPreStart, leftPreEnd, leftInStart, leftInEnd);
	}


}


// 用递归构建二叉树的方法压栈父节点(这里preOrder和inOrder定义为全局)
void Construct(int len){
	if(len <= 0)
		return;

	ConstructCore(0, len-1, 0, len-1);
} 



int main(){
	freopen("in.txt","r",stdin);					
	
	int num,i;
	while(scanf("%d",&num) != EOF){
		for(i=0; i<num; i++){
			scanf("%d", &preOrder[i]);
		}
		for(i=0; i<num; i++){
			scanf("%d", &inOrder[i]);
		}
		bacLen = 0;

		// deal with data
		try{
			Construct(num);
			
			// backOrder
			for(int i=bacLen-1;i>=0;i--)
				printf("%d ",back[i]);
			printf("\n");

		}catch(...){
			// throw exception -- can't construct binary tree
			printf("No\n");
		}	
	}
}
*/
