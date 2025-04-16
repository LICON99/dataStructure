#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE    1
#define FALSE   0

#include <stdio.h>
#include <stdlib.h>

// Define Data type as int
typedef int Data;

// Node structure definition
typedef struct _node
{
    Data data;          // Data stored in the node
    struct _node * next; // Pointer to the next node
} Node;

// Queue structure definition
typedef struct _lQueue
{
    Node * front;  // Pointer to the front of the queue
    Node * rear;   // Pointer to the rear of the queue
} LQueue;

// Define Queue as LQueue type
typedef LQueue Queue;

// Function prototypes
void QueueInit(Queue * pq); // Initialize the queue
int QIsEmpty(Queue * pq);  // Check if the queue is empty

void Enqueue(Queue * pq, Data data); // Add data to the queue
Data Dequeue(Queue * pq);           // Remove and return data from the queue
Data QPeek(Queue * pq);            // Peek at the front of the queue

int main()
{
    int n;
    int rd;
    Queue q;
    
    // Input the number of elements to be enqueued
    scanf("%d", &n);
    // Initialize the queue
    QueueInit(&q);

    // Enqueue numbers from 1 to n into the queue
    for(int i = 1; i <= n; i++)
        Enqueue(&q, i);
    
    // Dequeue and process elements until the queue is empty
    for(int i = 1;; i++)
    {
        // If the queue is empty, break the loop
        if(QIsEmpty(&q))
         break;
        // Dequeue an element
        rd = Dequeue(&q);
    
        // If i is odd, print the dequeued element
        if(i % 2 == 1)
            printf("%d ", rd);
        // If i is even, enqueue the dequeued element back into the queue
        if(i % 2 == 0)
            Enqueue(&q, rd);
    }
    return 0;
}

// Initialize the queue
void QueueInit(Queue * pq)
{
    pq->front = NULL;  // Set the front pointer to NULL
    pq->rear = NULL;   // Set the rear pointer to NULL
}

// Check if the queue is empty
int QIsEmpty(Queue * pq)
{
    // If the front pointer is NULL, the queue is empty
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

// Add a new element to the queue
void Enqueue(Queue * pq, Data data)
{
    // Create a new node
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;  // New node is the last one, so its next pointer is NULL
    newNode->data = data;  // Store the data in the new node

    // If the queue is empty, the new node becomes both the front and rear
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        // If the queue is not empty, link the new node at the end
        pq->rear->next = newNode;
        pq->rear = newNode;  // Update the rear pointer to the new node
    }
}

// Remove and return an element from the queue
Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;

    // If the queue is empty, print an error message and exit
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    // Get the node to be removed (the front of the queue)
    delNode = pq->front;
    retData = delNode->data;  // Store the data to be returned
    pq->front = pq->front->next;  // Move the front pointer to the next node

    free(delNode);  // Free the memory of the removed node
    return retData; // Return the data of the removed node
}

// Peek at the front element of the queue
Data QPeek(Queue * pq)
{
    // If the queue is empty, print an error message and exit
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    // Return the data of the front node without removing it
    return pq->front->data;
}

#endif
