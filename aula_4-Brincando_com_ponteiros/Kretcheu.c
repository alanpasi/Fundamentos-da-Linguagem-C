#include <stdio.h>

int main() {

    int i = 123456789;
    unsigned char *c = (unsigned char *) &i;    // Type casting
    printf("\nInteiro %d em hexa: %#010x\n\n", i, i);

    for (int b = 0; b < sizeof(i); b++) {
        printf("Byte %d: %#04x - Endereço: %p\n", b, *(c + b), c + b);
    }

    puts("\nObserve como fica claro o ordenamento 'little endian'!\n");

    return 0;
}
