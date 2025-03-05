#include <stdio.h>

int main() {

    int valor = 10;
    int *pvalor = &valor;

    printf("%d\n", valor);
    printf("%d\n", *pvalor);
    printf("%p\n", &valor);
    printf("%p\n", pvalor);

    return 0;
}
