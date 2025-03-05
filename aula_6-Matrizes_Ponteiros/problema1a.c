#include <stdio.h>

#define MAX_ROW 3
#define MAX_COL 4

int main() {

    float aluno1[MAX_COL] = {10, 9.5, 5.5, 7.5};
    float aluno2[MAX_COL] = {7, 8, 10, 8.5};
    float aluno3[MAX_COL] = {8.5, 6.5, 8, 10};

    float turma[MAX_ROW][MAX_COL] = {
        aluno1,
        aluno2,
        aluno3
    };

    puts("--------------------------------");
    puts("Alunos : Nota1 Nota2 Nota3 Nota4");
    puts("--------------------------------");

    for (int linha = 0; linha < MAX_ROW; linha++) {
        printf("Aluno%d : ", linha + 1);

        for (int coluna = 0; coluna < MAX_COL; coluna++) {
            printf("%5.2f ", turma[linha][coluna]);
        }
        puts("");

    }
    return 0;
}
