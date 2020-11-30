#include<stdio.h>
#include<stdlib.h>
#include "browser.h"

Browser* create() {
  Browser* browser = NULL;

  browser = (Browser*) malloc(sizeof(Browser));
  if (browser == NULL) {
    exit(1);
  }

  for (int i = 0; i < MAX_PAGES; i++) {
    browser->pages[i] = -1;
  }

  return browser;
}

void insert(Browser* browser) {
  int value;

  if (current_size == MAX_PAGES) {
    printf("limit of pages reached");
    return;
  }

  if (browser->current_size == 0) {
    browser->current_page = 0;
    value = 1;
  } else {
    value = browser->pages[browser->current_size - 2] + 1;
  }

  browser->current_size = browser->current_size + 1;
  browser->pages[browser->current_size == 0 ? 0 : browser->current_size - 1] = value;
}

void print(Browser* browser) {
  for (int i = 0; i < browser->current_size; i++) {
    if (i == browser->current_page) {
      printf("\n[x] - pagina %i", i);
    } else {
      printf("\n[ ] - pagina %i", i);
    }
  }
}

void back(Browser* browser) {
  browser->current_page = browser->current_page - 1;
}

void next(Browser* browser) {
  browser->current_page = browser->current_page + 1;
}