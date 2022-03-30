#include "queue.h"
void QueueInit(Queue* q){
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;

}
void QueuePush(Queue* q,QDataType x){
	assert(q);
	QNode* Node = (QNode*)calloc(1,sizeof(QNode));
	assert(Node);
	Node->_data = x;
	if (q->_front == NULL){
		q->_front = q->_rear = Node;
	}
	else{
		q->_rear->_next = Node;
		q->_rear = Node;
	}
}

void QueuePop(Queue* q){
	assert(q);
	Queue* head = q->_front;
	if (head == NULL)return;
	if (head == q->_rear){  //判断是否为一个节点
		q->_rear=q->_front = q->_front->_next;
		free(head);
	}
	else{
		q->_front = q->_front->_next;
		free(head);
	}
}


QDataType QueueFront(Queue* q){
	return q->_front->_data;
}

QDataType QueueBack(Queue* q){
	return q->_rear->_data;
}

int QueueEmpty(Queue* q){
	return q->_front == NULL;
}


int QueueSize(Queue* q){
	QNode* cur;
	int count = 0;
	for (cur = q->_front; cur; cur = cur->_next){
		count++;
	}
	return count;
}

void QueueDestory(Queue* q){
	if (q->_front == NULL){
		return;
	}

	while (q->_front){
		QueuePop(q);
	}
}
