#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData(int data);

int main(void)
{
	BTreeNode *bt1 = MakeBTreeNode();
	BTreeNode *bt2 = MakeBTreeNode();
	BTreeNode *bt3 = MakeBTreeNode();
	BTreeNode *bt4 = MakeBTreeNode();
	BTreeNode *bt5 = MakeBTreeNode();
	BTreeNode *bt6 = MakeBTreeNode();
	BTreeNode *bt7 = MakeBTreeNode();
	BTreeNode *bt8 = MakeBTreeNode();
	BTreeNode *bt9 = MakeBTreeNode();
	BTreeNode *bt10 = MakeBTreeNode();
	BTreeNode *bt20 = MakeBTreeNode();
	BTreeNode *bt30 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);
	SetData(bt8, 8);
	SetData(bt9, 9);
	SetData(bt10, 10);
	SetData(bt20, 20);
	SetData(bt30, 30);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);
	MakeLeftSubTree(bt4, bt8);
	MakeRightSubTree(bt4, bt9);

	// new subTree
	MakeLeftSubTree(bt10, bt20);
	MakeRightSubTree(bt10, bt30);

	printf("there are 2 trees\n");
	printf("tree 1 : ");
	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	printf("tree 2 : ");
	PreorderTraverse(bt10, ShowIntData);
	printf("\n\n");
	printf("Insert tree 2 as the left subtree of node 2 in tree 1 : \n");
	MakeLeftSubTree(bt2, bt10);
	// check new tree
	PreorderTraverse(bt1, ShowIntData);
	printf("\n\n");

	printf("Subsequently insert tree 2 as the right subtree of node 1 in this tree : \n");
	MakeRightSubTree(bt1, bt10);
	// check new tree
	PreorderTraverse(bt1, ShowIntData);
	printf("\n");

	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}
