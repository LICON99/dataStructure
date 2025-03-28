#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** Creation and initialization of ArrayList ***/
	List list;
	int data;
	ListInit(&list);

	/*** Store 94 pieces of data ***/
	for (int i = 0; i < 95; i++)
		LInsert(&list, i);

	/*** Print all stored data ***/
	printArr(&list);

	/*** Search for the number 22 and delete all occurrences ***/
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

	/*** Print all stored data after deletion ***/
	printArr(&list);

	/* LAdd start let new data < 0 */

	if (LAdd(&list, 92, -8)) // add new data at the end of the arr
		printArr(&list);

	if (LAdd(&list, 0, -1)) // add new data at the beginning of the arr
		printArr(&list);

	if (LAdd(&list, 5, -11))
		printArr(&list);

	if (LAdd(&list, 89, -77))
		printArr(&list);

	if (LAdd(&list, 7, -19))
		printArr(&list);

	if (LAdd(&list, 123, -99)) // impossible case ( index >= numOfData )
		printArr(&list);

	if (LAdd(&list, -1, -12)) // impossible case ( index < 0 )
		printArr(&list);

	if (LAdd(&list, 50, -15))
		printArr(&list);

	if (LAdd(&list, 87, -17)) // impossible case ( the list has reached its storage limit(100) )
		printArr(&list);
	return 0;
}