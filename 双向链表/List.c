#include "List.h"
//创建返回链表头节点
ListNode* ListCreate(){
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL){ printf("ListCrate is fail return null point\n"); return NULL; }
	head->_data = 0;
	head->_next = head;
	head->_prev = head;
	return head;
}
//销毁
void ListDestory(ListNode* phead){
	if (phead == NULL){
		printf("ListDestory erro:: null point\n");
		return;
	}
	ListNode* cur = phead->_next;
	while (cur != phead){
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(cur);
}
//打印
void ListPrint(ListNode* phead){
	if (phead == NULL){
		printf("ListPrint erro:: null point\n");
		return;
	}
	ListNode* cur = phead->_next;
	printf("[");
	while (cur != phead){
		printf(" %d ", cur->_data);
		cur = cur->_next;
	}
	printf("]\n");
}
//申请一个节点
static ListNode* BuyNode(LTDataType x){
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL){ printf("Buy is fail\n"); return NULL; }
	node->_data = x;
	node->_next = NULL;
	node->_prev = NULL;
	return node;
}
//尾插
void ListPushBack(ListNode* phead, LTDataType x){
	ListNode* prev = phead->_prev;
	ListNode* node = BuyNode(x);
	node->_next = phead;
	node->_prev = phead->_prev;
	(phead->_prev)->_next = node;
	phead->_prev = node;
}
//尾删
void ListPopBack(ListNode* phead){
	assert(phead);
	if (phead->_next == phead){
		printf("list is null\n");
		return;
	}
	ListNode* prev = (phead->_prev)->_prev;
	free(phead->_prev);
	phead->_prev = prev;
	prev->_next = phead;
}

//查找
ListNode* ListFind(ListNode* phead, LTDataType x){
	assert(phead);
	ListNode* cur = phead->_next;
	while (cur != phead){
		if (cur->_data == x){
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//前插入
void ListInsert(ListNode* pos,LTDataType x){
	assert(pos);
	ListNode* node = BuyNode(x);
	node->_next = pos;
	node->_prev = pos->_prev;
	pos->_prev->_next = node;
	pos->_prev = node;
	
}
void ListPushFront(ListNode* pHead, LTDataType x){
	assert(pHead);
	ListInsert(pHead->_next, x);
}

//删除

void ListErase(ListNode* pos){
	assert(pos);
	(pos->_prev)->_next = pos->_next;
	(pos->_next)->_prev = pos->_prev;
	free(pos);
}

//头删

void ListPopFront(ListNode* phead){
	assert(phead);
	if (phead->_next != NULL){
		ListErase(phead->_next);
	}
}