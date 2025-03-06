#include <stdio.h>

int main() {

    char str1[4];
    char str2[4] = {'D', 'E', 'F', '\0'};
    char str3[] = {'G', 'H', 'I', '\0'};

    str1[0] = 'A';
    str1[1] = 'B';
    str1[2] = 'C';
    str1[3] = '\0';

    printf("str1 -> %s\nstr2 -> %s\nstr3 -> %s\n", str1, str2, str3);

    return 0;
}
