#include <stdio.h>
#include <stdlib.h>

#define MILHA 0.6213

int main(int argc, char *argv[]) {

    float ml = atof(argv[1]);
    float km = ml / MILHA;

    printf("%.2f milha(s) = %.2f km\n", ml, km);

    return 0;
}
