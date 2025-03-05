#include <stdio.h>

#define MAX 5

int main() {

    int arr[MAX] = {1, 2, 3, 4, 5};
    int *pa = arr;

    for (int i = 0; i < MAX; i++) {
        printf(
            "Valor em ar[%d] = %d - "
            "Endereço de ar[%d] = %p\n",
            i, *pa, i, pa
        );
        pa++;
    }
    return 0;
}
