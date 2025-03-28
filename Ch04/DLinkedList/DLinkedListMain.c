#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	/* insert data from 100 to 1 */
	for (int i = 100; i > 0; i--)
		LInsert(&list, i);

	/* print all data of the list */
	printList(&list);

	/* delete nodes if the data of the node is 22 */
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}
	/*print all node after delete*/
	printList(&list);

	/* let data of the new node < 0 */
	if (LAdd(&list, 98, -99)) // add new node at the end of the list
		printList(&list);	  // print all nodes

	if (LAdd(&list, 0, -99)) // add new node at the beginning of the list
		printList(&list);

	if (LAdd(&list, 40, -99))
		printList(&list);

	if (LAdd(&list, -1, -99)) // impossible case ( index < 0 )
		printList(&list);

	if (LAdd(&list, 200, -99)) // impossible case ( index >= numOfData)
		printList(&list);

	return 0;
}