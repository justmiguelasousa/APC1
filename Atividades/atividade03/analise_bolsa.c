/*
 * Resposta (Operador ternario x if aninhado):
 * O operador ternario foi mais vantajoso no calculo do bonus de pontualidade,
 * pois so ha uma atribuicao simples com duas opcoes (5% ou 0%), e ele deixa
 * isso em uma unica linha, sem blocos extras como no if-else tradicional.
 * O if aninhado foi indispensavel na analise do desconto: primeiro e preciso
 * saber a faixa social e, so dentro dela, comparar a media com o limite
 * daquela faixa (8.5, 9.0 ou 9.5). Uma condicao depende da outra, o que um
 * ternario ou ifs soltos deixariam confuso e dificil de ler.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[100];
    int idade;
    float renda;
    float media;
    char pontual;

    char faixa;
    float descontoBase = 0.0f;
    float bonus;
    float descontoTotal;

    /* ---------- Entrada de dados ---------- */
    printf("Nome completo: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Renda familiar mensal (R$): ");
    scanf("%f", &renda);

    printf("Media academica (0.0 a 10.0): ");
    scanf("%f", &media);

    printf("Pagamento em dia? (S/N): ");
    scanf(" %c", &pontual);

    if (idade < 16 || renda <= 0 || media < 0.0f || media > 10.0f) {
        printf("\nERRO: dados invalidos. Analise encerrada.\n");
        printf("(idade minima 16, renda maior que 0, media entre 0 e 10)\n");
        return 0;
    }

    if (renda <= 2000.0f) {
        faixa = 'A';
    } else if (renda <= 5000.0f) {
        faixa = 'B';
    } else {
        faixa = 'C';
    }

    if (faixa == 'A') {
        if (media >= 8.5f) {
            descontoBase = 50.0f;
        } else {
            descontoBase = 30.0f;
        }
    } else if (faixa == 'B') {
        if (media >= 9.0f) {
            descontoBase = 25.0f;
        } else {
            descontoBase = 10.0f;
        }
    } else {
        if (media >= 9.5f) {
            descontoBase = 10.0f;
        } else {
            descontoBase = 0.0f;
        }
    }

    bonus = (pontual == 'S' || pontual == 's') ? 5.0f : 0.0f;

    descontoTotal = descontoBase + bonus;

    /*Saida*/
    printf("\n========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno         : %s\n", nome);
    printf("Faixa Social  : Faixa %c\n", faixa);
    printf("Media         : %.2f\n", media);
    printf("Desconto Base : %.1f%%\n", descontoBase);
    printf("Bonus Pontual : %.1f%%\n", bonus);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", descontoTotal);
    printf("Status        : %s\n",
           descontoTotal > 0.0f ? "APROVADO PARA BOLSA" : "SEM DESCONTO");
    printf("========================================\n");

    return 0;
}