#include <stdio.h>

int main() {

    char troca[] = "abcdefghij";
    char fruta[] = "banana";

    int max, i;

    max = sizeof(fruta);

    printf("Número de caracteres em 'fruta': %d\n\n", max);

    printf("Antes era: %s\n", fruta);

    for (i = 0; i < max; i++) {
        printf("Caractere %d -> '%c'", i, fruta[i]);

        if (fruta[i] != '\0')
            fruta[i] = troca[i];

        printf(" -> '%c'\n", fruta[i]);
    }
    printf("\nAgora é: %s\n\n", fruta);

    return 0;
}
