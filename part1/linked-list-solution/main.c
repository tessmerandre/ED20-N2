#include<stdio.h>
#include<stdlib.h>
#include "browser.h"

int main() {
  Browser* browser = create();

  int leave = 0;
  int op = 0;

  while (leave != 1) {
    printf("\n0 - sair");
    printf("\n1 - inserir nova pagina");
    printf("\n2 - avançar uma pagina");
    printf("\n3 - voltar uma pagina");
    printf("\n4 - ver paginas");
    printf("\nopcao: ");
    scanf("%i", &op);
    switch (op) {
      case 0: leave = 1; break;
      case 1: insert(browser); break;
      case 2: next(browser); break;
      case 3: back(browser); break;
      case 4: print(browser); break;
    }
  }

  return 0;
}