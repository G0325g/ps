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
	if (pstack->numOfData == 0) return '-1';

	Data data = pstack->head->data;
	pstack->head = pstack->head->next;
	(pstack->numOfData)--;
	return data;

}
Data Peek(Stack* pstack)
{ 
	if (pstack->numOfData == 0) return '-1';
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
int isVPS(Stack* pstack, char* str)
{
	StackInit(pstack);
	for (int j = 0; j < strlen(str); j++)
	{
	 
		if (str[j] == '(') Push(pstack, str[j]);
		else if (pstack->numOfData > 0 && str[j] == ')') Pop(pstack);
		// 스택에 아무것도없는데 ) 나왔을때
		else if (pstack->numOfData == 0 && str[j] == ')')
			return 0;
		
	}
	// 다끝났는데 스택에 뭐가 남아있을때
	if (pstack->numOfData > 0)
		return 0;

	return 1;
	
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char str[51] = "";
		scanf("%s", str);
		Stack st;
		if (isVPS(&st, str) == 1) printf("YES\n");
		else printf("NO\n");

	}



}