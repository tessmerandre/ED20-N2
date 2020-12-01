#include<stdio.h>
#include<stdlib.h>

#define MAX_PAGES 100

typedef struct browser {
  int pages[MAX_PAGES];
  int current_page;
  int current_size;
} Browser;

Browser* create(void);

void insert(Browser* browser);

void back(Browser* browser);

void next(Browser* browser);

void print(Browser* browser);