#include <stdio.h>

#define ROWS 2
#define COLS 3

int main() {

    int m1[ROWS][COLS] = {
        {10, 9, 5},
        {7, 8, 6}
    };

    int m2[ROWS][COLS] = {
        {3, 7, 9},
        {2, 6, 5}
    };

    int soma[ROWS][COLS];

    for (int linha = 0; linha < ROWS; linha++) {
        for (int coluna = 0; coluna < COLS; coluna++) {
            soma[linha][coluna] = m1[linha][coluna] + m2[linha][coluna];

            printf(
                "m1[%d][%d] (%2d) + m2[%d][%d] (%2d) = soma[%d][%d] (%2d)\n",
                linha, coluna, m1[linha][coluna],
                linha, coluna, m2[linha][coluna],
                linha, coluna, soma[linha][coluna]
            );
        }
    }
    return 0;
}
