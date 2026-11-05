/*
 * Resposta teórica:
 * Em char nome[50] o último espaço é reservado para o caractere '\0',
 * que marca o fim da string em C. Por isso sobram 49 posições para
 * caracteres úteis. Em int M[3][4], o primeiro índice representa a linha
 * (0 a 2) e o segundo representa a coluna (0 a 3). Na memória, C guarda a
 * matriz de forma contígua, linha por linha (row-major): M[0][0], M[0][1],
 * M[0][2], M[0][3], depois M[1][0], M[1][1], e assim por diante.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int op, i, j;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma\n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        while (getchar() != '\n');  /* limpa o buffer */

        if (op == 1) {
            char alunos[5][50];
            for (i = 0; i < 5; i++) {
                printf("Nome do aluno %d: ", i + 1);
                fgets(alunos[i], sizeof(alunos[i]), stdin);
                alunos[i][strcspn(alunos[i], "\n")] = '\0';
            }
            for (i = 0; i < 5; i++) {
                printf("%d - %s\n", i + 1, alunos[i]);
            }
        } else if (op == 2) {
            float notas_finais[5], soma = 0, media;
            int acima = 0;
            for (i = 0; i < 5; i++) {
                printf("Nota %d: ", i + 1);
                scanf("%f", &notas_finais[i]);
            }
            for (i = 0; i < 5; i++) {
                soma += notas_finais[i];
            }
            media = soma / 5;
            for (i = 0; i < 5; i++) {
                if (notas_finais[i] >= media) {
                    acima++;
                }
            }
            printf("Media da turma: %.2f\n", media);
            printf("Alunos com nota >= media: %d\n", acima);
        } else if (op == 3) {
            float boletim[3][4], soma;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 4; j++) {
                    printf("Aluno %d, bimestre %d: ", i + 1, j + 1);
                    scanf("%f", &boletim[i][j]);
                }
            }
            printf("\n  B1     B2     B3     B4    Media\n");
            for (i = 0; i < 3; i++) {
                soma = 0;
                for (j = 0; j < 4; j++) {
                    printf("%5.1f  ", boletim[i][j]);
                    soma += boletim[i][j];
                }
                printf("| %5.2f\n", soma / 4);
            }
        } else if (op == 4) {
            float notas[5], maior;
            int pos = 0;
            for (i = 0; i < 5; i++) {
                printf("Nota %d: ", i + 1);
                scanf("%f", &notas[i]);
            }
            maior = notas[0];
            for (i = 1; i < 5; i++) {
                if (notas[i] > maior) {
                    maior = notas[i];
                    pos = i;
                }
            }
            printf("Maior nota: %.2f (indice %d)\n", maior, pos);
        } else if (op != 0) {
            printf("Opcao invalida!\n");
        }
    } while (op != 0);

    printf("Programa encerrado.\n");
    return 0;
}