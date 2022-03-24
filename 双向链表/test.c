#include "List.h"
int main(){
	ListNode* head = ListCreate();
	ListPrint(head);
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPrint(head);

	//ListPopBack(head);//1 2
	//ListPrint(head);
	//ListPopBack(head);//1
	//ListPrint(head);
	//ListPopBack(head);//
	//ListPrint(head);
	//printf("-=-=-=-=-\n");
	//ListPopBack(head);//
	//ListPrint(head);
	printf("%p\n", ListFind(head, 3));
	ListInsert(ListFind(head, 3), 33);
	ListPrint(head);
	ListInsert(head, 999);
	ListPrint(head);
	ListInsert(head->_next, 111);
	ListPrint(head);
	printf("-0-0-0-0-erase\n");
	ListErase(ListFind(head, 3));
	ListPrint(head);
	ListErase(ListFind(head, 111));
	ListPrint(head);
	ListErase(ListFind(head, 999));
	ListPrint(head);
	ListErase(head->_next);
	ListPrint(head);
	ListErase(head->_next);
	ListPrint(head);
	ListErase(head->_next);
	ListPrint(head);
	ListErase(head->_next);
	ListPrint(head);


	
	
	
	return 0;

}