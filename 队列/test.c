#include "queue.h"
int main(){
	free(NULL);
	Queue que;
	Queue* q = &que;
	QueueInit(q);
	QueuePush(q, 1);
	QueuePush(q, 2);
	QueuePush(q, 3);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);
	QueuePop(q);

}