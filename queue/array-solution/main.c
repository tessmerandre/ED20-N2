#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main() {
	Queue* queue = create();

  int leave = 0;
  int op = 0;

  while (leave != 1) {
    printf("\n0 - sair");
    printf("\n1 - entrar na fila");
    printf("\n2 - atender cliente");
    printf("\n3 - ver fila");
    printf("\nopcao: ");
    scanf("%i", &op);
    switch (op) {
      case 0: leave = 1; break;
      case 1: {
        int rg;
        printf("Qual seu RG? ");
        scanf("%i", &rg);
        enqueue(queue, rg);
        break;
      }
      case 2: {
        int data = dequeue(queue);
        if (data != -1) {
          printf("Você está atendendo o cliente %i", data);
        } else {
          printf("Não há ninguém na fila");
        }
        break;
      }
      case 3: print(queue); break;
    }
  }

  return 0;
}
