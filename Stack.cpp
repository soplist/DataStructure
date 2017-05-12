// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;

bool InitStack(SqStack &S);
bool DestroyStack(SqStack &S);
bool ClearStack(SqStack &S);
bool StackEmpty(SqStack S);
int StackLength(SqStack S);
bool GetTop(SqStack S,char &e);
bool Push(SqStack &S, char e);
bool Pop(SqStack &S, char &e);

bool InitStack(SqStack &S){
	S.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base) exit(0);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool GetTop(SqStack S, char &e){
	if (S.top == S.base) return false;
	e = *(S.top - 1);
	return true;
}

bool Push(SqStack &S, char e){
	if (S.top - S.base >= S.stacksize){
		S.base = (char *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(char));
		if (!S.base) exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return true;
}

bool Pop(SqStack &S, char &e){
	if (S.top == S.base) return false;
	e = *--S.top;
	return true;
}

/*int _tmain()
{
	//printf("%d",STACK_INIT_SIZE);
	//system("pause");
	SqStack sqStack;
	InitStack(sqStack);
	Push(sqStack, 'a');
	Push(sqStack, 'b');
	Push(sqStack, 'c');

	char pop;
	Pop(sqStack, pop);
	printf("%c", pop);
	Pop(sqStack, pop);
	printf("%c", pop);
	system("pause");
	return 0;
}*/

