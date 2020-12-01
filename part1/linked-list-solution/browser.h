#include<stdio.h>
#include<stdlib.h>

typedef struct node  {
	int data;
	struct node* prev;
	struct node* next;
  int is_current;
} Node;

typedef struct browser {
  struct node* head;
} Browser;

Browser* create();

void insert(Browser * browser);

void back(Browser * browser);

void next(Browser * browser);

void print(Browser * browser);