/**
 * 本题主要通过Trie树构建字典，加速后面的单词查询。 
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX 26
typedef struct Node{
	int count;
	struct Node *next[MAX];
}TrieNode;


// 创建新节点
TrieNode* CreateNode(){
	int i=0;
	TrieNode *p = (TrieNode*)malloc(sizeof(TrieNode));
	p->count=1;
	for(i=0; i<MAX; i++){
		p->next[i]=NULL;
	}
//	return p;
}

// 插入字典树
void InsertTrie(TrieNode** pRoot, char *s){
	TrieNode *p = NULL;
	if (*pRoot == NULL){
		*pRoot = CreateNode();
	}
	p = *pRoot;
	int i=0,index;
	while(s[i] != '\0'){
		index = s[i++] - 'a';
		if(p->next[index] == NULL){
			p->next[index] = CreateNode();
		}else{
			p->next[index]->count++;
		}
		p = p->next[index];
	}
}

// 查找字典树
int SearchTrie(TrieNode** pRoot, char *s){
	TrieNode *p = NULL;
	if(*pRoot == NULL){
		return 0;
	}
	p = *pRoot;
	int i=0,index;
	while(s[i] != '\0'){
		index = s[i++] - 'a';
		if (p->next[index] == NULL){
			return 0;
		}else{
			p = p->next[index];
		}
	}
	return p->count;
}


int main(){
	freopen("in.txt","r",stdin);	
	int num,i;
	char arr[100];
	TrieNode *root = CreateNode();
	scanf("%d\n",&num);
	for(i=0; i<num; i++){
		// input 
		scanf("%s\n",arr);
		InsertTrie(&root, arr);
//		printf("%s\n",arr);
	}
	scanf("%d\n",&num);
	for(i=0; i<num; i++){
		// output 
		scanf("%s\n",arr);
		printf("%d\n",SearchTrie(&root, arr));
//		printf("%s\n",arr);
	}

	return 0;
}

