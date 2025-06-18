#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode *bstRoot;
	BTreeNode *sNode; // 검색 결과 노드

	// 트리 초기화
	BSTMakeAndInit(&bstRoot);

	// 트리에 노드 삽입
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	// BSTInsert(&bstRoot, 4);  // 주석 처리된 노드
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
	// BSTInsert(&bstRoot, 7);  // 주석 처리된 노드

	// 값 1 검색
	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("검색 실패\n");
	else
		printf("검색 성공: 키 값 = %d\n", BSTGetNodeData(sNode));

	// 값 4 검색
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("검색 실패\n");
	else
		printf("검색 성공: 키 값 = %d\n", BSTGetNodeData(sNode));

	// 값 6 검색
	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("검색 실패\n");
	else
		printf("검색 성공: 키 값 = %d\n", BSTGetNodeData(sNode));

	// 값 7 검색
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("검색 실패\n");
	else
		printf("검색 성공: 키 값 = %d\n", BSTGetNodeData(sNode));

	return 0;
}