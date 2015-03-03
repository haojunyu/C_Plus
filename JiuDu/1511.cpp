/*
 * 这题直接做比较简单,不过下面的代码为了实现List而花费了大量时间,所以在九度上无法通过
 * (Time Limit Exceed),去掉List读取这段之后就可通过,通过代码在最后
 * Tips: 逆向输出 = stack = 递归
 */
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;


// 链表结构定义
struct ListNode{
	int value;
	ListNode* next;

	// constructors
	ListNode(){
		next = NULL;
	}

	ListNode(int val, ListNode* add = NULL){
		value = val;
		next = add;
	}
};


// 这里pHead必须定义成ListNode的指针,这样才会在参数值传递时修改到真正的list
void AddToTail(ListNode** pHead, int value){
	ListNode *pNew = new ListNode();
	pNew->value = value;
	pNew->next = NULL;

	if(*pHead == NULL)
		*pHead = pNew;
	else{
		ListNode* pIter = *pHead;

		while(pIter->next != NULL){
			pIter = pIter->next;
		}
		
		pIter->next = pNew;
	}
}



//-------------------实现功能---------------------------------
// 递归实现反向输出list中数据
void ReverseListByRe(ListNode** list){
	ListNode* pIter = *list;
	if(pIter != NULL){
		ReverseListByRe(&(pIter->next));
		printf("%d\n",pIter->value);
	}
		
}

// stack实现反向输出list中数据
void ReverseListByStack(ListNode** list){
	ListNode* pIter = *list;
	stack<int> reList;

	while(pIter != NULL){
		reList.push(pIter->value);
		pIter = pIter->next;	
	}
	
	while(!reList.empty()){
		printf("%d\n",reList.top());
		reList.pop();
	}
}


int main(){
	freopen("in.txt","r",stdin);					
	
	ListNode* list = NULL;
	ListNode* pIter = NULL;
	int num;
	while(scanf("%d",&num) != EOF){
		if(num == -1)
			break;
		AddToTail(&list, num);
	}
	// show data
	pIter = list;
	while(pIter != NULL){
		printf("%d\n",pIter->value);
		pIter = pIter->next;
	}
		
	// deal data
	ReverseListByStack(&list);
	// output
}


/*
 * 九度accepted code
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
 
int main(){
    //freopen("in.txt","r",stdin);                  
     
    int num;
        stack<int> reList;
    while(scanf("%d",&num) != EOF){
        if(num == -1)
            break;
        reList.push(num);
    }
 
    // deal data
    while(!reList.empty()){
        printf("%d\n",reList.top());
        reList.pop();
    }
    // output
}

*/
