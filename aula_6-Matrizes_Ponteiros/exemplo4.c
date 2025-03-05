#include <stdio.h>

#define MAX 5

int main() {

    int arr[MAX] = {15, 25, 43, 64, 51};
    int *pa = arr;

    for (int i = 0; i < MAX; i++) {
        printf(
            "pa + %d = %p -> *(pa + %d) = %d\n",
            i, pa + i, i, *(pa + i)
        );
    }
    return 0;
}
