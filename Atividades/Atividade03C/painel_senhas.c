/*
 *
 * Por que o menu precisa de do-while, e nao de while? Porque o menu deve
 * aparecer pelo menos uma vez, antes de ler a opcao; o do-while so testa
 * a condicao no fim do corpo.
 * No lote (opcao 1), o continue evita contar uma senha invalida: se a
 * senha e negativa, soma em ignoradas, le a proxima e salta o resto da volta,
 * sem mexer em atendidas e pares.
 * Na busca prioritaria, sem o break o for(;;) nunca terminaria e o
 * programa ficaria preso pedindo senhas, sem voltar ao menu.
 */
#include <stdio.h>

int main(void)
{
    int opcao, senha, atendidas, ignoradas, pares;
    int inicio, fim, passo, qtd;
    int g, s, lidas;

    do {
        printf("===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            atendidas = 0;
            ignoradas = 0;
            pares = 0;
            printf("Senha: ");
            scanf("%d", &senha);
            while (senha != 0) {
                if (senha < 0) {
                    ignoradas++;
                    printf("Senha: ");
                    scanf("%d", &senha);
                    continue;
                }
                atendidas++;
                if (senha % 2 == 0) {
                    pares++;
                }
                printf("Senha: ");
                scanf("%d", &senha);
            }
            printf("Atendidas : %d\n", atendidas);
            printf("Ignoradas : %d\n", ignoradas);
            printf("Pares : %d\n", pares);
        } else if (opcao == 2) {
            printf("Inicio: ");
            scanf("%d", &inicio);
            printf("Fim: ");
            scanf("%d", &fim);
            printf("Passo: ");
            scanf("%d", &passo);
            if (passo == 0) {
                printf("Passo invalido\n");
            } else {
                qtd = 0;
                for (int i = inicio; (passo > 0 && i <= fim) || (passo < 0 && i >= fim); i += passo) {
                    if (qtd == 0) {
                        printf("Chamadas:");
                    }
                    printf(" %d", i);
                    qtd++;
                }
                if (qtd == 0) {
                    printf("Nenhuma chamada\n");
                } else {
                    printf("\n");
                }
            }
        } else if (opcao == 3) {
            printf("Guiches (1 a 4): ");
            scanf("%d", &g);
            printf("Senhas por guiche (1 a 5): ");
            scanf("%d", &s);
            if (g < 1 || g > 4 || s < 1 || s > 5) {
                printf("Grade invalida\n");
            } else {
                for (int i = 1; i <= g; i++) {
                    printf("Guiche %d:", i);
                    for (int j = 1; j <= s; j++) {
                        printf(" %d", j);
                    }
                    printf("\n");
                }
            }
        } else if (opcao == 4) {
            lidas = 0;
            for (;;) {
                printf("Senha: ");
                scanf("%d", &senha);
                if (senha == 0) {
                    printf("Nao encontrada\n");
                    printf("Lidas : %d\n", lidas);
                    break;
                }
                if (senha > 0 && senha % 10 == 0) {
                    printf("Prioritaria : %d\n", senha);
                    printf("Lidas antes : %d\n", lidas);
                    break;
                }
                lidas++;
            }
        } else if (opcao != 0) {
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);

    printf("Painel encerrado.\n");
    return 0;
}