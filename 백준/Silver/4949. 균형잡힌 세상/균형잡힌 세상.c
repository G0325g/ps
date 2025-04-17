#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char Data;

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
	while (1)
	{
		StackInit(&st);
		int fnd = 0;
		char* str = (char*)malloc(sizeof(char) * 101);
		scanf("%[^\n]", str);
		getchar();
		if (strcmp(str, ".") == 0) return 0;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '(')
			{
				Push(&st, '(');
			}
			else if (str[i] == ')')
			{
				if (Peek(&st) == '(') Pop(&st);
				else
				{
					fnd = 1;
					break;
				}
			}
			else if (str[i] == '[')
			{
				Push(&st, '[');
			}
			else if (str[i] == ']')
			{
				if (Peek(&st) == '[') Pop(&st);
				else
				{
					fnd = 1;
					break;
				}
			}
		}

		if (st.numOfData > 0) fnd = 1;

		if (fnd == 1) printf("no\n");
		else printf("yes\n");

		free(str);
	}
}