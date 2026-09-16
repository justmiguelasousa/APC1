#include <stdio.h>
#include <string.h>

int main(void) {
    char nome_cliente[100];
    char nome_produto[100];
    int codigo_produto;
    int quantidade;
    float preco_unitario;
    char categoria;
    float total;

    /* Nome do cliente (com espacos) */
    printf("Nome completo do cliente: ");
    fgets(nome_cliente, 100, stdin);
    nome_cliente[strcspn(nome_cliente, "\n")] = '\0';

    /* Codigo do produto */
    printf("Codigo do produto: ");
    scanf("%d", &codigo_produto);
    getchar(); /* consome o '\n' deixado pelo scanf */

    /* Nome do produto (com espacos) */
    printf("Nome do produto: ");
    fgets(nome_produto, 100, stdin);
    nome_produto[strcspn(nome_produto, "\n")] = '\0';

    /* Quantidade */
    printf("Quantidade: ");
    scanf("%d", &quantidade);

    /* Preco unitario */
    printf("Preco unitario: ");
    scanf("%f", &preco_unitario);

    /* Categoria (A, B ou C) */
    printf("Categoria (A, B ou C): ");
    scanf(" %c", &categoria); /* espaco antes de %c ignora \n pendente */

    total = quantidade * preco_unitario;

    printf("\n========================================\n");
    printf("           RECIBO DE COMPRA\n");
    printf("========================================\n");
    printf("Cliente   : %s\n", nome_cliente);
    printf("Produto   : %s\n", nome_produto);
    printf("Codigo    : %d\n", codigo_produto);
    printf("Categoria : %c\n", categoria);
    printf("Qtd       : %d\n", quantidade);
    printf("Unitario  : R$ %.2f\n", preco_unitario);
    printf("Total     : R$ %.2f\n", total);
    printf("========================================\n");

    return 0;
}