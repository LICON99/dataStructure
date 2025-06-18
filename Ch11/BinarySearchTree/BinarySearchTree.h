#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree2.h"

typedef BTData BSTData; // 이진 탐색 트리에서 사용하는 데이터 타입 정의

// 이진 탐색 트리 초기화 함수
void BSTMakeAndInit(BTreeNode **pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode *bst);

// 이진 탐색 트리에 데이터 삽입 (중복 데이터는 삽입하지 않음)
void BSTInsert(BTreeNode **pRoot, BSTData data);

// 이진 탐색 트리에서 데이터 검색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

#endif