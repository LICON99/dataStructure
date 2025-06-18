#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*";
	BTreeNode *eTree = MakeExpTree(exp);

	// 전위 표기식 출력
	printf("전위 표기식 출력: ");
	ShowPrefixTypeExp(eTree);
	printf("\n");

	// 중위 표기식 출력
	printf("중위 표기식 출력: ");
	ShowInfixTypeExp(eTree);
	printf("\n");

	// 후위 표기식 출력
	printf("후위 표기식 출력: ");
	ShowPostfixTypeExp(eTree);
	printf("\n");

	// 수식 트리 계산 결과 출력
	printf("계산 결과: %d \n", EvaluateExpTree(eTree));

	return 0;
}