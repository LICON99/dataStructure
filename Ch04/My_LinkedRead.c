#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

int main()
{
	Node *head = NULL;
	Node *cur = NULL;
	Node *tail = NULL;

	int readData;

	while (1)
	{
		Node *newNode;
		scanf("%d", &readData);
		tail->next = readData;
		tail = readData;
		tail->next = NULL;
	}
}