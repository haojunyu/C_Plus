/**
 *	本题使用双指针，倒数第k个结点就是当第一个指针走到尾时，在它后k步
 *  出发的指针会走到倒数第k个结点。
 */
#include<stdio.h>
#include<stdlib.h>

// 链表结构定义
struct ListNode{
	int value;
	ListNode* next;

	// constructors
	ListNode(){
		next == NULL;
	}

	ListNode(int val, ListNode *add=NULL){
		value = val;
		next = add;
	}
};


void AddTail(ListNode **pHead, int value){
	ListNode *pNew = (ListNode *)malloc(sizeof(ListNode));
	pNew->value = value;
	pNew->next = NULL;
	if(*pHead == NULL)
		*pHead = pNew;
	else{
		ListNode *pIter = *pHead;
		while(pIter->next != NULL){
			pIter = pIter->next;
		}
		pIter->next = pNew;
	}
}


void DeleteList(ListNode **pHead){
	ListNode *pIter = *pHead, *pTemp;
	while(pIter!=NULL){
		pTemp = pIter;
		pIter = pIter->next;
		free(pTemp);
	}
}


int main(){
	freopen("in.txt","r",stdin);	//redirect the input stream
	
	int num, target, data, i;
	while(scanf("%d %d",&num,&target)!=EOF){
		ListNode *list = NULL;
		ListNode *pFront = NULL, *pBack=NULL;
		// input & print
		for(i=0; i<num; i++){
			scanf("%d",&data);
			AddTail(&list,data);
		}

		// deal with data
		int j=0;
		pFront = list;
		pBack = list;
		while(pFront != NULL){
			if(j>=target)
				pBack = pBack->next;
			j++;
			pFront = pFront->next;
		}

		// output
		if(j>=target)
			printf("%d\n",pBack->value);
		else
			printf("NULL\n");

		DeleteList(&list);
	}
}
