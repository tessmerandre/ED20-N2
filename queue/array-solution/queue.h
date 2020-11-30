#include<stdio.h>
#include<stdlib.h>

#define MAX_ITEMS 100

typedef struct queue {
	int head_index;
	int tail_index;
	int items[MAX_ITEMS];
} Queue;

Queue* create();

void enqueue(Queue* queue, int data);

int dequeue(Queue* queue);

void print(Queue* queue);