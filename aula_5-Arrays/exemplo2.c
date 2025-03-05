#include <stdio.h>

#define SIZE 10

int main() {

    int arr[SIZE];
    int elementos = sizeof(arr) / sizeof(arr[0]);

    printf(
        "Tamanho                 : %2lu bytes\n"
        "Tamanho do elemento     : %2lu bytes\n"
        "Elementos               : %2d elementos\n",
        sizeof(arr),
        sizeof(arr[0]),
        elementos);

    return 0;
}
