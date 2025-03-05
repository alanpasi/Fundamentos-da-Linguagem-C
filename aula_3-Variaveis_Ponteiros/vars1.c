#include <stdio.h>

int a;

int main() {

    int b;  // warning: ‘b’ is used uninitialized [-Wuninitialized]

    printf("a: %d\nb: %d\n", a, b);

    return 0;
}
