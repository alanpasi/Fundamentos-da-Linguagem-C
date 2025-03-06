#include <stdio.h>

int main() {

    char fruta[] = "banana";
    char *bicho = "zebra";
    char cor[5];
    char *carro;

    cor[0] = 'r';
    cor[1] = 'o';
    cor[2] = 'x';
    cor[3] = 'o';
    cor[4] = '\0';

    carro = "fusca";

    printf(
        "fruta -> %s\nbicho -> %s\ncor -> %s\ncarro -> %s\n",
        fruta, bicho, cor, carro
    );

    return 0;
}
