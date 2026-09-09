#include <stdio.h>
 
#define VALOR_TICKET 12.50
#define VALOR_CAFE   4.00
 
int main() {
    int quantidade_tickets, quantidade_cafes;
    float saldo_carteira, total_tickets, total_cafes, total_geral, total_saldo;
    float percentual_usado;
 
    // Solicita ao usuário o saldo da conta, quantidade de tickets e quantidade de cafés
    printf("Digite o saldo da sua conta: ");
    scanf("%f", &saldo_carteira);
 
    printf("Digite a quantidade de tickets comprados: ");
    scanf("%d", &quantidade_tickets);
 
    printf("Digite a quantidade de cafés comprados: ");
    scanf("%d", &quantidade_cafes);
 
    // Calcula os totais
    total_tickets = quantidade_tickets * VALOR_TICKET; // Calcula o total gasto com tickets
    total_cafes = quantidade_cafes * VALOR_CAFE; // Calcula o total gasto com cafés
    total_geral = total_tickets +total_cafes; // Calcula o total geral gasto
    total_saldo = saldo_carteira - total_geral; // Calcula o saldo restante após as compras
 
    // Desafio opcional: percentual do saldo que já foi consumido pelas compras
    percentual_usado = (total_geral / saldo_carteira) * 100;
 
    // Exibe os resultados
    printf("Total tickets: R$ %.2f\n", total_tickets);
    printf("Total cafes: R$ %.2f\n", total_cafes);
    printf("Total geral gasto: R$ %.2f\n", total_geral);
    printf("Saldo restante: R$ %.2f\n", total_saldo);
    printf("Percentual do saldo utilizado: %.2f%%\n", percentual_usado);
 
    // Desafio opcional: avisa se o saldo ficou negativo
    if (total_saldo < 0) {
        printf("Atencao: saldo negativo!\n");
    }
 
    return 0;
}
 