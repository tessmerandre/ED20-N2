#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Queue* create() {
  Queue* queue = NULL;

  queue = (Queue*) malloc(sizeof(Queue));
  if (queue == NULL) {
    exit(1);
  }

	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

Node* create_node(int data) {
  Node* node = NULL;

  node = (Node*) malloc(sizeof(Node));
  if (node == NULL) {
    exit(1);
  }

  node->data = data;

	return node;
}

void enqueue(Queue* queue, int data) {
	Node* node = create_node(data);
  if (queue->tail != NULL) {
    queue->tail->prev = node;
  }
  if (queue->head == NULL) {
    queue->head = node;
  }
  queue->tail = node;
}

int dequeue(Queue* queue) {
  if (queue->head == NULL) return -1;
	Node* head = queue->head;
	queue->head = head->prev;
	return head->data;
}

void print(Queue* queue) {
	int pos = 1;
	Node* node = queue->head;
	while (node != NULL) {
		printf("\n[%i] - cliente rg: %i", pos, node->data);
		pos = pos + 1;
		node = node->prev;
	}
}