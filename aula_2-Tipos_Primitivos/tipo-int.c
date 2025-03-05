/*
Constantes inteiras
*/

#include <stdio.h>
#include <limits.h>

int main() {

    printf("23\t - %lu bytes: %d ... %d\n", sizeof(23), INT_MIN, INT_MAX);
    printf("23u\t - %lu bytes: %u ... %u\n", sizeof(23u), 0, UINT_MAX);
    printf("23l\t - %lu bytes: %ld ... %ld\n", sizeof(23l), LONG_MIN, LONG_MAX);
    printf("23ul\t - %lu bytes: %u ... %lu\n", sizeof(23ul), 0, ULONG_MAX);

    printf("\nLiteral: %u - %lu bytes\n", 922, sizeof(922));
    printf("Literal: %lu - %lu bytes\n", 4294967293, sizeof(4294967293));

    return 0;
}
