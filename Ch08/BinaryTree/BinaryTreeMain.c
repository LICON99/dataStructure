#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();
	BTreeNode * bt7 = MakeBTreeNode();
	BTreeNode * bt8 = MakeBTreeNode();
	BTreeNode * bt9 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);
	SetData(bt8, 8);
	SetData(bt9, 9);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2,bt5);
	MakeLeftSubTree(bt3,bt6);
	MakeRightSubTree(bt3,bt7);
	MakeLeftSubTree(bt4,bt8);
	MakeRightSubTree(bt4,bt9);

	printf("%d \n",
		GetData(GetLeftSubTree(bt1)));
	printf("%d \n",
		GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	return 0;
}