#include <stdio.h>

int main() {

    char c = 'A', *pc = &c;
    int i = 10, *pi = &i;
    double d = 1.5, *pd = &d;

    printf("pc = %p; pc - 1 = %p (%ld byte)(char)\n", pc, pc - 1, sizeof(c));
    printf("pi = %p; pi - 1 = %p (%ld bytes)(int)\n", pi, pi - 1, sizeof(i));
    printf("pd = %p; pd - 1 = %p (%ld bytes)(double)\n", pd, pd - 1, sizeof(d));

    return 0;
}
