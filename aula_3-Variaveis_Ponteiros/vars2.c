#include <stdio.h>

int a = 5;
int c = 45; // A variável local tem prioridade sobre a variável global

int faz_nada() {
    int c = 15;
    return c;
}

int main() {

    int b = 10;  // warning: ‘b’ is used uninitialized [-Wuninitialized]
    int c = 23; // Prioridade para variável local

    //printf("a: %d\nb: %d\n", a, b);

    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}
