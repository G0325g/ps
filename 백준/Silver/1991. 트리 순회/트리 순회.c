#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef char BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(BTData data);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(BTData data);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

void DeleteTree(BTreeNode* bt);
void ShowIntData(int data);
void ShowCharData(char data);
void DestroyTree(BTreeNode* bt);

int main(void)
{
	/*BTreeNode* bt1 = MakeBTreeNode(1);
	BTreeNode* bt2 = MakeBTreeNode(2);
	BTreeNode* bt3 = MakeBTreeNode(3);
	BTreeNode* bt4 = MakeBTreeNode(4);
	BTreeNode* bt5 = MakeBTreeNode(5);
	BTreeNode* bt6 = MakeBTreeNode(6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	PreorderTraverse(bt1, ShowIntData);   printf("\n");
	InorderTraverse(bt1, ShowIntData);    printf("\n");
	PostorderTraverse(bt1, ShowIntData);  printf("\n");

	DeleteTree(bt1);*/

	//백준 1991
	BTreeNode *nodes[26];
	for (int i = 0; i < 26; i++)
		nodes[i] = MakeBTreeNode('A' + i);
	
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		BTData node, left, right;
		scanf("%c %c %c", &node, &left, &right);
		getchar();
		if (left != '.')
			MakeLeftSubTree(nodes[node - 'A'], nodes[left - 'A']);
		if (right != '.')
			MakeRightSubTree(nodes[node - 'A'], nodes[right - 'A']);
	}
	PreorderTraverse(nodes[0], ShowCharData); printf("\n");
	InorderTraverse(nodes[0], ShowCharData); printf("\n");
	PostorderTraverse(nodes[0], ShowCharData); printf("\n");
	return 0;
}

void ShowIntData(int data) {
	printf("%d ", data);
}
void ShowCharData(char data) {
	printf("%c", data);
}

BTreeNode* MakeBTreeNode(BTData data) {
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	nd->data = data;
	return nd;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL)
		DestroyTree(main->left);  // 기존 서브트리 제거

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)
		DestroyTree(main->right);  // 기존 서브트리 제거
	
	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL) return;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTreeNode* bt) {
	if (bt == NULL) return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data: %d \n", bt->data);
	free(bt);
}
void DestroyTree(BTreeNode* bt) {
	if (bt == NULL) return;

	DestroyTree(bt->left);
	DestroyTree(bt->right);
	free(bt);
}

