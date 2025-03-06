#include <stdio.h>

/* F = (C * 1.8) + 32 */

int main() {

    int c = 100;
    int f = 0;

    printf("%d°C = %.2f°F\n", c, (c * 1.8) + 32);
    printf("%d°F = %.2f°C\n", f, (f - 32) / 1.8);

    return 0;
}
