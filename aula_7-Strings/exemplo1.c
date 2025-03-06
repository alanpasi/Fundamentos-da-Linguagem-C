#include <stdio.h>

int main() {

    char c = 'A';   /* Variável do tipo 'char' */
    char *pc = &c;  /* Ponteiro do tipo base 'char' */

    printf("Valor em 'pc' : %p\n", pc);
    printf("Valor em '*pc' : %c\n", *pc);

    return 0;
}
