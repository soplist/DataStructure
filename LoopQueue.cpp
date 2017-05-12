#include "stdafx.h"
#include<stdlib.h>

#define MAXQSIZE 5
typedef struct{
	char *base;
	int front;
	int rear;
}SqQueue;

bool InitQueue(SqQueue &Q){
	Q.base = (char *)malloc(MAXQSIZE*sizeof(char));
	if (!Q.base) exit(0);
	Q.front = Q.rear = 0;
	return true;
}

int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool EnQueue(SqQueue &Q,char e){
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(SqQueue &Q, char &e){
	if (Q.front == Q.rear) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

/*int _tmain()
{
	SqQueue sqQueue;
	InitQueue(sqQueue);
	EnQueue(sqQueue, 'a');
	EnQueue(sqQueue, 'b');
	EnQueue(sqQueue, 'c');
	EnQueue(sqQueue, 'd');
	EnQueue(sqQueue, 'e');
	EnQueue(sqQueue, 'f');
	char de;
	DeQueue(sqQueue, de);
	printf("%c", de);
	DeQueue(sqQueue, de);
	printf("%c", de);
	DeQueue(sqQueue, de);
	printf("%c", de);
	DeQueue(sqQueue, de);
	printf("%c", de);
	DeQueue(sqQueue, de);
	printf("%c", de);
	DeQueue(sqQueue, de);
	printf("%c", de);
	system("pause");
}*/