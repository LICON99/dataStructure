#ifndef __AB_STACK_H__
#define __AB_STACK_H__ // Include guard to prevent multiple inclusions

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100 // Maximum length of the stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data; // Define the data type to be stored in the stack

// Definition of the array-based stack structure
typedef struct _arrayStack
{
	Data stackArr[STACK_LEN]; // Array to store actual data
	int topIndex;			  // Index of the top element in the stack
} ArrayStack;

typedef ArrayStack Stack; // Define Stack as an alias for ArrayStack

// Function declarations related to the stack
void StackInit(Stack *pstack); // Initialize the stack
int SIsEmpty(Stack *pstack);   // Check if the stack is empty

void SPush(Stack *pstack, Data data); // Push data onto the stack
Data SPop(Stack *pstack);			  // Pop data from the stack
Data SPeek(Stack *pstack);			  // Peek at the top data without popping

int main()
{
	int t;		   // Number of test cases
	char str[100]; // Input string (parentheses string)
	int isNo;	   // Flag to indicate whether the parentheses string is invalid
	Stack stack;   // Declare a stack

	scanf("%d", &t); // Read the number of test cases
	for (int i = 0; i < t; i++)
	{
		isNo = 0;		   // Reset flag for each test case
		StackInit(&stack); // Initialize the stack

		scanf("%s", str); // Read the parentheses string

		// Check each character in the string
		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == '(')
				SPush(&stack, str[j]); // Push '(' onto the stack

			if (str[j] == ')')
			{
				// If the closing parenthesis is found but the stack is empty,
				// or the top is not a matching '('
				if (stack.topIndex < 0 || stack.stackArr[stack.topIndex] != '(')
				{
					isNo = 1; // Mark as an invalid parentheses string
					break;	  // Stop checking
				}
				else if (stack.stackArr[stack.topIndex] == '(')
					SPop(&stack); // If matched, pop the '('
			}
		}

		// If the parentheses string seems valid so far
		if (isNo == 0)
		{
			if (SIsEmpty(&stack))
				printf("YES\n"); // If the stack is empty, it's a valid string
			else
				printf("NO\n"); // If the stack still has items, it's invalid
		}

		if (isNo == 1)
			printf("NO\n"); // If an error occurred during checking
	}
}

// Function to initialize the stack
void StackInit(Stack *pstack)
{
	pstack->topIndex = -1; // Set top to -1 to indicate an empty stack
}

// Function to check if the stack is empty
int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

// Function to push data onto the stack
void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1;					   // Move top up by one
	pstack->stackArr[pstack->topIndex] = data; // Insert data
}

// Function to pop data from the stack
Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!"); // Error if pop is attempted on an empty stack
		exit(-1);
	}

	rIdx = pstack->topIndex; // Save the index to remove
	pstack->topIndex -= 1;	 // Decrease top by one

	return pstack->stackArr[rIdx]; // Return the removed data
}

// Function to peek at the top value of the stack without removing it
Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!"); // Error if peek is attempted on an empty stack
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex]; // Return the current top data
}

#endif // End of include guard