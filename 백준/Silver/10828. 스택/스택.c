#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int Data;

typedef struct Node
{
	struct Node* next;
	Data data;

}Node;

typedef struct Stack
{
	Node* head;
	int numOfData;
}Stack;
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	pstack->numOfData = 0;
}
int isEmpty(Stack* pstack)
{
	if (pstack->numOfData == 0) return 1;
	else return 0;
}
void Push(Stack* pstack, Data pdata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = pdata;
	newNode->next = NULL;

	if (pstack->numOfData == 0)
	{
		pstack->head = newNode;
	}
	else
	{
		newNode->next = pstack->head;
		pstack->head = newNode;
	}
	(pstack->numOfData)++;
}
Data Pop(Stack* pstack)
{
	if (pstack->numOfData == 0) return -1;

	Node* del = pstack->head;
	Data data = pstack->head->data;

	pstack->head = pstack->head->next;
	(pstack->numOfData)--;
	free(del);
	return data;

}
Data Peek(Stack* pstack)
{
	if (pstack->numOfData == 0) return -1;
	else return pstack->head->data;
}
void SPrint(Stack* pstack)
{

	if (pstack->numOfData == 0) return;
	Node* cur = pstack->head;
	while (cur != NULL)
	{
		printf("%c ", cur->data);
		cur = cur->next;
	}
	puts("");
}
int main()
{
	Stack st;
	StackInit(&st);
	char* cmd = (char*)malloc(sizeof(char) * 6);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s",cmd);
		getchar();

		if (strcmp(cmd, "push")==0)
		{
			int data;
			scanf("%d", &data);
			Push(&st, data);
		}
		else if (strcmp(cmd, "pop")==0)
		{
			printf("%d\n", Pop(&st));
		}
		else if (strcmp(cmd, "size")==0)
		{
			printf("%d\n", st.numOfData);
		}
		else if (strcmp(cmd, "empty")==0)
		{
			printf("%d\n", isEmpty(&st));
		}
		else if (strcmp(cmd, "top")==0)
		{
			printf("%d\n", Peek(&st));
		}
	
	}
	free(cmd);
}