#include<stdio.h>
#include<stdlib.h>
#include "browser.h"

Node* create_node(int data, Node* prev) {
  Node* node = NULL;

  node = (Node*) malloc(sizeof(Node));
  if (node == NULL) {
    exit(1);
  }

  node->data = data;
  node->prev = prev;

  return node;
}

Browser* create() {
  Browser* browser = NULL;

  browser = (Browser*) malloc(sizeof(Browser));
  if (browser == NULL) {
    exit(1);
  }

  browser->head = NULL;
  return browser;
}

void insert(Browser * browser) {
  if (browser->head != NULL) {
    Node* temp = browser->head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = create_node(temp->data + 1, temp);
  } else {
    browser->head = create_node(1, NULL);
    browser->head->is_current = 1;
  }
}

void print(Browser * browser) {
  Node* temp = browser->head;
  while (temp != NULL) {
    if (temp->is_current) {
      printf("\n[x] - pagina %i", temp->data);
    } else {
      printf("\n[ ] - pagina %i", temp->data);
    }
    temp = temp->next;
  }
}

void back(Browser * browser) {
  Node* temp = browser->head;
  if (temp == NULL) return;

  int found = 0;
  while (found != 1 && temp != NULL) {
    if (temp->prev != NULL && temp->is_current == 1) {
      temp->is_current = 0;
      temp->prev->is_current = 1;

      found = 1;
    }
    temp = temp->next;
  }
}

void next(Browser * browser) {
  Node* temp = browser->head;
  if (temp == NULL) return;

  int found = 0;
  while (found != 1 && temp != NULL) {
    if (temp->next != NULL && temp->is_current == 1) {
      temp->is_current = 0;
      temp->next->is_current = 1;

      found = 1;
    }
    temp = temp->next;
  }
}