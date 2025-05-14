#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

#define TRUE	1
#define FALSE	0

/*** Heap의 정의 ****/
#define HEAP_LEN	100001

typedef int HData;

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);


int DataPriorityComp(int d1, int d2)
{
	if (abs(d1) < abs(d2)) return 1;
	else if (abs(d1) > abs(d2)) return -1;
	else if (abs(d1) == abs(d2))
	{
		if (d1 < d2) return 1;
		else if (d1 > d2) return -1;
		else return 0;
	}
}
Heap heap;
int main(void)
{
	 
	HeapInit(&heap, DataPriorityComp);
	int n;
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
	 
		if (x != 0)
			HInsert(&heap, x);
		else if (HIsEmpty(&heap))
			printf("0\n");
		else
			printf("%d\n", HDelete(&heap));
	}
	return 0;
}

void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);

	else
	{
		//	if(ph->heapArr[GetLChildIDX(idx)].pr 
		//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],
			ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		//	if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
		{
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];
	ph->numOfData -= 1;
	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		//	if(lastElem.pr <= ph->heapArr[childIdx].pr)
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;

	return retData;
}