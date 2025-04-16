#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _lQueue
{
	Node* front;
	Node* rear;
	int numOfData;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->numOfData = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	(pq->numOfData)++;
}

Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	(pq->numOfData)--;
	return retData;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}

int main()
{
	Queue q;
	QueueInit(&q);

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		Enqueue(&q, i);

	while (1)
	{
		if (q.numOfData == 1)
		{
			printf("%d ", QPeek(&q));
			break;
		}

		printf("%d ",Dequeue(&q));
		int num = Dequeue(&q);
		Enqueue(&q, num);
	}

	

}