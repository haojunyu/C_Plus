/**
 * 本题的做法跟插入法类似，就是将取出的结点插到链表的开头，完成反转的目的
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


void Reverse(ListNode **pHead,ListNode **pRes){
	ListNode *pIter=*pHead, *pTmp=NULL;
	while(pIter!=NULL){
		pTmp = pIter;
		pIter = pIter->next;
		if(*pRes==NULL){
			pTmp->next = NULL;
			*pRes = pTmp;
		}else{
			pTmp->next = *pRes;
			*pRes = pTmp;
		}
			
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
	
	int num,i,data;
	while(scanf("%d",&num)!=EOF){
		ListNode *list=NULL, *pIter=NULL, *pRes=NULL;
		// input & print
		for(i=0; i<num; i++){
			scanf("%d",&data);
			AddTail(&list,data);
		}
		
		// deal with data
		Reverse(&list, &pRes);

		// output
		pIter=pRes;
		i=0;
		while(pIter!=NULL){
			if(i==0){
				printf("%d",pIter->value);
				i++;
			}else
				printf(" %d",pIter->value);
			pIter=pIter->next;
		}
		if(i==0)
			printf("NULL");
		printf("\n");
		DeleteList(&pRes);
	}
}
