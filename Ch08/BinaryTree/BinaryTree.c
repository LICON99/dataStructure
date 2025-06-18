#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode *bt)
{
	return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL)
		DestroyTree(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL)
		DestroyTree(main->right);

	main->right = sub;
}

void DestroyTree(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	DestroyTree(bt->left);
	DestroyTree(bt->right);

	printf("del tree data: %d \n", bt->data);
	free(bt);
	
}