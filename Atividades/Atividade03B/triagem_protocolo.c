/*
 * Atividade 03B - Triagem de Protocolos (switch)
 *
 * O fall-through foi mais vantajoso no switch de servico e no de expediente:
 * os codigos 1, 2 e 3 (e tambem 4 e 5) compartilham categoria, prazo e taxa,
 * entao escrevo esse bloco uma unica vez e os cases vazios "caem" nele. O
 * mesmo vale para os dias 2 a 5 (Pleno) e para U/u, N/n e B/b. Repetir o
 * bloco deixaria o codigo maior e facil de desatualizar. O switch nao
 * substitui o if-else-if das faixas de renda porque ele so compara igualdade
 * com constantes inteiras ou char; faixas (renda >= X e renda < Y) dependem
 * de comparacoes relacionais, que o switch nao faz.
 */
#include <stdio.h>

int main(void)
{
    int servico, dia, guiche = 0;
    char prioridade;
    const char *nome = "Codigo invalido", *categoria = "-", *prazo = "0", *status = "RECUSADO";
    const char *nome_prio = "Invalida", *nome_dia = "Dia invalido", *expediente = "Dia invalido";
    double taxa_base = 0.0, acrescimo = 0.0;

    printf("Digite servico (1 a 6), prioridade (U/N/B)(urgente, normal ou balcao) e dia (1 a 7): ");
    scanf("%d", &servico);
    scanf(" %c", &prioridade);
    scanf("%d", &dia);

    switch (servico) {
    case 1: /* fall-through */
    case 2: /* fall-through */
    case 3:
        switch (servico) {
        case 1:  nome = "Historico escolar"; break;
        case 2:  nome = "Declaracao de matricula"; break;
        default: nome = "Declaracao de vinculo"; break;
        }
        categoria = "Documento simples"; prazo = "2 dias uteis"; taxa_base = 15.0; status = "ACEITO";
        break;
    case 4: /* fall-through */
    case 5:
        switch (servico) {
        case 4:  nome = "Trancamento"; break;
        default: nome = "Cancelamento"; break;
        }
        categoria = "Interrupcao de vinculo"; prazo = "10 dias uteis"; status = "ACEITO";
        break;
    case 6:
        nome = "Colacao de grau"; categoria = "Ato solene"; prazo = "15 dias uteis";
        taxa_base = 80.0; status = "ACEITO";
        break;
    default:
        break; /* os valores iniciais ja sao os de codigo invalido */
    }

    switch (prioridade) {
    case 'U': /* fall-through */
    case 'u': nome_prio = "Urgente"; guiche = 1; acrescimo = 10.0; break;
    case 'N': /* fall-through */
    case 'n': nome_prio = "Normal"; guiche = 2; break;
    case 'B': /* fall-through */
    case 'b': nome_prio = "Balcao"; guiche = 3; break;
    default:  break;
    }

    switch (dia) {
    case 1:  nome_dia = "Domingo"; break;
    case 2:  nome_dia = "Segunda-feira"; break;
    case 3:  nome_dia = "Terca-feira"; break;
    case 4:  nome_dia = "Quarta-feira"; break;
    case 5:  nome_dia = "Quinta-feira"; break;
    case 6:  nome_dia = "Sexta-feira"; break;
    case 7:  nome_dia = "Sabado"; break;
    default: break;
    }

    switch (dia) {
    case 2: /* fall-through */
    case 3: /* fall-through */
    case 4: /* fall-through */
    case 5:  expediente = "Pleno"; break;
    case 6:  expediente = "Reduzido"; break;
    case 1: /* fall-through */
    case 7:  expediente = "Fechado"; break;
    default: break;
    }

    printf("\n========================================\n"
           " TRIAGEM DE PROTOCOLO ACADEMICO\n"
           "========================================\n"
           "Servico           : %s\nCategoria         : %s\nPrazo             : %s\n"
           "Taxa base         : R$ %.2f\nPrioridade        : %s\nGuiche            : %d\n"
           "Acrescimo         : R$ %.2f\nDia               : %s\nExpediente        : %s\n"
           "----------------------------------------\n"
           "Taxa final        : R$ %.2f\nStatus do servico : %s\n"
           "========================================\n",
           nome, categoria, prazo, taxa_base, nome_prio, guiche,
           acrescimo, nome_dia, expediente, taxa_base + acrescimo, status);
    return 0;
}
