#include "stack.h"
int main(){
	Stack stack1 ;
	Stack* ps = &stack1;
	
	StackInit(ps);
	StackPush(ps,1);
	StackPush(ps,2);
	StackPush(ps,3);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPop(ps);
	StackPush(ps, 1);
	StackPush(ps, 2);
	StackPush(ps, 3);
	while (ps->_top){
		printf(" %d ", (ps->_a)[ps->_top-1]);
		StackPop(ps);


	}




}