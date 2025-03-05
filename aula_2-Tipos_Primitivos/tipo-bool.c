/*
Tipo booleano...
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    bool a = 123;
    bool b = 0;

    printf("Tamanho do tipo 'bool': %lu bytes\n\n", sizeof(bool));

    printf("O valor de 'a' é: %d (%lu bytes)\n", a, sizeof(a));
    printf("O valor de 'b' é: %d (%lu bytes)\n\n", b, sizeof(b));

    printf("Tamanho de 'true' : %lu bytes\n", sizeof(true));
    printf("Tamanho de 'false': %lu bytes\n\n", sizeof(false));

    return 0;
}
