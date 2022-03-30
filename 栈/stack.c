#pragma once
#include "stack.h"
	

//��ʼ��
void StackInit(Stack* ps){
	assert(ps);
	ps->_top = 0;
	ps->_capacity = 0;
	ps->_a = NULL;
}
//�������
static void Checkcapacity(Stack* ps){
	assert(ps);
	if (ps->_capacity == ps->_top){
		int newCap = (ps->_capacity == 0 ? 2 : (ps->_capacity * 2));
		ps->_a = (STDataType*)realloc(ps->_a,newCap*(ps->_capacity)*sizeof(STDataType));
		assert(ps->_a);
		ps->_capacity = newCap;
		//printf("add capcity\n");//����ע��
	}
}
void StackPush(Stack* ps,STDataType x){
	Checkcapacity(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps){
	if (ps->_top == 0){
		//printf("top is 0\n");//��ע��,�������
		return;
	
	}
	--(ps->_top);
}

int StackEmpty(Stack* ps){
	assert(ps);
	return ps->_top==0;
}



void StackDestory(Stack* ps){
	assert(ps);
	if (ps->_a){
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = 0;
		ps->_top = 0;
	}
}



