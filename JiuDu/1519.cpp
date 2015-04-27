/**
 * 本题的做法其实跟归并排序中并的操作类似，不过是将数组变成链表
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


void Merge(ListNode **pa, ListNode **pb, ListNode **pRes){
	ListNode *pIa=*pa, *pIb=*pb, *pTmp=NULL, *pIter=NULL;
	while(pIa!=NULL&&pIb!=NULL){
		if(pIa->value > pIb->value){
			pTmp = pIb;
			pIb = pIb->next;
		}else{
			pTmp = pIa;
			pIa = pIa->next;
		}
		if(pIter==NULL){
			pIter = pTmp;
			*pRes = pIter;
		}else{
			pIter->next = pTmp;
			pIter = pIter->next;
		}
	}

	if(pIa!=NULL){
		pIter->next = pIa;		
	}
	if(pIb!=NULL){
		pIter->next = pIb;
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
	
	int numa,numb,i,data;
	while(scanf("%d %d",&numa,&numb)!=EOF){
		ListNode *lista=NULL, *listb=NULL, *pIter=NULL, *pRes=NULL;
		// input & print
		for(i=0; i<numa; i++){
			scanf("%d",&data);
			AddTail(&lista,data);
		}
		for(i=0; i<numb; i++){
			scanf("%d",&data);
			AddTail(&listb,data);
		}
		
		// deal with data
		Merge(&lista, &listb, &pRes);

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
