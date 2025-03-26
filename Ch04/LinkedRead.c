#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

int main(void)
{
	Node *head = NULL; // NULL ������ �ʱ�ȭ
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;

	/**** �����͸� �Է� �޴� ���� ****/
	while (1)
	{
		printf("input integer : ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data); // ù ��° ������ ���
		while (cur->next != NULL) // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}

	printf("\n\n");

	/**** �޸��� �������� ****/
	if (head == NULL)
	{
		return 0; // ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node *delNode = head;
		Node *delNextNode = head->next;

		printf("%d 을 삭제. \n", head->data);
		free(delNode); // ù ��° ����� ����

		while (delNextNode != NULL) // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 을 삭제. \n", delNode->data);
			free(delNode); // �� ��° ������ ��� ����
		}
	}

	return 0;
}