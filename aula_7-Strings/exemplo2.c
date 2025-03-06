#include <stdio.h>

int main() {

    char c[] = {'A', 'B', 'C'};
    char s[] = {'D', 'E', 'F', '\0'};

    printf("Array de caracteres: %s (%lu bytes)\n", c, sizeof(c));
    printf("String:              %s (%lu bytes)\n", s, sizeof(s));

    return 0;
}
