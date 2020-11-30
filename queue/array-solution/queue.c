#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Queue* create() {
  Queue* queue = NULL;

  queue = (Queue*) malloc(sizeof(Queue));
  if (queue == NULL) {
    exit(1);
  }

	for (int i = 0; i < MAX_ITEMS; i++) {
		queue->items[i] = -1;
	}

	queue->head_index = 0;
	queue->tail_index = 0;

	return queue;
}

void enqueue(Queue* queue, int data) {
	if (queue->tail_index == MAX_ITEMS - 1) {
		printf("limit of items reached");
		return;
	}

	queue->items[queue->tail_index] = data;
	queue->tail_index = queue->tail_index + 1;
}

int dequeue(Queue* queue) {
	if (queue->head_index == MAX_ITEMS - 1) {
		printf("no more items");
		return -1;
	}

	int data = queue->items[queue->head_index];

	queue->items[queue->head_index] = -1; // removing item
	queue->head_index = queue->head_index + 1;

  return data;
}

void print(Queue* queue) {
	int pos = 1;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (queue->items[i] != -1) {
			printf("\n[%i] - cliente rg: %i", pos, queue->items[i]);
			pos = pos + 1;
		}
	}
}