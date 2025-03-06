#include <stdio.h>

int main() {

    char fruta[] = "banana";
    char *carro = "fusca";

    int max, i;

    max = sizeof(fruta);
    printf("Número de caracteres em 'fruta': %d\n", max);

    for (i = 0; i < max; i++) {
        printf("Caractere %d -> '%c'\n", i, fruta[i]);
    }

    /* Solução 1 */
    max = sizeof("fusca");
    printf("\nSolução 1\nNúmero de caracteres em 'carro': %d\n", max);
    for (i = 0; i < max; i++) {
        printf("Caractere %d -> '%c'\n", i, *(carro + i));
    }

    /* Solução 2 */
    max = 1;
    while (*carro != '\0') {
        max++;
        carro++;
    }
    carro = carro - (max - 1);
    printf("\nSolução 2\nNúmero de caracteres em 'carro': %d\n", max);
    for (i = 0; i < max; i++) {
        printf("Caractere %d -> '%c'\n", i, *(carro + i));
    }

    return 0;
}
