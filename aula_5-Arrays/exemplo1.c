#include <stdio.h>

#define MAX 4   // Constante simbólica

int main() {

    float valor[MAX] = {10.5, 9.8, 15.7, 13.25};

   for (int i = 0; i < MAX; i++) {
       printf("Valor %d: R$ %5.2f - Indice %d\n", i + 1, valor[i], i);
   }

   int elementos = sizeof(valor) / sizeof(valor[0]);
   printf("Quantidade de elementos em valor[]: %d\n", elementos);

   valor[2] = 17.3;

   printf("\nNovo valor[2]: R$ %.2f\n", valor[2]);

   return 0;
}
