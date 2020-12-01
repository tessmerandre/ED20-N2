#include<stdio.h>
#include<stdlib.h>

typedef struct node  {
	int data;
	struct node* prev;
} Node;

typedef struct queue {
  struct node* head;
} Queue;

Queue* create();

void enqueue(Queue * queue, int data);

int dequeue(Queue * queue);

void print(Queue * queue);