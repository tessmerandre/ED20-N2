#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Node* create_node(int data) {
  Node* node = NULL;

  node = (Node*) malloc(sizeof(Node));
  if (node == NULL) {
    exit(1);
  }

  node->data = data;
  node->prev = NULL;

  return node;
}

Queue* create() {
  Queue* queue = NULL;

  queue = (Queue*) malloc(sizeof(Queue));
  if (queue == NULL) {
    exit(1);
  }

  queue->head = NULL;
  return queue;
}

void enqueue(Queue * queue, int data) {
  if (queue->head != NULL) { // first time the head will be null
    Node* tail = queue->head;
    while (tail->prev != NULL) { // getting the tail
      tail = tail->prev;
    }
    tail->prev = create_node(data);
  } else {
    queue->head = create_node(data);
  }
}

int dequeue(Queue * queue) {
  if (queue->head == NULL) return -1; // returning -1 if theres no data in the queue;
  int data = queue->head->data;
  queue->head = queue->head->prev; // removing the 1st element
  return data;
}

void print(Queue * queue) {
  int pos = 0;

  Node* temp = queue->head;
  while (temp != NULL) {
    printf("\n[%i] - cliente rg: %i", pos, temp->data);
    temp = temp->prev;
    pos = pos + 1;
  }
}