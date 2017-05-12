#include "stdafx.h"
#include<stdlib.h>

typedef struct QNode{
	char data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q);
bool DestroyQueue(LinkQueue &Q);
bool ClearQueue(LinkQueue &Q);
bool QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
bool GetHead(LinkQueue Q,char &e);
bool EnQueue(LinkQueue &Q, char e);
bool DeQueue(LinkQueue &Q, char &e);

bool InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(0);
	Q.front->next = NULL;
	return true;
}

bool DestroyQueue(LinkQueue &Q){
	while (Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return true;
}

bool EnQueue(LinkQueue &Q, char e){
	QNode *p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(0);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

bool DeQueue(LinkQueue &Q, char &e){
	if (Q.front == Q.rear) return false;
	QNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return true;
}

/*int _tmain()
{
	LinkQueue linkQueue;
	InitQueue(linkQueue);
	EnQueue(linkQueue, 'a');
	EnQueue(linkQueue, 'b');
	EnQueue(linkQueue, 'c');
	EnQueue(linkQueue, 'd');
	char de;
	DeQueue(linkQueue, de);
	printf("%c", de);
	DeQueue(linkQueue, de);
	printf("%c", de);
	DeQueue(linkQueue, de);
	printf("%c", de);
	DestroyQueue(linkQueue);
	system("pause");
	return 0;
}*/