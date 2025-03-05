#include <stdio.h>

#define MAX_ROW 3
#define MAX_COL 4

int main() {

    float aluno1[MAX_COL] = {10, 9.5, 5.5, 7.5};
    float aluno2[MAX_COL] = {7, 8, 10, 8.5};
    float aluno3[MAX_COL] = {8.5, 6.5, 8, 10};

    float turma[MAX_ROW][MAX_COL] = {
        {aluno1[0], aluno1[1], aluno1[2], aluno1[3]},
        {aluno2[0], aluno2[1], aluno2[2], aluno2[3]},
        {aluno3[0], aluno3[1], aluno3[2], aluno3[3]}
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
