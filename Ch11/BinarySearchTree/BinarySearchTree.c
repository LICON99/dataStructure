#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

// 이진 탐색 트리 초기화 함수
void BSTMakeAndInit(BTreeNode **pRoot)
{
	*pRoot = NULL; // 트리의 루트를 NULL로 초기화
}

// 노드에서 데이터 가져오기
BSTData BSTGetNodeData(BTreeNode *bst)
{
	return GetData(bst); // BinaryTree2.h에 정의된 함수
}

// 이진 탐색 트리에 노드 삽입
void BSTInsert(BTreeNode **pRoot, BSTData data)
{
	BTreeNode *pNode = NULL;   // 부모 노드 (Parent)
	BTreeNode *cNode = *pRoot; // 현재 노드 (Current)
	BTreeNode *nNode = NULL;   // 새로 삽입할 노드 (New)

	// 삽입 위치를 찾기 위한 반복
	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return; // 중복된 데이터는 삽입하지 않음

		pNode = cNode;

		if (data < GetData(cNode))
			cNode = GetLeftSubTree(cNode); // 왼쪽으로 이동
		else
			cNode = GetRightSubTree(cNode); // 오른쪽으로 이동
	}

	// 새 노드 생성 및 데이터 설정
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// 루트가 아닌 경우: 부모 노드의 왼쪽 또는 오른쪽에 연결
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
	{
		// 루트가 NULL이면 새 노드가 루트가 됨
		*pRoot = nNode;
	}
}

// 이진 탐색 트리에서 데이터 검색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
	BTreeNode *cNode = bst; // 현재 노드
	BSTData cd;				// 현재 노드의 데이터

	// 탐색 반복
	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode; // 데이터를 찾은 경우
		else if (target < cd)
			cNode = GetLeftSubTree(cNode); // 왼쪽 서브트리로 이동
		else
			cNode = GetRightSubTree(cNode); // 오른쪽 서브트리로 이동
	}

	return NULL; // 찾지 못한 경우
}